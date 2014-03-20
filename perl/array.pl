#!/usr/bin/perl -W

use warnings;

$rocks[0] = 'testone';
$rocks[1] = 'testtwo';
$rocks[3] = 'testthree';
$rocks[4] = 'testfour';
$rocks[5] = 'testfive';
$rocks[6] = 'testsix';
$rocks[96] = 'testninety-six';

$rocks_number = $#rocks;

print "*********** rocks_number $#rocks   ll $rocks[@rocks - 1]\n";

@array_in = ("fred", 2.2);

foreach $w(@array_in){
    print "$w \n";
}

@test_qw = qw(fred barney betty wilma dino);

foreach $a(@test_qw){
    print "$a \n";
}

@replace = qw(zhang wu yi);
@array_pop = 0..9;
printf ("the array_pop : @array_pop \n");
$fred = pop(@array_pop);
printf ("after pop     : @array_pop \n");
printf ("the pop value : $fred \n");
$fred = pop(@array_pop);
printf ("after pop     : @array_pop \n");
printf ("the pop value : $fred \n");
push(@array_pop, 100);
printf ("after push    : @array_pop \n");
shift(@array_pop);
printf ("after shift   : @array_pop \n");
unshift(@array_pop, 1220);
printf ("after unshift : @array_pop \n");

@array_temp = splice(@array_pop, 2, 0, @replace);
printf ("after splice  : @array_pop \n");

@rock_o = qw(zhang wu yi);
foreach $rock_f(@rock_o) {
    $rock_f = "\t$rock_f\n";
}
print "my name is : @rock_o \n";

@array_pop = reverse @array_pop;
printf  "after reverse : @array_pop \n";

@array_pop = sort @array_pop;
printf  "after sort    : @array_pop \n";


my @rocks_t = qw(bedrock slate rubble granite);
while(my($index, $value) = each @rocks_t){
    printf "$index : $value \n";
}

#test_one
print "please enter any words \n";
chomp(@input = <STDIN>);
print "the enter value : @input\n";
@input = reverse @input;
print "reverse   value : @input\n";

#test_two
@people_name = qw(fred betty barney dino wilma pebbles bamm-bamm);

print "name : @people_name\n";
print "please enter the people you want to choose : \n";
chomp(@input_number = <STDIN>);

print "you choose : ";
foreach (@input_number){
    print " $people_name[$_ - 1] ";
}
print "\n";

#test_three
chomp(@name = <STDIN>);
print "orignal name : @name\n";
@name = sort(@name);
print ("after sort name : @name\n");
