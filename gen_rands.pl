#!/usr/bin/perl
# Usage: perl gen_rands.pl <#elm> <max> <random-seed>
use strict;

my $nelm=100;
my $nmax=1000000;

if (@ARGV >= 1) {
    $nelm = $ARGV[0];
}
if (@ARGV >= 2) {
    $nmax = $ARGV[1];
}
if (@ARGV >= 3) {
    srand $ARGV[2];
}

foreach my $i (1..$nelm) {
    print int(rand($nmax));
    print "\n";
}
