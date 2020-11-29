#include "BST.h"
#include <iostream>
#include <iomanip>
#include <queue>
#include <cmath>
using namespace std;

//helper functions
Node* BST::insert(int v, Node* r) {
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

void BST::displayInOrder(Node* r) {
	if (r != nullptr) {
		displayInOrder(r->left);
		cout.width(4); cout << right << r->data;
		displayInOrder(r->right);
	}
} //displayInOrder helper

void BST::displayPreOrder(Node* root) {
	if (root != nullptr) {
		cout.width(4); cout << right << root->data;
		displayPreOrder(root->left);
		displayPreOrder(root->right);
	}
} //displayPreOrder helper

void BST::displayPostOrder(Node* root) {
	if (root != nullptr) {
		displayPostOrder(root->left);
		displayPostOrder(root->right);
		cout.width(4); cout << root->data;
	}
} //displayPostOrder helper

int BST::getSize(Node* r) {
	if (r == nullptr)
		return 0;
	else
		return 1 + getSize(r->left) + getSize(r->right);
} //getSize helper

int BST::countLeaves(Node* root) {

	if (root == nullptr) {
		return 0;
	} else if (root->left == nullptr && root->right == nullptr) {
		return 1;
	} else {
		return countLeaves(root->left) + countLeaves(root->right);
	}
}

int BST::height(Node* root) {
	if (root == nullptr) {
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

Node* BST::find(int val, Node* root) {
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

Node* BST::findMin(Node* root) {
	if (root != nullptr) {
		while (root->left != nullptr) {
			root = root->left;
		}
		return root;
	}
	return nullptr;
}

Node* BST::remove(int val, Node* root) {
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
		} else if (root->left == nullptr) {
			Node* temp = root;
			root = root->right;
			delete temp;
		} else if (root->right == nullptr) {
			Node* temp = root;
			root = root->left;
			delete temp;
		} else {
			Node* temp = findMin(root->right);
			root->data = temp->data;
			root->right = remove(temp->data, root->right);
		}
	}
	return root;
}

Node* BST::copy(Node* root) { //VLR
	Node* nodeCopy = new Node();
	if (root != nullptr) {
		nodeCopy->data = root->data;
		nodeCopy->left = copy(root->left);
		nodeCopy->right = copy(root->right);
		return nodeCopy;
	}
	return nullptr;
}

bool BST::equal(Node* root, Node* checkNode) {
	if (root != nullptr && checkNode != nullptr) {
		equal(root->left, checkNode->left);
		equal(root->right, checkNode->right);
		if (root->data == checkNode->data) {
			return true;
		}
	}
	return false;
}

void BST::clear(Node* root) {
	if (root != nullptr) {
		clear(root->left);
		clear(root->right);
		delete root;
	}
}

int BST::size(Node* root) {
	if (root != nullptr) {
		return 1 + size(root->left) + size(root->right);
	}
	return 0;
}

int BST::findMax(Node* root) {
	if (root != nullptr) {
		while (root->right != nullptr) {
			root = root->right;
		}
		return root->data;
	}
	return NULL;
}

int BST::findSum(Node* root) {
	if (root != nullptr) {
		return root->data + findSum(root->left)+findSum(root->right);
	}
	return 0;
}

void BST::levelByLevel(Node* root) {
	if (root != nullptr) {
		queue<Node*> queue;
		queue.push(root);
		while (!queue.empty()) {
			Node* node = queue.front();
			queue.pop();
			cout << node->data << " ";
			if (node->left != nullptr) {
				queue.push(node->left);
			}
			if (node->right != nullptr) {
				queue.push(node->right);
			}
			
		}
	}
}

//constructors
BST::BST() {
	root = nullptr;
} //BST

BST::BST(Node* nodeC) {
	root = nodeC;
}

//setters
void BST::insert(int v) {
	root = insert(v, root);
} //insert

//getters
int BST::getSize() {
	return getSize(root);
} //getSize

int BST::height() {
	return height(root);
} //height

Node* BST::find(int val) {
	Node* p = find(val, root);
	if (p != nullptr) {
		cout << "found, value is " << val << endl;
	} else {
		cout << "not found" << endl;
	}
	return p;
} //find

bool BST::remove(int val) {
	if (find(val, root) == nullptr) {
		cout << "Did not delete " << val << endl;
		return false;
	} else {
		bool p = remove(val, root);
		if (p) {
			displayInOrder();
			cout << endl;
		}
		return p;
	}
} //remove/delete

int BST::leafCount() {
	return countLeaves(root);
}

//utility
void BST::displayInOrder() {
	displayInOrder(root);
} //displayInOrder

void BST::displayPreOrder() {
	displayPreOrder(root);
} //displayPreOrder

void BST::displayPostOrder() {
	displayPostOrder(root);
} //displayPostOrder

Node* BST::copy() {
	return copy(root);
}

Node* BST::getRoot() {
	return root;
}

bool BST::equal(BST bst) {
	Node* checkNode = bst.getRoot();
	return equal(root, checkNode);
}

void BST::clear() {
		clear(root);
		root = nullptr;
}

int BST::size() {
	return size(root);
}

int BST::findMax() {
	return findMax(root);
}

int BST::findMin() {
	if (root != nullptr) {
		return findMin(root)->data;
	}
	return NULL;
}

int BST::findSum() {
	return findSum(root);
}

double BST::findAve() {
	if (abs(findSum(root)) > 0 && 0 < abs(size(root))) {
		return ((double)findSum(root) / size(root));
	}
	return 0;
}

void BST::levelByLevel() {
	levelByLevel(root);
}