#include "Sales_data.h"

namespace MySales
{
    int salesData::a = 5;
    vector<int> salesData::vec(b);

    salesData::salesData()
        :bookIsbn("")
        ,bookCount(0)
    {
        cout << "construct by init" << endl;
    }

    salesData::salesData(const string &isbn, const int count)
        :bookIsbn(isbn)
        ,bookCount(count)
    {
        cout << "construct by " << isbn << endl;
    }

    salesData::salesData(const salesData& SD)
    {
        this->bookIsbn = SD.bookIsbn; 
        this->bookCount = SD.bookCount;
    }

    string salesData::isbn() const
    {
        return this->bookIsbn; 
    }

    salesData& salesData::combine(const salesData& newSalesData)
    {
        if(this == &newSalesData) 
            return *this;

        this->bookCount += newSalesData.bookCount;
        return *this;
    }

    salesData& salesData::operator+(const salesData &newSalesData)
    {
        if(this == &newSalesData) 
            return *this;

        this->bookCount += newSalesData.bookCount;
        return *this;     
    }

    salesData& salesData::operator-(const salesData &newSalesData)
    {
         if(this == &newSalesData) 
            return *this;

        this->bookCount -= newSalesData.bookCount;
        return *this;     
    }

    salesData& salesData::operator=(const salesData &newSalesData)
    {
         if(this == &newSalesData) 
            return *this;

        this->bookIsbn  = newSalesData.bookIsbn;
        this->bookCount = newSalesData.bookCount;

        return *this;     
    }
}
