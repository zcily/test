#!/usr/bin/perl -W

$value = -5 ** 2.5;


$value_of_mix = 'a' + 2; 

printf "the value is : $value \n";
printf "the mix value is : $value_of_mix \n";

if ( $value >= $value_of_mix )
{
    printf "the first value is bigger \n";
}
else
{
    printf "the second value is bigger \n";
}
$ab = 'a';
while( 1 )
{
    if (++$ab gt 'h') 
    {
        last;
    }
    printf "************8 $ab \n"
}

printf "the value of ab : $ab \n";

until ($ab ge 'y')
{
    ++$ab;
}
printf "the value of ab : $ab \n";


foreach $a(1,2,4,34,5)
{
    printf "the value is : $a \n";
}

$a = 12 % 5;

printf "the value of a is : $a \n";


$b = 'a';

++$b;

printf "the value of b is : $b \n";


$c = 15 & 12;

printf "the value of c is : $c \n";


$d = 'z';
++$d;

printf "the value of d is : $d \n";


$e = 'a';

for( $e = 'a'; $e lt 'y'; ++$e)
{
    if( $e gt 'h' && $e le 'n')
    {
        next;
    }

    printf "*******************   $e \n";
}


@test_array = (5,34,234,78,5,9,4);
printf "the test_array value is : @test_array\n";

foreach $a(@test_array[0, 1,2,3])
{
    printf "the value of array[]  $a \n";

    if( $a == 34)
    {
        goto test_label;
    }
}

goto normal;

test_label:
printf ("*************** test_label \n");

normal:
printf ("*************** normal_label \n");
