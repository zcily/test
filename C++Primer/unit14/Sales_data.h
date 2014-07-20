#ifndef __SALES_DATA_H__
#define __SALES_DATA_H__

#include <string>
#include <iostream>

using namespace std;

namespace MyOperator
{
	class Sales_data
	{
		public:
			Sales_data(const string number = "", const int sold = 0, const double revenues = 0.0)
				:bookNo(number)
				,units_sold(sold)
			{}
			~Sales_data(){ cout << "no need to destruct!!!" << endl;}

			Sales_data& operator=(const Sales_data&);
			Sales_data& operator+(const Sales_data&);
			Sales_data& operator+=(const Sales_data&);
			const char& operator[](size_t i) const 
			{
				cout << "use []  const " << endl;
				if(i < bookNo.size()) 
					return bookNo[i];
			}

			char & operator[](size_t i)
			{
				cout << "use [] non const " << endl;
				if(i < bookNo.size())
					return bookNo[i];
			}

			Sales_data& operator++()
			{
				cout << "use ++ without value"	 << endl;
				++units_sold;

				return *this;
			}

			Sales_data operator++(int)
			{
				cout << "use ++ with int "	 << endl;

				Sales_data temp = *this;

				++units_sold;

				return temp;
			}

			operator int() const
			{
				cout << "qiangzhi zhuanhaun .... to int "	 << endl;
				return units_sold;
			}

			operator string() const
			{
				cout << "qiangzhi zhuanhaun .... to sting"	 << endl;
				return this->bookNo;
			}


			friend ostream& operator<<(ostream &out, const Sales_data&);
			friend istream& operator>>(istream &in, Sales_data&);
			
		private:
			string bookNo;
			int    units_sold;
	};
}

#endif
