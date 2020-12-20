#include<iostream>
#include"Array.h"

void bubbleSort(Array<int, 7>& arr) {
	for (size_t i = arr.length; i > 0; i--) {
		bool noSwaps = true;
		for (size_t j = 0; j < i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				arr.swap(j, j + 1);
				noSwaps = false;
			}
		}
		if (noSwaps) break;
	}
}


int main() {

	Array<int, 7> arr = { 7,1,6,2,5,4,3 };
	bubbleSort(arr);
	arr.print();
}
