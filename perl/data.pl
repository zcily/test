#!/usr/bin/perl

#use 5.014;
use utf8;
use warnings;
use diagnostics;

$little = 10 / 3;

$mi = 2 ** 8;

printf ("the value 10 / 3 = $little   mi : $mi\n");


print q(print in qfasfasdf\n\'\\);
print qq(print in qq fasfasfasdf \x{2688}\n);

printf qq(hello).qq(world).qq(\n);


printf "zhang" x 5 . "\n";

printf 5 x 4 . "\n";


$test_op = "1233ccfa3" * 4;
printf("the test_op value : $test_op\n");

$my_name = "zhangwuyi";
if($my_name eq "zhangwuyi") {
    printf "you name is zhangwuyi  i know you\n";
}else {
    printf "i don't know who you are!!!!\n";
}


if('0') {
    print "\'0\' is the true\n";
} else {
    print "\'0\' is the false\n";
}

$name = "zhangwuyi\n";
chomp($name);
if($name eq "zhangwuyi") {
    print "ok  find you\n";
} else {
    print "not find \n";
}


#test1
$banjing = 12.5;
$zhouchang = $banjing * 2 * 3.141592654;
print "the zhouchang = $zhouchang \n";

#TEST2 and test3
$banjing2 = <STDIN>;
if($banjing2 < 0) {
    $zhouchang  = 0;
} else {
    $zhouchang = $banjing2 * 2 * 3.141592654;
}
print "the zhouchang = $zhouchang \n";


#test4 
print "please enter two number :  ";

$number_one = <STDIN>;
$number_two = <STDIN>;

$number_x = $number_one * $number_two;
print "the two number fix : $number_x \n";

#test5

print "please enter the string and number \n";

$string = <STDIN>;
chomp($string);
$number = <STDIN>;

$result = $string x $number;
print "$result\n";

