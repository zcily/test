#ifndef __QUOTE_H__
#define __QUOTE_H__

#include <iostream>
#include <string>

using namespace std;

namespace MyVirtual
{
	class Quote
	{
		friend class testFriend;
		public:
			Quote(const string &bookNumber = "", double Bprice = 0.0)
				:bookNo(bookNumber)
				,price(Bprice)
			{}

			virtual ~Quote() 
			{
				cout << "no need the destruct but i also write it" << endl;
			}

			string isbn() {return bookNo;}
			virtual double net_price(size_t n) const;
			void test1(){cout << "in test1" << endl;}
			void test1(int i){cout << "in test1 int i" << endl;}
		private:
			string bookNo;
		protected:
			double price;
			void test() {cout << "test protected function call" << endl;};
	};

	class Bulk_quote : public Quote
	{
		public:
			Bulk_quote(const string& bookNumber= "", double bookPrice = 0.0, size_t mq = 0, double dc = 0.0)
				:Quote(bookNumber, bookPrice)
				,min_qty(mq)
				,discount(dc)
			{}
			virtual ~Bulk_quote()
			{
				cout << "destruct the Bulk_quote" << endl;
			}

			double net_price(size_t) const;
			void testProtected(Bulk_quote& qt){cout << "......" << endl; qt.test();}
			//void test1(){cout << "in Bulk_quote test1" << endl;}
		private:
			size_t min_qty;
			double discount;
	};

	class testFriend
	{
		public:
			testFriend(Quote&qt) {string temp = qt.bookNo;}
	};
}

#endif
