#!/usr/bin/perl
use strict;
use warnings;
use IO::Socket::INET;

my $host = $ENV{TARGET_HOST} // '127.0.0.1';
my $port = $ENV{TARGET_PORT} // 80;
my $timeout = 4;

sub request {
	my ($raw) = @_;
	my $sock = IO::Socket::INET->new(
		PeerHost => $host,
		PeerPort => $port,
		Proto => 'tcp',
		Timeout => $timeout,
	) or return "CONNECT_ERROR:$!";

	my $offset = 0;
	while ($offset < length($raw)) {
		my $written = syswrite($sock, $raw, length($raw) - $offset, $offset);
		return "WRITE_ERROR:$!" if !defined($written);
		$offset += $written;
	}
	local $SIG{ALRM} = sub { die "READ_TIMEOUT\n" };
	alarm($timeout);
	my $response = '';
	while (1) {
		my $chunk = '';
		my $read = sysread($sock, $chunk, 8192);
		last if !defined($read) || $read == 0;
		$response .= $chunk;
		last if length($response) > 262_144;
	}
	alarm(0);
	close($sock);
	return $response;
}

sub post {
	my ($path, $type, $body) = @_;
	return "POST $path HTTP/1.0\r\n" .
		"Host: router.local\r\n" .
		"Content-Type: $type\r\n" .
		"Content-Length: " . length($body) . "\r\n" .
		"Connection: close\r\n\r\n" .
		$body;
}

my @cases = (
	['control-get', "GET /cgi-bin/luci/ HTTP/1.0\r\nHost: router.local\r\nConnection: close\r\n\r\n"],
	['empty-form', post('/cgi-bin/luci/', 'application/x-www-form-urlencoded', '')],
	['malformed-percent', post('/cgi-bin/luci/', 'application/x-www-form-urlencoded', 'luci_username=%&luci_password=%0')],
	['encoded-nul', post('/cgi-bin/luci/', 'application/x-www-form-urlencoded', 'luci_username=admin%00suffix&luci_password=x')],
	['duplicate-login-fields', post('/cgi-bin/luci/', 'application/x-www-form-urlencoded',
		('luci_username=a&' x 128) . ('luci_password=b&' x 128))],
	['long-form-name', post('/cgi-bin/luci/', 'application/x-www-form-urlencoded', ('A' x 8192) . '=x')],
	['long-form-value', post('/cgi-bin/luci/', 'application/x-www-form-urlencoded', 'luci_username=' . ('A' x 65536))],
	['truncated-json', post('/cgi-bin/luci/', 'application/json', '{"x":[')],
	['deep-json', post('/cgi-bin/luci/', 'application/json', ('[' x 256) . '0' . (']' x 256))],
	['multipart-no-boundary', post('/cgi-bin/luci/', 'multipart/form-data', 'x')],
	['multipart-truncated', post('/cgi-bin/luci/', 'multipart/form-data; boundary=EW1200',
		"--EW1200\r\nContent-Disposition: form-data; name=\"x\"\r\n\r\nvalue")],
	['multipart-long-boundary', post('/cgi-bin/luci/', 'multipart/form-data; boundary=' . ('B' x 8192), '')],
	['dot-segments', "GET /cgi-bin/luci/../../etc/passwd HTTP/1.0\r\nHost: router.local\r\nConnection: close\r\n\r\n"],
	['encoded-dot-segments', "GET /cgi-bin/luci/%2e%2e/%2e%2e/etc/passwd HTTP/1.0\r\nHost: router.local\r\nConnection: close\r\n\r\n"],
	['encoded-slash', "GET /cgi-bin/luci/%2f%2e%2e%2fetc%2fpasswd HTTP/1.0\r\nHost: router.local\r\nConnection: close\r\n\r\n"],
	['long-path-info', "GET /cgi-bin/luci/" . ('A' x 8192) . " HTTP/1.0\r\nHost: router.local\r\nConnection: close\r\n\r\n"],
);

for my $case (@cases) {
	my ($name, $raw) = @$case;
	my $result;
	eval { $result = request($raw); 1 } or $result = "ERROR:$@";
	my ($status) = $result =~ /\AHTTP\/\d\.\d\s+(\d+)/;
	$status //= substr($result, 0, 100);

	my $control = request("GET /cgi-bin/luci/ HTTP/1.0\r\nHost: router.local\r\nConnection: close\r\n\r\n");
	my $alive = ($control =~ /\AHTTP\/\d\.\d\s+\d+/) ? 'yes' : 'no';
	print "$name\tstatus=$status\talive=$alive\tresponse_bytes=" . length($result) . "\n";
}
