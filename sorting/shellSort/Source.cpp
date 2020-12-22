#include<iostream>


void swap(int arr[], int idx1, int idx2) {
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

void shellSort(int arr[], int size) {
	for (int gap = size / 2; gap >= 1; gap = gap / 2) {
		for (int j = gap; j < size; j++) {
			for (int i = j - gap; i >= 0; i = i - gap) {
				if (arr[i + gap] < arr[i]) {
					swap(arr, i, i + gap);
				}
				else {
					break;
				}
			}
		}
	}
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
	shellSort(arr, arrSize);
	print(arr, arrSize);
}