#ifndef __SALES_DATA_H__
#define __SALES_DATA_H__

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

namespace MySales
{
    class salesData
    {
        public:
            salesData();
            salesData(const string &isbn, const int count);
            salesData(const salesData&);

            string isbn() const;
            salesData& combine(const salesData&);
            salesData& operator+(const salesData&);
            salesData& operator-(const salesData&);
            salesData& operator=(const salesData&);

        private:
            string bookIsbn;
            int    bookCount;
            static int a;
            static const int b = 5;
            static vector<int> vec;
    };
}

#endif
