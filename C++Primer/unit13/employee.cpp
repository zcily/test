#include "employee.h"

namespace MyEmployEE
{
    int Employee::EmployeeNo = 0;

    Employee::Employee(const string& Name)
    {
        cout << "init by name : "  << Name << endl;
        this->EmployeeName = Name;
        ++this->EmployeeNo;
        this->workNo = this->EmployeeNo;
    }

    Employee::Employee(const Employee& other)
    {
        this->EmployeeName = other.EmployeeName; 
        ++this->EmployeeNo;
        this->workNo = this->EmployeeNo;
    }

    Employee& Employee::operator=(const Employee& other)
    {
        this->EmployeeName = other.EmployeeName; 
        ++this->EmployeeNo;
        this->workNo = this->EmployeeNo;

        return *this;
    }

    Employee::~Employee()
    {
        --this->EmployeeNo; 
    }

    void Employee::show()
    {
        cout << "name : " << this->EmployeeName << endl;
        cout << "no   : " << this->workNo << endl;
    }

//---------------------------------hasptr-----------------------------
    HasPtr::~HasPtr()
    {
        cout << " use  : " << *use << endl;
        if(--*use == 0)  {
            cout << "ready to delete hasptr" << endl;
            delete ps;
            delete use;
        }
    }

    HasPtr& HasPtr::operator=(const HasPtr& hp)
    {
        //赋值时元对象要被销毁掉一个。
        ++*hp.use;
        if(--*use == 0){
            delete ps; 
            delete use;
        }
        this->use = hp.use;
        this->ps = hp.ps;
        this->i = hp.i;

        return *this;
    }

    HasPtr& HasPtr::swap(HasPtr &hp)
    {
        //交换不需要改变use计数 既没有减少也没有增加。
        using std::swap;
        swap(this->ps, hp.ps);
        swap(this->use, hp.use);
        swap(this->i, hp.i);
        cout << "use  swap " << endl;
        return *this; 
    }

    void HasPtr::show()
    {
        cout << "string :  "  << *this->ps << endl;
        cout << "i      :  "  << this->i  << endl;
        cout << "use    :  "  << *this->use << endl;
    }

    bool HasPtr::operator<(const HasPtr& hp)
    {
        return *this->ps < *hp.ps;
    }
}
