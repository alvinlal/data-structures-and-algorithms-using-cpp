#include<iostream>

class Node {
public:
	Node* next = nullptr;
	int val = 0;
	Node(int val) :val(val) {}
};

class SinglyLinkedList {
public:
	Node* head = nullptr;
	Node* tail = nullptr;
	int length = 0;
	SinglyLinkedList& push(int val) {
		Node* newNode = new Node(val);
		if (!head) {
			head = newNode;
			tail = head;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		length++;
		return *this;
	}
	Node pop() {
		if (!head) return NULL;
		Node* current = head;
		Node* newTail = current;
		while (current->next) {
			newTail = current;
			current = current->next;
		}
		newTail->next = nullptr;
		Node temp = *tail;
		delete tail;
		tail = newTail;
		length--;
		if (length == 0) {
			head = nullptr;
			tail = nullptr;
		}
		return temp;
	}
	Node shift() {
		if (!head) return NULL;
		Node* current = head;
		Node temp = *current;
		head = current->next;
		delete current;
		length--;
		if (length == 0) {
			head = nullptr;
			tail = nullptr;
		}
		return temp;
	}
	SinglyLinkedList& unshift(int val) {
		Node* newHead = new Node(val);
		if (!head) {
			head = newHead;
			tail = head;
		}
		else {
			newHead->next = head;
			head = newHead;
		}
		length++;
		return *this;
	}
	Node* get(int index) {
		if (index < 0 || index >= length) { return nullptr; }
		int counter = 0;
		Node* current = head;
		while (counter != index) {
			current = current->next;
			counter++;
		}
		return current;
	}
	bool set(int index, int val) {
		Node* foundNode = get(index);
		if (foundNode) {
			foundNode->val = val;
			return true;
		}
		return false;
	}
	bool insert(int index, int val) {
		if (index <0 || index>length) { return false; }
		if (index == 0) { unshift(val); return true; }
		if (index == length) { push(val); return true; }

		Node* newNode = new Node(val);
		Node* prevNode = get(index - 1);
		Node* temp = prevNode->next;
		prevNode->next = newNode;
		newNode->next = temp;
		length++;
		return true;

	}
	Node remove(int index) {
		if (index < 0 || index >= length) { return NULL; }
		if (index == length - 1) { return pop(); }
		if (index == 0) { return shift(); }

		Node* previousNode = get(index - 1);
		Node* removed = previousNode->next;
		previousNode->next = removed->next;
		length--;
		return *removed;


	}
	void reverse() {
		Node* node = head;
		head = tail;
		tail = node;
		Node* next;
		Node* prev = nullptr;
		for (int i = 0; i < length; i++) {
			next = node->next;
			node->next = prev;
			prev = node;
			node = next;
		}
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
	SinglyLinkedList list;
	list.push(12);
	list.push(13);
	list.push(14);
	list.push(15);
	list.push(16);
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
	temp = list.shift();
	std::cout << "\nshifted " << temp.val << " from the list\n";
	std::cout << "The list is now: ";
	list.traverse();
	temp = list.shift();
	std::cout << "\nshifted " << temp.val << " from the list\n";
	std::cout << "The list is now: ";
	list.traverse();
	SinglyLinkedList temp2 = list.unshift(77);
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
	temp = list.pop();
	std::cout << "\npoped " << temp.val << " from the list\n";
	std::cout << "The list is now: ";
	list.traverse();
	temp = list.shift();
	std::cout << "\nshifted " << temp.val << " from the list\n";
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
	temp2 = list.unshift(78);
	std::cout << "\nunshifted " << temp2.head->val << " to the list\n";
	std::cout << "The list is now: ";
	list.traverse();
	temp2 = list.unshift(79);
	std::cout << "\nunshifted " << temp2.head->val << " to the list\n";
	std::cout << "The list is now: ";
	list.traverse();
	temp2 = list.push(22);
	std::cout << "\npushed " << temp2.tail->val << " to the list\n";
	std::cout << "The list is now: ";
	list.traverse();
	temp2 = list.push(34);
	std::cout << "\npushed " << temp2.tail->val << " to the list\n";
	std::cout << "The list is now: ";
	list.traverse();
	std::cout << "\nThe element at index 0 is " << list.get(0)->val;
	temp = list.shift();
	std::cout << "\nshifted " << temp.val << " from the list\n";
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
	temp = list.remove(0);
	std::cout << "\nremoved element " << temp.val << " from index 0";
	std::cout << "\nThe list is now: ";
	list.traverse();
	temp = list.remove(list.length - 1);
	std::cout << "\nremoved element " << temp.val << " from  last index";
	std::cout << "\nThe list is now: ";
	list.traverse();
	temp = list.remove(3);
	std::cout << "\nremoved element " << temp.val << " from index 3";
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
	std::cout << "\nInvalid indexhave been swapped";
	std::cout << "\nThe list is now: ";
	list.traverse();


}