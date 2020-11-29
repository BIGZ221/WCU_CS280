#pragma once
struct Node {
	int data;
	Node *left, *right;
};
class BST1 {
private:
	Node* root;
	Node* insert(int, Node*); //helper
	int getSize(Node*); //helper
	void displayInOrder(Node*); //helper
	void displayPreOrder(Node*); //helper
	void displayPostOrder(Node*); //helper
	int countLeaves(Node*); //helper
	int height(Node*); //helper
	Node* find(int, Node*); //helper
	Node* remove(int, Node*); //helper
	Node* findMin(Node*); //helper
public:
	BST1();
	void insert(int);
	void displayInOrder();
	void displayPreOrder();
	void displayPostOrder();
	int countLeaves();
	int height();
	Node* find(int);
	bool remove(int);//
	int getSize();
};

