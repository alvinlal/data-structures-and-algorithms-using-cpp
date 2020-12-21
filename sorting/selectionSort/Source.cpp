#include<iostream>
#include"Array.h"


void selectionSort(Array<int, 7>& arr) {
	size_t j = 0;
	for (size_t i = 0; i < arr.length - 1; i++) {
		int lowest = i;
		for (j = i + 1; j < arr.length; j++) {
			if (arr[j] < arr[lowest]) {
				lowest = j;
			}
		}
		if (lowest != i) {
			arr.swap(i, lowest);
		}
	}
}



int main() {
	Array<int, 7> arr = { 7,1,5,2,3,4,6 };
	selectionSort(arr);
	arr.print();
}