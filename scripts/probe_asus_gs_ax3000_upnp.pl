#!/usr/bin/perl
use strict;
use warnings;
use IO::Socket::INET;

sub exchange {
    my ($payload) = @_;
    my $sock = IO::Socket::INET->new(
        PeerAddr => '127.0.0.1', PeerPort => 15000, Proto => 'tcp', Timeout => 3,
    ) or return '';
    $sock->autoflush(1);
    print {$sock} $payload;
    shutdown($sock, 1);
    my $response = '';
    while (length($response) < 65536) {
        my $block = '';
        my $count = sysread($sock, $block, 8192);
        last if !defined($count) || $count == 0;
        $response .= $block;
    }
    close($sock);
    return $response;
}

sub control {
    return exchange(
        "GET /rootDesc.xml HTTP/1.1\r\nHost: 127.0.0.1\r\n" .
        "Connection: close\r\n\r\n"
    ) =~ /^HTTP\/1\.[01] 200/;
}

sub subscribe {
    my ($callback, $extra) = @_;
    $extra //= '';
    return
        "SUBSCRIBE /evt/IPConn HTTP/1.1\r\nHost: 127.0.0.1\r\n" .
        "Callback: $callback\r\nNT: upnp:event\r\n" .
        "Timeout: Second-30\r\n$extra" .
        "Connection: close\r\n\r\n";
}

sub soap {
    my ($action) = @_;
    my $body = '<s:Envelope><s:Body/></s:Envelope>';
    return
        "POST /ctl/IPConn HTTP/1.1\r\nHost: 127.0.0.1\r\n" .
        "SOAPAction: $action\r\nContent-Type: text/xml\r\n" .
        "Content-Length: " . length($body) . "\r\n" .
        "Connection: close\r\n\r\n$body";
}

sub add_mapping {
    my ($client) = @_;
    my $body =
        '<s:Envelope xmlns:s="http://schemas.xmlsoap.org/soap/envelope/">' .
        '<s:Body><u:AddPortMapping xmlns:u="urn:schemas-upnp-org:service:WANIPConnection:1">' .
        '<NewRemoteHost></NewRemoteHost><NewExternalPort>40080</NewExternalPort>' .
        '<NewProtocol>TCP</NewProtocol><NewInternalPort>80</NewInternalPort>' .
        "<NewInternalClient>$client</NewInternalClient><NewEnabled>1</NewEnabled>" .
        '<NewPortMappingDescription>FRIDAY_SELF_MAP</NewPortMappingDescription>' .
        '<NewLeaseDuration>60</NewLeaseDuration></u:AddPortMapping></s:Body></s:Envelope>';
    return
        "POST /ctl/IPConn HTTP/1.1\r\nHost: 127.0.0.1\r\n" .
        "SOAPAction: \"urn:schemas-upnp-org:service:WANIPConnection:1#AddPortMapping\"\r\n" .
        "Content-Type: text/xml\r\nContent-Length: " . length($body) . "\r\n" .
        "Connection: close\r\n\r\n$body";
}

my @cases = (
    ['gena-empty', subscribe('')],
    ['gena-no-brackets', subscribe('http://127.0.0.1:9/')],
    ['gena-unclosed', subscribe('<http://127.0.0.1:9/')],
    ['gena-extra-close', subscribe('<http://127.0.0.1:9/>>')],
    ['gena-refused', subscribe('<http://127.0.0.1:9/>')],
    ['gena-rax30-shape', subscribe('<http://127.0.0.1/FRIDAY_RAX30_PROBE_7b6f2a' . ('A' x 32) . '>')],
    ['gena-duplicate', subscribe('<http://127.0.0.1:9/>', "Callback: <http://127.0.0.1:10/>\r\n")],
    ['gena-timeout-negative', subscribe('<http://127.0.0.1:9/>', "Timeout: Second--1\r\n")],
    ['gena-nt-long', subscribe('<http://127.0.0.1:9/>', 'NT: ' . ('A' x 4096) . "\r\n")],
    ['gena-callback-256', subscribe('<http://127.0.0.1/' . ('A' x 256) . '>')],
    ['gena-callback-1024', subscribe('<http://127.0.0.1/' . ('A' x 1024) . '>')],
    ['gena-callback-4096', subscribe('<http://127.0.0.1/' . ('A' x 4096) . '>')],
    ['gena-callback-16384', subscribe('<http://127.0.0.1/' . ('A' x 16384) . '>')],
    ['soap-single-quote', soap("'")],
    ['soap-long-4096', soap("'" . ('A' x 4096))],
    ['soap-long-16384', soap("'" . ('A' x 16384))],
    ['soap-self-map-router-address', add_mapping('10.0.2.15')],
);

die "miniupnpd baseline is not alive\n" unless control();
print "scope=localhost-only network-disabled container\n";
print "miniupnpd_control_before=alive\n";
for my $case (@cases) {
    my ($name, $payload) = @$case;
    my $response = exchange($payload);
    my ($status) = $response =~ /\A([^\r\n]*)/;
    my ($error_code) = $response =~ m{<errorCode>(\d+)</errorCode>};
    my $alive = control();
    printf(
        "case=%s request_bytes=%d response_bytes=%d status=%s error_code=%s alive=%s\n",
        $name, length($payload), length($response), ($status // 'empty'),
        ($error_code // 'none'),
        $alive ? 'yes' : 'no',
    );
    die "miniupnpd died after $name\n" unless $alive;
}
print "miniupnpd_control_after=alive\n";
