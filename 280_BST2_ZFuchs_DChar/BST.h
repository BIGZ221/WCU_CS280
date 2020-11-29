#pragma once
using namespace std;
struct Node {
	int data;
	Node* left, * right;
};

class BST {
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
	Node* copy(Node*); //helper
	bool equal(Node*,Node*); //helper
	void clear(Node*); //helper
	int size(Node*); //helper
	int findMax(Node*);//helper
	int findSum(Node*);//helper
	void levelByLevel(Node*);//helper
public:
	BST();
	BST(Node*);
	void insert(int);
	void displayInOrder();
	void displayPreOrder();
	void displayPostOrder();
	int leafCount();
	int height();
	Node* find(int);
	bool remove(int);
	int getSize();
	Node* copy();
	bool equal(BST);
	Node* getRoot();
	void clear();
	int size();
	int findMax();
	int findMin();
	int findSum();
	double findAve();
	void levelByLevel();
};
