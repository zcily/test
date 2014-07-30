#include <iostream>
#include <stdlib.h>

using namespace std;
//********************** bubble sort
template<typename T>
void bubble_sort(T *array, const int lenth)
{
	int sortOverFlag = false;
	T tempValue;

	for(int i = 0; i < lenth - 1; ++i) {
		for(int j = 0; j < lenth - 1 - i; ++j) {
			if(*(array + j) > *(array + j + 1))	{
				sortOverFlag = true;
				tempValue = *(array + j);
				*(array + j) = *(array + j + 1);
				*(array + j + 1) = tempValue;
			}
		}
		if(!sortOverFlag)
			break;
	}
}

//*********************** insert sort
template<typename T>
void insert_sort(T * array, const int lenth)
{
	T temp;

	for(int i = 1; i < lenth; ++i) {
		int j = i - 1;
		temp = *(array + i);

		while(j >= 0 && *(array + j) > temp){
			*(array + j + 1) = *(array + j);
			--j;
		}

		if(j != i - 1)
			*(array + j + 1) = temp;
	}
}

//********************* select sort
template<typename T>
void select_sort(T* array, const int lenth)
{
	T temp;
	int index;

	for(int i = 0; i < lenth; ++i){
		index = i;
		for(int j = i + 1; j < lenth; ++j){
			if(*(array + j) < *(array + i))	
				index = j;		
		}
		if(index != i){
			temp = *(array + i);
			*(array + i) = *(array + index);
			*(array + index) = temp;
		}
	}
}

//**************************** quick sort
template<typename T>
void quick_sort(T* array,  int lenth)
{
	int i = 0;
	int j = lenth - 1;

	if(lenth < 2)
		return;

	T tempValue = *(array + i);
	while(i < j){
		for(; j > i; --j){
			if(*(array+j) < tempValue){
				*(array + i) = *(array + j);
				break;
			}
		}

		for(; i < j; ++i){
			if(*(array + i) > tempValue){
				*(array + j) = *(array + i);
				break;
			}
		}
	}

	*(array + i) = tempValue;
	quick_sort(array, i);
	quick_sort(array + i + 1, lenth - i - 1);
}

template<typename T>
void show(const T *array, const int lenth)
{
	for(int i = 0; i < lenth; ++i){
		cout << "**" << *(array + i);
	}
	cout << endl;
}

int main(int argc, char**argv)
{
	int array[10] = {5,6,1,473,523,723451,6251,41327,15312,412};
	quick_sort(array, 10);
	show(array,10);
	return EXIT_SUCCESS;
}
