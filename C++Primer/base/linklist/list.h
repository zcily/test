#ifndef __LIST_H__
#define __LIST_H__

#include <iostream>

using namespace std;

namespace MyList
{
	template<typename T> class linkList
	{
		private:
			struct Node{
				T value;	
				Node *next;
			};

			Node* first = NULL;

		public:
			linkList();
			linkList(T value);
			linkList(const linkList& olink);
			virtual ~linkList();

			linkList& operator=(const linkList&olink);

			bool push_head(const T& value);
			bool push_tail(const T& value);
			bool push_value_by_postion(const T& value, const T&);

			bool delete_value(const T& value);

			bool modify_value(const T& orignalValue, const T&replaceValue);

			bool find_value(const T& value);

			bool clear_all_value();
	};
	
	template<typename T>
	linkList<T>::linkList()
		:first(new Node)
	{
		if(this->first)
			this->first->value = 0;
	}
	
	template<typename T>
	linkList<T>::linkList(T value)
		:first(new Node)
	{
		if(this->first)	
			this->first->value = value;
	}
			
	template<typename T>
	linkList<T>::linkList(const linkList& olink)
	{
	}

	template<typename T>
	linkList<T>::~linkList()
	{
		clear_all_value();

		delete first;
		first = NULL;
	}

	template<typename T>
	linkList<T>& linkList<T>::operator=(const linkList& olink)
	{
		if(this == &olink)
			return *this;
	
		return *this;
	}

	template<typename T>
	bool linkList<T>::push_head(const T& value)
	{
	
		return true;
	}

	template<typename T>
	bool linkList<T>::push_tail(const T& value)
	{
	
		return true;
	}

	template<typename T>
	bool linkList<T>::push_value_by_postion(const T& value, const T&)
	{
	
		return true;
	}

	template<typename T>
	bool linkList<T>::delete_value(const T& value)
	{
	
		return true;
	}

	template<typename T>
	bool linkList<T>::modify_value(const T& orignalValue, const T&replaceValue)
	{
	
		return true;
	}

	template<typename T>
	bool linkList<T>::find_value(const T& value)
	{
	
		return true;
	}

	template<typename T>
	bool linkList<T>::clear_all_value()
	{
	
		return true;
	}
}

#endif
