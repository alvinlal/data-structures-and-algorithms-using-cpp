#include<iostream>


class Node {
public:
	int val;
	Node* next = nullptr;
	Node* prev = nullptr;
	Node(int val) : val(val) {}
};

class DoublyLinkedList {
public:
	int length = 0;
	Node* head = nullptr;
	Node* tail = nullptr;

	DoublyLinkedList& push(int val) {
		Node* newNode = new Node(val);
		if (!head) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
		length++;
		return *this;
	}
	Node pop() {
		if (!head)  return NULL;
		Node* popedNode = tail;
		Node returnNode = *tail;

		if (length == 1) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			tail = tail->prev;
			tail->next = nullptr;
			popedNode->prev = nullptr;
		}
		length--;
		delete popedNode;
		return returnNode;
	}
	Node shift() {
		if (!head)  return NULL;
		Node* popedNode = head;
		Node returnNode = *head;
		if (length == 1) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			head = popedNode->next;
			head->prev = nullptr;
			popedNode->next = nullptr;
		}
		length--;
		delete popedNode;
		return returnNode;
	}
	DoublyLinkedList& unshift(int val) {
		Node* newNode = new Node(val);
		if (!head) {
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
		length++;
		return *this;
	}
	Node* get(int index) {
		if (index < 0 || index >= length)  return NULL;
		Node* currentNode;
		int counter;
		if (index <= length / 2) {
			currentNode = head;
			counter = 0;
			while (counter != index) {
				currentNode = currentNode->next;
				counter++;
			}
		}
		else {
			currentNode = tail;
			counter = length - 1;
			while (counter != index) {
				currentNode = currentNode->prev;
				counter--;
			}
		}
		return currentNode;
	}
	bool set(int index, int val) {
		if (index < 0 || index >= length)  return false;
		Node* foundNode = get(index);
		if (foundNode) {
			foundNode->val = val;
			return true;
		}
		return false;
	}
	bool insert(int index, int val) {
		if (index<0 || index>length)  return false;
		if (index == 0)  unshift(val); return true;
		if (index == length)  push(val); return true;

		Node* newNode = new Node(val);
		Node* prevNode = get(index - 1);
		Node* nextNode = prevNode->next;

		prevNode->next = newNode;
		newNode->prev = prevNode;
		newNode->next = nextNode;
		nextNode->prev = newNode;

		length++;
		return true;
	}
	Node remove(int index) {
		if (index < 0 || index >= length) return NULL;
		if (index == 0) return shift();
		if (index == length - 1) return pop();

		Node* removedNode = get(index);
		Node* prevNode = removedNode->prev;
		Node* nextNode = removedNode->next;

		prevNode->next = nextNode;
		nextNode->prev = prevNode;

		removedNode->next = nullptr;
		removedNode->prev = nullptr;

		length--;
		return *removedNode;
	}
	bool reverse() {
		if (!head) return false;
		Node* currentNode = head;
		Node* nextNode;
		while (currentNode) {
			nextNode = currentNode->next;
			currentNode->next = currentNode->prev;
			currentNode->prev = nextNode;
			currentNode = nextNode;
		}
		currentNode = head;
		head = tail;
		tail = currentNode;
		return true;
	}
	bool swap(int index1, int index2) {
		if (index1 == index2) { return true; }
		if (index1 < 0 || index2 < 0 || index1 >= length || index2 >= length) { return false; }
		if (!head) { return false; }

		Node* firstNode = get(index1);
		Node* secondNode = get(index2);
		int temp = firstNode->val;
		firstNode->val = secondNode->val;
		secondNode->val = temp;
		return true;

	}
	void traverse() {
		Node* current = head;
		while (current) {
			std::cout << current->val << " -> ";
			current = current->next;
		}
		std::cout << "NULL";
	}
};

//test code

