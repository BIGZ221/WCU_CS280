/*
	280
	LinkedListReview
	ZFuchs, DChar
*/
#include <iostream>
#include <iomanip>
using namespace std;

struct Node {
	int data;
	Node* next;
};

class LinkedList {
	private:
		Node* top;
		int size;
	public:
		LinkedList();
		void insertVal(int v); //insert integer v in ascending order (from top to bottom) in the linked list.
		bool deleteVal(int v); //delete the first instance of v in the list (from top to bottom) from the list. Return true if v was found, false otherwise.
		void display();

}; 
LinkedList::LinkedList() {
	top = nullptr;
	size = 0;
}

void LinkedList::insertVal(int val) {
	Node* p = new Node;
	p->data = val;
	p->next = nullptr;
	if (size == 0) {
		top = p;
	} else if (size == 1) {
		if (val < top->data) {
			p->next = top;
			top = p;
		} else {
			top->next = p;
		}
	} else {
		if (val < top->data) {
			p->next = top;
			top = p;
			size++;
			return;
		}
		Node* front = top->next;
		Node* rear = top;
		while (front != nullptr) {
			if (val >= rear->data && val < front->data) {
				rear->next = p;
				p->next = front;
				break;
			} else if (front->next == nullptr) {
				front->next = p;
				break;
			}

			rear = front;
			front = rear->next;

		}
	}
	size++;
}

bool LinkedList::deleteVal(int val) {
	Node* runner = top;
	Node* holder;
	if (runner->data == val) {
		delete runner;
		size--; 
		return true;
	}
	while (runner->next != nullptr) {
		if (runner->next->data == val) {
			holder = runner->next->next;
			delete runner->next;
			runner->next = holder;
			size--;
			return true;
		} else {
			runner = runner->next;
		}
	}
	return false;
}

void LinkedList::display(){
	Node* runner = top;
	while (runner != nullptr) {
		cout.width(4);
		cout << runner->data;
		runner = runner->next;
	}
}

int main() {
	LinkedList l1 = LinkedList();
	cout << "Inserting integers 12, -8, 14, 2, 10, -20, 30" << endl;
	l1.insertVal(12);
	l1.insertVal(-8);
	l1.insertVal(14);
	l1.insertVal(2);
	l1.insertVal(10);
	l1.insertVal(-20);
	l1.insertVal(30);
	cout.width(4);
	cout << "Expected:" << endl << " -20  -8   2  10  12  14  30" << endl << "Actual:" << endl;
	l1.display();
	cout << endl << "Deleting 12" << endl;
	cout << "Expected:" << endl << " -20  -8   2  10  14  30" << endl << "Done" << endl << "Actual:" << endl;
	if (l1.deleteVal(12) == true) {
		l1.display();
		cout << endl << "Done" << endl;
	} else {
		l1.display();
		cout << endl << "Fail" << endl;
	}
	cout << "Deleting a 30" << endl;
	cout << "Expected:" << endl << " -20  -8   2  10  14" << endl <<  "Done" << endl << "Actual:" << endl;
	if (l1.deleteVal(30) == true) {
		l1.display();
		cout << endl << "Done" << endl;
	} else {
		l1.display();
		cout << endl << "Fail" << endl;
	}
	cout << "Deleting a 9" << endl;
	cout << "Expected:" << endl << " -20  -8   2  10  14" << endl << "Fail" << endl << "Actual:" << endl;;
	if (l1.deleteVal(9) == true) {
		l1.display();
		cout << endl << "Done" << endl;
	} else {
		l1.display();
		cout << endl << "Fail" << endl;
	}
}
