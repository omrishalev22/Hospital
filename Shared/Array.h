#include "./consts.h"

#ifndef __ARRAY_H
#define __ARRAY_H


template<class T>
class Array
{
	int physicalSize, logicalSize;
	char delimiter;
	T* arr;
public:
	Array(int size = AMOUNT_OF_STARTED_ITEMS, char delimiter = ' ');
	Array(const Array& other);
	int getSize();
	~Array();

	const Array& operator=(const Array& other);
	const Array& operator+=(const T& newVal);
	T operator[](const int index);

};


template<class T>
Array<T>::Array(int maxSize, char delimiter)
	: physicalSize(maxSize), logicalSize(0), delimiter(delimiter)
{
	arr = new T[physicalSize];
}

template<class T>
Array<T>::Array(const Array& other) : arr(NULL)
{
	*this = other;
}


template<class T>
int Array<T>::getSize()
{
	return this->logicalSize;
}

template<class T>
Array<T>::~Array()
{
	delete[]arr;
}


template<class T>
const Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		delete[]arr;
		physicalSize = other.physicalSize;
		logicalSize = other.logicalSize;
		delimiter = other.delimiter;
		arr = new T[physicalSize];
		for (int i = 0; i < logicalSize; i++)
			arr[i] = other.arr[i];
	}
	return *this;
}

template<class T>
const Array<T>& Array<T>::operator+=(const T& newVal)
{
	if (logicalSize < physicalSize)
	{
		arr[logicalSize++] = newVal;
	}
	else
	{
		this-> physicalSize = this-> logicalSize * 2;
		T* tmp = new T[physicalSize];

		for (int i = 0; i <= logicalSize; i++) {
			tmp[i] = arr[i];
		}
		arr = tmp;
	}
	return *this;
}

template<class T>
T Array<T>::operator[](const int index)
{
	return this->arr[index];
}


#endif //__ARRAY_H
