#pragma once
#include <iostream>
#include <ctime> 

using namespace std;

template<class T>
struct Node {
	T data;
	Node<T>* next = nullptr;
};

template<class T>
class Queue {
private:
	Node<T>* top, * rear;
	int size;
public:
	Queue<T>();
	void append(T);
	T serve();
	int getSize();
	bool isEmpty();
	void displayFR();
	void displayRF(Node<T>*);
	void displayRF();
};

template<class T>
Queue<T>::Queue() {
	top = rear = nullptr;
	size = 0;
}

template<class T>
void Queue<T>::append(T val) {
	Node<T>* p = new Node<T>;
	p->data = val;
	p->next = nullptr;
	if (size == 0) {
		top = p;
		p->next = rear;
		rear = p;
	} else {
		rear->next = p;
		rear = p;
	}
	size++;
}

template<class T>
T Queue<T>::serve() {
	Node<T>* p = top;
	T holder = p->data;
	top = top->next;
	size--;
	delete p;
	return holder;
}

template<class T>
int Queue<T>::getSize() {
	return size;
}

template<class T>
bool Queue<T>::isEmpty() {
	return size == 0;
}

template<class T>
void Queue<T>::displayFR() {
	Node<T>* runner = top;
	while (runner != nullptr) {
		cout << runner->data << " ";
		runner = runner->next;
	}
}

template<class T>
void Queue<T>::displayRF() {
	displayRF(top);
}

template<class T>
void Queue<T>::displayRF(Node<T>* hold) {
	Node<T>* runner = hold;
	if (runner != nullptr) {
		displayRF(runner->next);
		cout << runner->data << " ";
	}
}