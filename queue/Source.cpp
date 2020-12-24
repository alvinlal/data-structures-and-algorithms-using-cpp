#include<iostream>

class Node {
public:
	int val;
	Node* next = nullptr;
	Node(int val) :val(val) {}
};

class Queue {
public:
	int size = 0;
	Node* first = nullptr;
	Node* last = nullptr;

	int enqueue(int val) {
		Node* newNode = new Node(val);
		if (!first) {
			first = newNode;
			last = newNode;
		}
		else {
			last->next = newNode;
			last = newNode;
		}
		return ++size;
	}

	int dequeue() {
		if (!first) return NULL;
		Node* dequeuedNode = first;
		if (first == last) {
			last = nullptr;
		}
		first = first->next;
		size--;
		return dequeuedNode->val;

	}
	void traverse() {
		Node* currentNode = first;
		std::cout << "[ ";
		while (currentNode) {
			std::cout << currentNode->val << ", ";
			currentNode = currentNode->next;
		}
		std::cout << "]";

	}
};


int main() {
	Queue queue;
	queue.enqueue(1);
	queue.enqueue(2);
	queue.enqueue(3);
	queue.enqueue(4);
	queue.enqueue(5);
	std::cout << "\nThe queue is now: ";
	queue.traverse();
	int val = queue.dequeue();
	std::cout << "\nDequeued " << val << " from the queue";
	std::cout << "\nThe queue is now: ";
	queue.traverse();
	val = queue.dequeue();
	std::cout << "\nDequeued " << val << " from the queue";
	std::cout << "\nThe queue is now: ";
	queue.traverse();
	val = queue.dequeue();
	std::cout << "\nDequeued " << val << " from the queue";
	std::cout << "\nThe queue is now: ";
	queue.traverse();
	val = queue.dequeue();
	std::cout << "\nDequeued " << val << " from the queue";
	std::cout << "\nThe queue is now: ";
	queue.traverse();
	val = queue.dequeue();
	std::cout << "\nDequeued " << val << " from the queue";
	std::cout << "\nThe queue is now: ";
	queue.traverse();
}