#include <iostream>

#include <stdio.h>

struct test_num
{
    const char * utf8;
};


int main(int argc, char** argv)
{
    unsigned long AA = 0x1f;
    
    test_num test;

    test.utf8 = (const char *)&AA;

    printf("******* the utf8 value : %d \n", *(unsigned long *)(test.utf8));
    return 0;
}
