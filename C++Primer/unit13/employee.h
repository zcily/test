#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include <iostream>
#include <string>

using namespace std;

namespace MyEmployEE
{
    class Employee
    {
        public:
            Employee(const string &name = string(""));
            Employee(const Employee&);
            Employee& operator=(const Employee&);
            void show();
            ~Employee();

        private:
            string EmployeeName;
            static int EmployeeNo;
            int    workNo;
            size_t *use;
    };


    class HasPtr
    {
        public:
            HasPtr(const string &s = string(""))
                :ps(new string(s))
                ,use(new size_t(1))
                ,i(0)
            {} 

            HasPtr(const HasPtr& other) 
                :ps(other.ps) 
                ,use(other.use) 
                ,i(other.i) 
            {
                ++*use;
            }
            HasPtr& operator=(const HasPtr&);
            ~HasPtr();

            HasPtr& swap(HasPtr&);
            void show();
            bool operator<(const HasPtr&);
        private:
            string *ps;
            size_t *use;
            int i;
    };
}

#endif
