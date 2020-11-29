#include "WordList.h"
#include <iostream>
#include <string>

WordList::WordList() {
	top = nullptr;
}

void WordList::appendWord(string oStr) {
	for (int i = 0; i < oStr.size(); i++) {
		char n = oStr[i];
		oStr[i] = tolower(n);
	}
	string str = oStr;
	if (top == nullptr) {
		WordNode* temp = new WordNode;
		temp->data = str;
		top = temp;
	}
	else if (str < top->data) {
		WordNode* temp = new WordNode;
		temp->data = str;
		temp->next = top;
		top->prev = temp;
		top = temp;
	}
	else {
		WordNode* runner = top;
		while (str > runner->data && runner->next != nullptr) {
			runner = runner->next;
		}
		if (str == runner->data) {
		}
		else if (str > runner->data) {
			WordNode* temp = new WordNode;
			temp->data = str;
			temp->next = runner->next;
			temp->prev = runner;
			runner->next = temp;
		}
		else {
			WordNode* temp = new WordNode;
			temp->data = str;
			runner->prev->next = temp;
			temp->prev = runner->prev;
			temp->next = runner;
			runner->prev = temp;
		}
	}
}

string WordList::searchWords(string str) {
	WordNode* runner = top;
	while (runner->data != str && runner->next != nullptr) {
		runner = runner->next;
	}
	if (runner->data == str) {
		return str;
	} else {
		return "Word was not found.";
	}
}

void WordList::displayWords() {
	WordNode* runner = top;
	while (runner != nullptr) {
		cout << runner->data << " ";
		runner = runner->next;
	}
}