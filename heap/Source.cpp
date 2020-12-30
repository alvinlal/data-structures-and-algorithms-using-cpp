#include<iostream>
#include<vector>
#include<cmath>


class MaxBinaryHeap {
public:

	std::vector<int> values;

	void insert(int val) {
		values.push_back(val);
		bubbleUp();
	}
	void bubbleUp() {
		int idx = values.size() - 1;
		int element = values[idx];

		while (idx > 0) {
			int parentIdx = (int)std::floor((idx - 1) / 2);
			int parentElement = values[parentIdx];
			if (element <= parentElement) break;
			values[parentIdx] = element;
			values[idx] = parentElement;
			idx = parentIdx;
		}
	}
	int extractMax() {
		int max = values[0];
		int end = values[values.size() - 1];
		values.pop_back();
		if (values.size() > 0) {
			values[0] = end;
			sinkDown();
		}
		return max;
	}
	void sinkDown() {
		int idx = 0;
		const int length = values.size() - 1;
		const int  element = values[0];
		while (true) {
			int leftChildIdx = 2 * idx + 1;
			int rightChildIdx = 2 * idx + 2;
			int swap = NULL;
			int leftChild, rightChild;
			if (leftChildIdx < length) {
				leftChild = values[leftChildIdx];
				if (leftChild > element) {
					swap = leftChildIdx;
				}
			}
			if (rightChildIdx < length) {
				rightChild = values[rightChildIdx];
				if ((swap == NULL && rightChild > element) || (swap != NULL && rightChild > leftChild)) {
					swap = rightChildIdx;
				}
			}
			if (swap == NULL) break;
			values[idx] = values[swap];
			values[swap] = element;
			idx = swap;
		}
	}
	void print() {
		for (unsigned int i = 0; i < values.size(); i++) {
			std::cout << values[i] << " ";
		}
	}
};



//test code

int main() {
	MaxBinaryHeap heap;
	heap.insert(41);
	heap.insert(39);
	heap.insert(33);
	heap.insert(18);
	heap.insert(27);
	heap.insert(12);
	std::cout << "\nThe heap is now: ";
	heap.print();
	heap.insert(55);
	std::cout << "\nInserted 55, the heap is now: ";
	heap.print();
	int max = heap.extractMax();
	std::cout << "\nExtracted " << max << " from the heap,the heap is now: ";
	heap.print();
	max = heap.extractMax();
	std::cout << "\nExtracted " << max << " from the heap,the heap is now: ";
	heap.print();
	max = heap.extractMax();
	std::cout << "\nExtracted " << max << " from the heap,the heap is now: ";
	heap.print();
	max = heap.extractMax();
	std::cout << "\nExtracted " << max << " from the heap,the heap is now: ";
	heap.print();

}