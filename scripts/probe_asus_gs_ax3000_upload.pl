#!/usr/bin/perl
use strict;
use warnings;
use IO::Socket::INET;

open(my $archive_file, '<:raw', '/proof.tgz') or die "open proof: $!\n";
local $/;
my $archive = <$archive_file>;
close($archive_file);

my @cases = (
    ['form_exact', 'FRIDAYGSAX3000BOUNDARY', 0, 'proof.tgz'],
    ['quoted_boundary', 'FRIDAYGSAX3000QUOTED', 1, 'proof.tgz'],
    ['browser_boundary', '----WebKitFormBoundary7MA4YWxkTrZu0gW', 0,
     'server_ovpn.tgz'],
);

for my $case (@cases) {
    my ($label, $boundary, $quoted, $filename) = @$case;
    my $body =
        "--$boundary\r\n" .
        "Content-Disposition: form-data; name=\"import_cert_file\"; filename=\"$filename\"\r\n" .
        "Content-Type: application/gzip\r\n\r\n" .
        $archive .
        "\r\n--$boundary--\r\n";
    my $boundary_parameter = $quoted ? qq{"$boundary"} : $boundary;
    my $request =
        "POST /upload_server_ovpn_cert.cgi HTTP/1.1\r\n" .
        "Host: 127.0.0.1\r\n" .
        "Content-Type: multipart/form-data; boundary=$boundary_parameter\r\n" .
        "Content-Length: " . length($body) . "\r\n" .
        "Connection: close\r\n\r\n" . $body;

    my $sock = IO::Socket::INET->new(
        PeerAddr => '127.0.0.1', PeerPort => 80, Proto => 'tcp', Timeout => 8,
    ) or die "connect: $!\n";
    $sock->autoflush(1);
    print {$sock} $request;
    shutdown($sock, 1);
    my $response = '';
    while (length($response) < 65536) {
        my $block = '';
        my $count = sysread($sock, $block, 8192);
        last if !defined($count) || $count == 0;
        $response .= $block;
    }
    close($sock);

    my @statuses = $response =~ /^(HTTP\/[^\r\n]*)/mg;
    print "case=$label request_bytes=" . length($request) . "\n";
    print "case=$label response_bytes=" . length($response) . "\n";
    print "case=$label status_count=" . scalar(@statuses) . "\n";
    print "case=$label statuses=" . join(' | ', @statuses) . "\n";
}
