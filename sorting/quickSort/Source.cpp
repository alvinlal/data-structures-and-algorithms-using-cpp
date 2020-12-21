#include <iostream>

void swap(int arr[], size_t index1, size_t index2) {
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}


int pivot(int arr[], int  start, int end) {
	int swapIdx = start;
	int pivot = arr[start];
	for (int i = start; i <= end; i++) {
		if (arr[i] < pivot) {
			swapIdx++;
			swap(arr, swapIdx, i);
		}
	}
	swap(arr, start, swapIdx);
	return swapIdx;
}

int* quickSort(int arr[], int left, int right) {
	if (left < right) {
		int pivotIndex = pivot(arr, left, right);
		quickSort(arr, left, pivotIndex - 1);
		quickSort(arr, pivotIndex + 1, right);
	}
	return arr;
}

void print(int arr[], int size) {
	std::cout << "[ ";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " , ";
	}
	std::cout << "]";
}

int main() {
	int arr[] = { 7,6,5,4,3,2,1 };
	int arrSize = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, arrSize - 1);
	print(arr, arrSize);
}