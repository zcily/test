#!/usr/bin/perl

use warnings;
use 5.014;

#test question one
my @file_content_temp;

foreach my $file_name (@ARGV) {
    open my $read_fh, '<', $file_name or die "open file error : $!";
    while(<$read_fh>) {
        unshift @file_content_temp, $_;
    }
    close $read_fh;
}
print "after use the tac context : \n", @file_content_temp;

#test question two


say "Please enter the dui qi number : ";

my $duiqi = <STDIN>;

chomp $duiqi;
say "Please enter the two words";
say "123456789012345678901234567890";

foreach my $value(<STDIN>) {
    chomp $value;
    printf "%${duiqi}s\n", $value;
}


