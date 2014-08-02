#ifndef __LIST_H__
#define __LIST_H__

#include <iostream>
#include <string.h>

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

			linkList& operator=(const linkList<T>& olink);
			T operator[](size_t index);
#if 0
			T& operator[](size_t index);
#endif

			bool push_head(const T& value);
			bool push_tail(const T& value);
			bool push_value_by_postion(const T& value, const T&);

			bool delete_value(const T& value);

			bool modify_value(const T& orignalValue, const T&replaceValue);

			bool find_value(const T& value);

			bool clear_all_value();

			size_t list_length() const;
			T get_value_by_index(size_t index) const;
			bool set_value_by_index(size_t index, const T& value);

			void show() const;

//advance
			void sort();
			void reverseList();
			void mergeList(linkList& olink);
	};
	
	template<typename T>
	linkList<T>::linkList()
	{
		first = NULL;
	}
	
	//*******************
	template<typename T>
	linkList<T>::linkList(T value)
	{
		Node*temp = new Node;
		if(temp)	{
			temp->value = value;
			temp->next = NULL;
		}	

		first = temp;
	}
			
	template<typename T>
	linkList<T>::linkList(const linkList<T>& olink)
	{
		clear_all_value();
		for(size_t i = 0; i < olink.list_length(); ++i){
			push_tail(olink.get_value_by_index(i));		
		}	
	}

	template<typename T>
	linkList<T>::~linkList()
	{
		clear_all_value();

		if(first)
			delete first;

		first = NULL;
	}

	template<typename T>
	linkList<T>& linkList<T>::operator=(const linkList<T>& olink)
	{
		if(this == &olink)
			return *this;

		clear_all_value();

		for(size_t i = 0; i < olink.list_length(); ++i){
			this->push_tail(olink.get_value_by_index(i));		
		}	

		return *this;
	}

	template<typename T>
	T linkList<T>::operator[](size_t index)
	{
		return get_value_by_index(index);	
	}
#if 0
	template<typename T>
	T& linkList<T>::operator[](size_t index)
	{
		Node*temp = first;
		size_t length = 0;

		while(temp) {
			if(length++ == index) {
				return temp->value;				
			}
			temp = temp->next;
		}
	}
#endif

	template<typename T>
	bool linkList<T>::push_head(const T& value)
	{
		Node *newNode = new Node;
		if(!newNode){
			cout << "new error"	 << endl;
			return false;
		}
		
		newNode->value = value;
		newNode->next = first;
		first = newNode;
	
		return true;
	}

	template<typename T>
	bool linkList<T>::push_tail(const T& value)
	{
		Node*index = first;

		while(index && index->next){
			index = index->next;	
		}
		
		Node *newNode = new Node;
		if(!newNode){
			cout << "new error"	 << endl;
			return false;
		}
		newNode->value = value;
		newNode->next = NULL;

		if(!index) first = newNode; else
			index->next = newNode;	
	
		return true;
	}

	template<typename T>
	bool linkList<T>::push_value_by_postion(const T& value, const T& postionValue)
	{
		Node*index  = first;

		while(index) {
			if(index->value == postionValue)
				break;
			index = index->next;		
		}

		if(!index){
			cout << "not find the value"<< endl;
			return false;
		}

		Node* newNode = new Node;
		newNode->value = value;

		newNode->next = index->next;
		index->next = newNode;
	
		return true;
	}

	template<typename T>
	bool linkList<T>::delete_value(const T& value)
	{
		Node* index = first;	
		if(!index)
			return false;

		while(index->next){
			if(index->next->value == value) {
				Node*temp = index->next;
				index->next = index->next->next;
				
				delete temp;
				temp = NULL;
			}
			index = index->next;
		}

		return true;
	}

	template<typename T>
	bool linkList<T>::modify_value(const T& orignalValue, const T&replaceValue)
	{
		Node* index = first;
		if(!index)
			return false;

		while(index){
			if(index->value == orignalValue){
				index->value = replaceValue;	
			}
			index = index->next;
		}
	
		return true;
	}

	template<typename T>
	bool linkList<T>::find_value(const T& value)
	{
		Node* index = first;
		if(!index)
			return false;

		while(index){
			if(index->value == value){
				break;
			}
			index = index->next;
		}

		if(!index)
			return false;
	
		return true;
	}

	template<typename T>
	bool linkList<T>::clear_all_value()
	{
		Node* temp = NULL;

		while(first){
			temp = first;
			first = first->next;
			delete temp;
		}
	
		return true;
	}

	template<typename T>
	size_t linkList<T>::list_length() const
	{
		Node* index = first;	
		size_t length = 0;

		while(index){
			++length;
			index = index->next;
		}
		return length;
	}

	template<typename T>
	T linkList<T>::get_value_by_index(size_t index) const
	{
		Node*temp = first;
		size_t length = 0;
		T result;
		memset(&result, 0, sizeof(result));

		while(temp) {
			if(length++ == index) {
				result = temp->value;				
				break;
			}
			temp = temp->next;
		}
		return  result;
	}

	template<typename T>
	bool linkList<T>::set_value_by_index(size_t index, const T& value)
	{
		Node*temp = first;
		size_t length = 0;
		bool setFlag = false;

		while(temp) {
			if(length++ == index) {
				temp->value = value;
				setFlag = true;
				break;
			}
			temp = temp->next;
		}

		return setFlag;
	}


	template<typename T>
	void linkList<T>::show() const
	{
		Node*index = first;
		if(!index){
			cout << "no value"<< endl;
			return;
		}

		while(index){
			cout << "__" << index->value;
			index = index->next;
		}
		cout << endl;
	}

