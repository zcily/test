#!/usr/bin/perl -W


@a = ('a', 'b', 'c', 'd');

@a = join('**', @a);

print @a,"\n";


$b = qq(a,b,c);

@a = split(/:/,$b);

printf "after spilt  @a \n";

@c = ('a', 'b', 'g');

($d, $e, $f)=@c;


printf("****** the d : $d\n");
printf("****** the e : $e\n");
printf("****** the f : $f\n");


sub test()
{
    print ("in the function test\n");
}


test();



$double_array = [[1,2,3,4], ['f','d','d']];


printf("the double_array $double_array->[1][2] \n");
printf("the double_array other way :  @{$double_array->[1]}[0]\n");


printf @{$double_array->[0]}[1];
printf "\n";
