#include <iostream>
#include "Array.h"


void insertionSort(Array<int, 7>& arr) {
	size_t j = 0;
	for (size_t i = 1; i < arr.length; i++) {
		int currentValue = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > currentValue; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = currentValue;
	}
}




int main() {
	Array<int, 7> arr = { 7,6,1,4,2,3,5 };
	insertionSort(arr);
	arr.print();
}