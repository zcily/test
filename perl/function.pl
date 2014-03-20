#!/usr/bin/perl

use warnings;

#test function

sub test_function {
    $n += 1;
    print "test function $n\n";
    $n;
}

&test_function;
&test_function;
&test_function;
$return_value = &test_function;

printf "????? the n value : $n\n";

print "the function return value : $return_value\n";

sub compare_value {
    my($m, $n) = @_;
    if ($m > $n) {
        $m;
    }else {
        $n;
    }
}

sub max_of_array {
    my($max_value);
    $max_value = shift @_;
    foreach $c(@_){
        print "*********** $c \n";
        if( $max_value < $c) {
            $max_value = $c;
        }
    }
    $max_value;
}

#print "please enter two number : \n";
#chomp(@numbers = <STDIN>);
@numbers = (13, 56);
$max_number = &compare_value($numbers[0], $numbers[1]);
print "the two number is  $numbers[0] ,  $numbers[1]  max value : $max_number\n";


@array_d = (34, 23, 64,1,24,5);

$max_value = &max_of_array(@array_d);

printf ("the array @array_d max value : $max_value \n");


sub test_zuoyong {
    my $test_value = 50; 
    foreach(1..100) { 
    }
    print "the test_value : $test_value \n";
}

&test_zuoyong;
