#!/usr/bin/perl -W

use warnings;
use 5.014;

my %hash_test;

$hash_test{testone} = 'yes';
$hash_test{testtwo} = 'no';
$hash_test{testthree} = 'yes and no';

%hash_test = (
    test => 'A',
    test1   => 'B',
    test2    => 'c',
);

my $key;
my $value;

while(($key, $value) = each %hash_test) {
   say "key : $key => $value" ;
}

say "******************  $hash_test{test1}";
%hash_test = (
    zhang => 'A',
    yes   => 'B',
    wu    => 'c',
);

while(($key, $value) = each %hash_test) {
   say "key : $key => $value" ;
}

#test one

my %people_name = (
    zhang => "wuyi",
    dai   => "sister",
    testo => "dont know who",
);

my $c_name;

while(chomp($c_name = <STDIN>)) {
    if ($c_name eq "quit"){
        say "quit test one\n";
        last;
    } elsif(exists $people_name{$c_name}) {
        say "$c_name => $people_name{$c_name}";
    } else {
        say "I don't know this one"; 
    }
}

#test two
my %words_hash;
foreach my $file_name (@ARGV) {
    open my $words_fh, "<", $file_name or die "can not open file : $!";
    foreach my $key(<$words_fh>) {
        chomp $key;
        $words_hash{$key} += 1;
        say "********my $key  $words_hash{$key}";
    }
}

while(($key, $value) = each %words_hash) {
    say "*********** $key => $value";
}

#test three
my $max_lenth;
my $first_flag = 0;
foreach $key(keys %ENV) {
    if($first_flag == 0) {
        $max_lenth = length ($key);
        $first_flag = 1;
        next;
    }
    if($max_lenth < length ($key)) {
        $max_lenth = length ($key);
    }
}

undef $first_flag;
foreach $key(sort keys %ENV) {
    printf "%${max_lenth}s : %-s  \n", $key, $ENV{$key};
}