//ÄæÐò
	template<typename T>
	void linkList<T>::reverseList()
	{
		Node* p1 = first;
		Node* p2 = NULL;
		Node* p3 = NULL;

		if(p1)
			p2 = p1->next;				

		if(p2)
			p3 = p2->next;

		if(p1)
			p1->next = NULL;

		while(p3){
			p2->next = p1;
			p1 = p2;
			p2 = p3;
			p3 = p3->next;
		}

		if(p2) {
			p2->next = p1;
			first = p2;
		}
	}

	template<typename T>
	void linkList<T>::sort()
	{
		T tempValue = 0;
		size_t index = 0;
		for(size_t i = 0; i < list_length(); ++i){	
			index = i;

			for(size_t j = i + 1; j < list_length(); ++j){
				if(get_value_by_index(j) < get_value_by_index(index)){
						index = j;	
				}
			}

			if(index != i){
				tempValue = get_value_by_index(index);
				set_value_by_index(index, get_value_by_index(i));
				set_value_by_index(i, tempValue);
			}
		}
	}

	template<typename T>
	void linkList<T>::mergeList(linkList<T>& olink)
	{
		//for ensure the list is orderly
		sort();
		olink.sort();

		size_t orignalLength = 0;
		size_t olinkLength = 0; 
	
		linkList tempList;

		while(1){
			if(olink.get_value_by_index(olinkLength) < get_value_by_index(orignalLength)){
				tempList.push_tail(olink.get_value_by_index(olinkLength));
				++olinkLength;	
			}else if(olink.get_value_by_index(olinkLength) > get_value_by_index(orignalLength)){
				tempList.push_tail(get_value_by_index(orignalLength));
				++orignalLength;	
			}else {
				tempList.push_tail(get_value_by_index(orignalLength));
				tempList.push_tail(olink.get_value_by_index(olinkLength));
				++orignalLength;
				++olinkLength;
			}

			if(olinkLength >= olink.list_length()){
				break;
			}
			
			if(orignalLength >= this->list_length())
				break;
		}

		if(olinkLength != olink.list_length()){
			for(unsigned int i = olinkLength; i < olink.list_length(); ++i)	{
				tempList.push_tail(olink.get_value_by_index(i));	
			}
		}else if(orignalLength != this->list_length()){
			for(unsigned int i = orignalLength; i < this->list_length(); ++i){
				tempList.push_tail(this->get_value_by_index(i));	
			}
		}

		tempList.show();
	}
}

#endif
