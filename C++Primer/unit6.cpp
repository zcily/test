#include <iostream>
#include <vector>
#include <stdlib.h>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int testFun(int a, int b)
{
    cout << "just test fun pointer  a " << a << "  b  " << b << endl;
}

int add(int a, int b)
{
    cout << "just test fun pointer  a  + b  = " << a + b << endl;
}

int jian(int a, int b)
{
    cout << "just test fun pointer  a  - b  = " << a  -  b << endl;
}

int chen(int a, int b)
{
    cout << "just test fun pointer  a  * b  = " << a  * b  << endl;
}

int chu(int a, int b)
{
    cout << "just test fun pointer  a  / b  = " << a / b << endl;
}

typedef int (*func)(int, int);

int main(int argc, char**argv)
{
    vector<func> test;

    test.push_back(add);
    test.push_back(jian);
    test.push_back(chen);
    test.push_back(chu);

    for(int i = 0; i < test.size(); ++i){
        test[i](10, 2);
    }
    return EXIT_SUCCESS;
}


