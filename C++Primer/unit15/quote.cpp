#include "quote.h"

namespace MyVirtual
{
	double Quote::net_price(size_t n) const
	{
		cout << "net_price in quote" << endl;
		return n * this->price;
	}

	double Bulk_quote::net_price(size_t n) const
	{
		cout << "net_price in Bulk_quote"	 << endl;

		if(n >= this->min_qty)
			return n * ( 1 - this->discount )* price;
		else
			return n * price;	
	}
}
