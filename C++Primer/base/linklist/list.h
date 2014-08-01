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

			unsigned int list_length();

			void show();
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

		if(!index)
			first = newNode;
		else
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
	void linkList<T>::show()
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
}

#endif
