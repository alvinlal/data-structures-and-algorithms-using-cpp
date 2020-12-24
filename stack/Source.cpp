#include<iostream>


class Node {
public:
	int val;
	Node* next = nullptr;
	Node(int val) :val(val) {}
};

class Stack {
public:
	Node* first = nullptr;
	Node* last = nullptr;
	int size = 0;

	int push(int val) {
		Node* newNode = new Node(val);
		if (!first) {
			first = newNode;
			last = newNode;
		}
		else {
			newNode->next = first;
			first = newNode;
		}
		return ++size;
	}
	int pop() {
		if (!first) return NULL;
		Node* popedNode = first;
		if (first == last) {
			last = nullptr;
		}
		first = first->next;
		size--;
		return popedNode->val;
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

//test code
int main() {
	Stack stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	std::cout << "\nThe stack is now: ";
	stack.traverse();
	int popedValue = stack.pop();
	std::cout << "\npoped value " << popedValue << " from stack";
	std::cout << "\nThe stack is now: ";
	stack.traverse();
	popedValue = stack.pop();
	std::cout << "\npoped value " << popedValue << " from stack";
	std::cout << "\nThe stack is now: ";
	stack.traverse();
	popedValue = stack.pop();
	std::cout << "\npoped value " << popedValue << " from stack";
	std::cout << "\nThe stack is now: ";
	stack.traverse();
	popedValue = stack.pop();
	std::cout << "\npoped value " << popedValue << " from stack";
	std::cout << "\nThe stack is now: ";
	stack.traverse();
	popedValue = stack.pop();
	std::cout << "\npoped value " << popedValue << " from stack";
	std::cout << "\nThe stack is now: ";
	stack.traverse();
}