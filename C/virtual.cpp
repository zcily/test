#include <iostream>

using namespace std;

class A
{
public:
    A(){cout << "construc A " << endl;}
    ~A(){ cout << "destroy A " << endl;}
    virtual void test()
    {
        cout << "test in A " << endl;
    }
};

class B : public A
{
public:
    B(){cout << "construct B " << endl;}
    ~B(){cout << "destroy  B " << endl;};
    virtual void test()
    {
        cout << "test in B " << endl;
    }
    void test_t()
    {
        test();
    }
};

int main(int argc, char**argv)
{
  // A* test_aa = new A;
   //B* test_a = static_cast<B*>(new A); 
   B test_a;
   test_a.test_t();
}
