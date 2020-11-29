#include "BST1.h"
#include <iostream>
#include <iomanip>
using namespace std;
//helper functions
Node* BST1::insert(int v, Node* r) {
	if (r == nullptr) {
		r = new Node;
		r->left = r->right = nullptr;
		r->data = v;
		return r;
	} else if (v <= r->data) {
		r->left = insert(v, r->left);
		return r;
	} else {
		r->right = insert(v, r->right);
		return r;
	}
} //insert helper

void BST1::displayInOrder(Node* r) {
	if (r != nullptr) {
		displayInOrder(r->left);
		cout.width(4); cout << right << r->data;
		displayInOrder(r->right);
	}
} //displayInOrder helper

void BST1::displayPreOrder(Node* root) {
	if (root != nullptr) {
		cout.width(4); cout << right << root->data;
		displayPreOrder(root->left);
		displayPreOrder(root->right);
	}
} //displayPreOrder helper

void BST1::displayPostOrder(Node* root) {
	if(root != nullptr){
		displayPostOrder(root->left);
		displayPostOrder(root->right);
		cout.width(4); cout << root->data;
	}
} //displayPostOrder helper

int BST1::getSize(Node* r) {
	if (r == nullptr)
		return 0;
	else
		return 1 + getSize(r->left) + getSize(r->right);
} //getSize helper

int BST1::countLeaves(Node* root) {

	if(root==nullptr){
		return 0; 
	} else if(root->left == nullptr && root->right == nullptr){
		return 1; 
	}else{
		return countLeaves(root->left) + countLeaves(root->right); 
	}
}

int BST1::height(Node* root) {
	if (root==nullptr) {
		return 0; 
	} else {
		int rightHeight = height(root->right);
		int leftHeight = height(root->left);
		if (rightHeight > leftHeight) {
			return 1 + rightHeight;
		} else {
			return 1 + leftHeight; 
		}
	}
}

Node* BST1::find(int val, Node* root) {
	if (root != nullptr) {
		if (root->data == val) {
			return root;
		} else {
			if (root->data >= val) {
				find(val, root->left);
			} else {
				find(val, root->right);
			}
		}
	} else {
		return nullptr;
	}
}

Node* BST1::findMin(Node* root) {
	while (root->left != nullptr) {
		root = root->left;
	}
	return root;
}

Node* BST1::remove(int val, Node* root) {
	if (root == nullptr) {
		return nullptr;
	}
	if (val < root->data) {
		root->left = remove(val, root->left);
	} else if (val > root->data) {
		root->right = remove(val, root->right);
	} else {
		if (root->left == nullptr && root->right == nullptr) {
			delete root;
			root = nullptr;
		}
		else if (root->left == nullptr) {
			Node* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == nullptr) {
			Node* temp = root;
			root = root->left;
			delete temp;
		}
		else {
			Node* temp = findMin(root->right);
			root->data = temp->data;
			root->right = remove(temp->data,root->right);
		}
	}
		return root;
}

//constructors
BST1::BST1() {
	root = nullptr;
} //BST

//setters
void BST1::insert(int v) {
	root = insert(v, root);
} //insert

//getters
int BST1::getSize() {
	return getSize(root);
} //getSize

int BST1::height() {
	return height(root);
} //height

Node* BST1::find(int val) {
	Node* p = find(val, root);
	if (p != nullptr) {
		cout << "found, value is " << val << endl;
	} else {
		cout << "not found" << endl;
	}
	return p;
} //find

bool BST1::remove(int val) {
	if (find(val,root) == nullptr) {
		cout << "Did not delete " << val << endl; 
		return false;
	} else {
		bool p = remove(val,root);
		if(p){
			displayInOrder(); 
			cout << endl; 
		}
		return p;
	}
} //remove/delete

int BST1::countLeaves() {
	return countLeaves(root);
}

//utility
void BST1::displayInOrder() {
	displayInOrder(root);
} //displayInOrder

void BST1::displayPreOrder() {
	displayPreOrder(root);
} //displayPreOrder

void BST1::displayPostOrder() {
	displayPostOrder(root);
} //displayPostOrder