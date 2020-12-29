#include<iostream>
#include<queue>


class Node {

public:
	int value;
	Node* left = nullptr;
	Node* right = nullptr;
	Node(int val) :value(val) {}
	void preOrder(Node* node) {
		std::cout << node->value << " ";
		if (node->left != nullptr) preOrder(node->left);
		if (node->right != nullptr) preOrder(node->right);
	}
	void postOrder(Node* node) {
		if (node->left != nullptr) postOrder(node->left);
		if (node->right != nullptr) postOrder(node->right);
		std::cout << node->value << " ";
	}
	void inOrder(Node* node) {
		if (node->left != nullptr) inOrder(node->left);
		std::cout << node->value << " ";
		if (node->right != nullptr) inOrder(node->right);
	}
};

class BinarySearchTree {
public:
	Node* root = nullptr;

	BinarySearchTree& insert(int value) {
		Node* newNode = new Node(value);
		if (!root) {
			root = newNode;
			return *this;
		}
		else {
			Node* current = root;
			while (true) {
				if (value == current->value) return *this;
				if (value < current->value) {
					if (current->left == nullptr) {
						current->left = newNode;
						return *this;
					}
					current = current->left;
				}
				else {
					if (current->right == nullptr) {
						current->right = newNode;
						return *this;
					}
					current = current->right;
				}
			}
		}
	}
	Node* find(int value) {
		if (root == nullptr) return NULL;
		Node* current = root;
		while (true) {
			if (current == nullptr) return NULL;
			if (current->value == value) return current;
			else if (value < current->value) {
				current = current->left;
			}
			else {
				current = current->right;
			}
		}
	}

	void BFS() {
		if (root == nullptr) return;
		std::queue<Node*> que;
		Node* node = root;
		que.push(node);
		while (!que.empty()) {
			node = que.front();
			std::cout << node->value << " ";
			que.pop();
			if (node->left) que.push(node->left);
			if (node->right) que.push(node->right);
		}
	}
	void preOrder() {
		if (root == nullptr) return;
		root->preOrder(root);
	}
	void postOrder() {
		if (root == nullptr) return;
		root->postOrder(root);
	}
	void inOrder() {
		if (root == nullptr) return;
		root->inOrder(root);
	}
};



//test code;
int main() {
	BinarySearchTree tree;
	tree.insert(60);
	tree.insert(30);
	tree.insert(90);
	tree.insert(40);
	tree.insert(35);
	tree.insert(70);
	tree.insert(95);
	Node* test = tree.find(22);
	if (!test) {
		std::cout << "\nCan't find 22 in the tree";
	}
	test = tree.find(40);
	if (test) {
		std::cout << "\nFound " << test->value << " in the tree";
	}
	std::cout << "\nThe breadth first search of the tree is:";
	tree.BFS();
	std::cout << "\nThe inorder traversal of the tree is: ";
	tree.inOrder();
	std::cout << "\nThe postorder traversal of the tree is: ";
	tree.postOrder();
	std::cout << "\nThe preOrder traversal of the tree is: ";
	tree.preOrder();

}