int main() {
	DoublyLinkedList list;
	list.push(1);
	list.push(2);
	list.push(3);
	list.push(4);
	std::cout << "The list is now: ";
	list.traverse();
	Node temp = list.pop();
	std::cout << "\npoped " << temp.val << " from the list\n";
	std::cout << "The list is now: ";
	list.traverse();
	temp = list.pop();
	std::cout << "\npoped " << temp.val << " from the list\n";
	std::cout << "The list is now: ";
	list.traverse();
	temp = list.pop();
	std::cout << "\npoped " << temp.val << " from the list\n";
	std::cout << "The list is now: ";
	list.traverse();
	temp = list.pop();
	std::cout << "\npoped " << temp.val << " from the list\n";
	std::cout << "The list is now: ";
	list.traverse();
	list.push(1);
	list.push(2);
	list.push(3);
	list.push(4);
	std::cout << "\nThe list is now: ";
	list.traverse();
	temp = list.shift();
	std::cout << "\nshifted " << temp.val << " from the list\n";
	std::cout << "The list is now: ";
	list.traverse();
	temp = list.shift();
	std::cout << "\nshifted " << temp.val << " from the list\n";
	std::cout << "The list is now: ";
	list.traverse();
	temp = list.shift();
	std::cout << "\nshifted " << temp.val << " from the list\n";
	std::cout << "The list is now: ";
	list.traverse();
	temp = list.shift();
	std::cout << "\nshifted " << temp.val << " from the list\n";
	std::cout << "The list is now: ";
	list.traverse();
	list.push(1);
	list.push(2);
	list.push(3);
	list.push(4);
	std::cout << "\nThe list is now: ";
	list.traverse();
	DoublyLinkedList temp2 = list.unshift(77);
	std::cout << "\nunshifted " << temp2.head->val << " to the list\n";
	std::cout << "The list is now: ";
	list.traverse();
	temp2 = list.unshift(78);
	std::cout << "\nunshifted " << temp2.head->val << " to the list\n";
	std::cout << "The list is now: ";
	list.traverse();
	temp2 = list.unshift(79);
	std::cout << "\nunshifted " << temp2.head->val << " to the list\n";
	std::cout << "The list is now: ";
	list.traverse();
	std::cout << "\nThe element at index 0 is " << list.get(0)->val;
	std::cout << "\nThe element at index 1 is " << list.get(1)->val;
	std::cout << "\nThe element at index 2 is " << list.get(2)->val;
	bool value = list.set(0, 999);
	if (value) {
		std::cout << "\nupadated element at index 0 to 999";
	}
	std::cout << "\nThe list is now: ";
	list.traverse();
	value = list.set(9, 222);
	if (value) {
		std::cout << "\nupadated element at index 9 to 222";
		std::cout << "\nThe list is now: ";
		list.traverse();
	}
	list.insert(0, 444);
	std::cout << "\ninserted element to index 0 the value 444";
	std::cout << "\nThe list is now: ";
	list.traverse();
	list.insert(list.length + 1, 444);
	std::cout << "\ninserted element to invalid index the value 444";
	std::cout << "\nThe list is now: ";
	list.traverse();
	list.insert(list.length, 4344);
	std::cout << "\ninserted element to last index the value 4344";
	std::cout << "\nThe list is now: ";
	list.traverse();
	list.insert(2, 333);
	std::cout << "\ninserted element to index 2 the value 333";
	std::cout << "\nThe list is now: ";
	list.traverse();
	list.pop();
	list.pop();
	list.pop();
	std::cout << "\nThe list is now: ";
	list.traverse();
	temp = list.remove(0);
	std::cout << "\nremoved element " << temp.val << " from index 0";
	std::cout << "\nThe list is now: ";
	list.traverse();
	temp = list.remove(list.length - 1);
	std::cout << "\nremoved element " << temp.val << " from  last index";
	std::cout << "\nThe list is now: ";
	list.traverse();
	list.remove(-1);
	std::cout << "\nremoved element from invalid position";
	std::cout << "\nThe list is now: ";
	list.traverse();
	list.reverse();
	std::cout << "\nThe list has been reversed";
	std::cout << "\nThe list is now: ";
	list.traverse();
	list.swap(1, 2);
	std::cout << "\nIndex 1 and 2 have been swapped";
	std::cout << "\nThe list is now: ";
	list.traverse();
	list.swap(7, 7);
	std::cout << "\nInvalid index have been swapped";
	std::cout << "\nThe list is now: ";
	list.traverse();
}