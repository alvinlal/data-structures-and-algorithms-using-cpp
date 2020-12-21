#include <iostream>
#include <vector>

void merge(int arr[], int l, int mid, int r) {
	std::vector<int> b;
	b.resize(r + 1);
	int i = l;
	int j = mid + 1;
	int k = l;

	while (i <= mid && j <= r) {
		if (arr[i] <= arr[j]) {
			b[k] = arr[i];
			i++;
		}
		else {
			b[k] = arr[j];
			j++;
		}
		k++;
	}

	while (i <= mid) {
		b[k] = arr[i];
		i++;
		k++;
	}
	while (j <= r) {
		b[k] = arr[j];
		j++;
		k++;
	}
	for (int k = l; k <= r; k++) {
		arr[k] = b[k];
	}
}


void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		int mid = (l + r) / 2;
		mergeSort(arr, 0, mid);
		mergeSort(arr, mid + 1, r);
		merge(arr, l, mid, r);
	}
}

void print(int arr[], int size) {
	std::cout << "[ ";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << ", ";
	}
	std::cout << "]";
}

int main() {
	int arr[] = { 7,6,5,4,3,2,1 };
	int arrSize = sizeof(arr) / sizeof(arr[0]);
	mergeSort(arr, 0, arrSize - 1);
	print(arr, arrSize);
}