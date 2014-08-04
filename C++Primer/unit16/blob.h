#ifndef __BLOB_H__
#define __BLOB_H__

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

namespace Myblob
{
	template<typename T> void testFriend(const T&);

	template<typename T> class Blob
	{
		typedef T value_type;
		typedef typename vector<T>::size_type size_type;
		
		public:

		friend void testFriend<>(const Blob<T>& b);

		public:
			Blob();
			Blob(initializer_list<T> ilist);
			size_type size() const {return data->size(); }
			bool empty() const {return data->empty();}
			void push_back(const T& t) {data->push_back(t);}
			void pop_back();
			T& back();
			T& operator[] (size_type i);
		private:
			shared_ptr<vector<T>> data;
			int test;
			bool check(size_type i, const string &msg) const;
	};

	template<typename T> Blob<T>::Blob()
		:data(make_shared<vector<T>>())
	{
		cout << "init vector" << endl;
	}

	template<typename T> Blob<T>::Blob(initializer_list<T> list)
		:data(make_shared<vector<T>>(list))
	{
		cout << "init by initializer_list" << endl;
	}

	template<typename T> void Blob<T>::pop_back()
	{
		check(0, "pop back on empty blob");
		data->pop_back();
	}

	template<typename T> T& Blob<T>::back()
	{
		check(0, "back on empty blob");
		return data->back();	
	}

	template<typename T> T& Blob<T>::operator[](size_type i)
	{
		check(i, "subscript out of range");
		return (*data)[i];
	}

	template<typename T> bool Blob<T>::check(size_type i, const string &msg) const
	{
		if(i >= data->size())		
			throw out_of_range(msg);
		return true;
	}
}

#endif
