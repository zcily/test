#include "Sales_data.h"

namespace MyOperator
{
	ostream& operator<<(ostream& out, const Sales_data& sd)
	{
		cout << "use << operator function"	 << endl;

		out << "bookNo      : " << sd.bookNo << endl;
		out << "units_sold  : " << sd.units_sold << endl;

		return out;
	}


	istream& operator>>(istream& in, Sales_data& sd)
	{
		cout << "use the >> operator function" << endl;
		in >> sd.bookNo >> sd.units_sold;	

		return in;
	}

	Sales_data& Sales_data::operator+(const Sales_data& sd)
	{
		cout << "use the + operator function" << endl;

		if(this == &sd)	
			return *this;

		if(this->bookNo == sd.bookNo)
			this->units_sold += sd.units_sold;

		return *this;
	}

	Sales_data& Sales_data::operator=(const Sales_data& sd)
	{
		cout << "use the = operator function" << endl;

		if(this == &sd)	
			return *this;

		this->bookNo = sd.bookNo;
		this->units_sold = sd.units_sold;

		return *this;
	}

	Sales_data& Sales_data::operator+=(const Sales_data&sd)
	{
		cout << "use the += operator function"	 << endl;
		if(this == &sd)
			return *this;

		*this = *this + sd;

		return *this;
	}
}
