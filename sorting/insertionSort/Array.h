#pragma once
#include<iostream>

template<typename T, size_t size>
class Array {
public:
	T array[size];
	size_t length = size;
	T temp;
	T& operator[](size_t index) { return array[index]; }
	const T& operator[]  (size_t index)const { return array[index]; }
	void swap(size_t index1, size_t index2) {
		temp = array[index1];
		array[index1] = array[index2];
		array[index2] = temp;
	}
	void print() {
		std::cout << "[ ";
		for (int i = 0; i < size; i++) {
			std::cout << array[i] << " , ";
		}
		std::cout << "]";
	}

};
