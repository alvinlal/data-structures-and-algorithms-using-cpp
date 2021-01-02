#include<iostream>
#include<vector>
#include<cmath>
#include<string>

class Node {
public:
	std::string value;
	int priority = NULL;
	Node(std::string value, int priority) :priority(priority), value(value) {}
	Node() {}
};


class PriorityQueue {
public:

	std::vector<Node*> values;

	void enqueue(std::string val, int priority) {
		Node* newNode = new Node(val, priority);
		values.emplace_back(newNode);
		bubbleUp();
	}
	void bubbleUp() {
		int idx = values.size() - 1;
		Node* element = values[idx];

		while (idx > 0) {
			int parentIdx = (int)std::floor((idx - 1) / 2);
			Node* parentElement = values[parentIdx];
			if (element->priority >= parentElement->priority) break;
			values[parentIdx] = element;
			values[idx] = parentElement;
			idx = parentIdx;
		}
	}
	Node dequeue() {
		Node* min = values[0];
		Node* end = values[values.size() - 1];
		values.pop_back();
		if (values.size() > 0) {
			values[0] = end;
			sinkDown();
		}
		return *min;
	}
	void sinkDown() {
		int idx = 0;
		const int length = values.size() - 1;
		Node* element = values[0];
		while (true) {
			int leftChildIdx = 2 * idx + 1;
			int rightChildIdx = 2 * idx + 2;
			int swap = NULL;
			Node leftChild;
			Node rightChild;
			if (leftChildIdx < length) {
				leftChild = *values[leftChildIdx];
				if (leftChild.priority < element->priority) {
					swap = leftChildIdx;
				}
			}
			if (rightChildIdx < length) {
				rightChild = *values[rightChildIdx];
				if ((swap == NULL && rightChild.priority < element->priority) || (swap != NULL && rightChild.priority < leftChild.priority)) {
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
			std::cout << values[i]->value << ", " << values[i]->priority << "\n";
		}
	}
};



//test code

int main() {
	PriorityQueue priority_Queue;
	priority_Queue.enqueue("common cold", 5);
	priority_Queue.enqueue("malaria", 4);
	priority_Queue.enqueue("corona", 3);
	priority_Queue.enqueue("broken arm", 2);
	priority_Queue.enqueue("gunshot wound", 1);
	std::cout << "\nThe priority Queue is now: \n";
	priority_Queue.print();
	Node max = priority_Queue.dequeue();
	std::cout << "\nDequeued " << max.value << " with priority " << max.priority << " from the priority queue";
	max = priority_Queue.dequeue();
	std::cout << "\nDequeued " << max.value << " with priority " << max.priority << " from the priority queue";
	max = priority_Queue.dequeue();
	std::cout << "\nDequeued " << max.value << " with priority " << max.priority << " from the priority queue";
	max = priority_Queue.dequeue();
	std::cout << "\nDequeued " << max.value << " with priority " << max.priority << " from the priority queue";
	max = priority_Queue.dequeue();
	std::cout << "\nDequeued " << max.value << " with priority " << max.priority << " from the priority queue";
}