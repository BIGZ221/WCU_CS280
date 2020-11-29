#include "Concordance.h"
#include <iostream>
#include <fstream>
using namespace std;

Concordance::Concordance() {
	top = nullptr;
}

void Concordance::loadConcordance(string filename) {
	string holder;
	fstream ifile(filename);
	while (!ifile.eof()) {
		ifile >> holder;
		append(holder);
	}
	ifile.close();
}

void Concordance::append(string oStr) {
	for (int i = 0; i < oStr.size(); i++) {
		char n = oStr[i];
		oStr[i] = tolower(n);
	}
	string str = oStr;
	char firstLetter = str[0];
	if (top == nullptr) {
		CharNode* temp = new CharNode;
		temp->data = firstLetter;
		temp->words.appendWord(str);
		top = temp;
	} else if (firstLetter < top->data) {
		CharNode* temp = new CharNode;
		temp->data = firstLetter;
		temp->words.appendWord(str);
		temp->next = top;
		top->prev = temp;
		top = temp;
	} else {
		CharNode* runner = top;
		while (firstLetter > runner->data && runner->next != nullptr) {
			runner = runner->next;
		}
		if (firstLetter==runner->data){
			runner->words.appendWord(str);
		}
		else if (firstLetter > runner->data) {
			CharNode* temp = new CharNode;
			temp->data = firstLetter;
			temp->words.appendWord(str);
			temp->next = runner->next;
			temp->prev = runner;
			runner->next = temp;
		} else {
			CharNode* temp = new CharNode;
			temp->data = firstLetter;
			temp->words.appendWord(str);
			runner->prev->next = temp;
			temp->prev = runner->prev;
			temp->next = runner;
			runner->prev = temp;
		}
	}
}

void Concordance::displayLetter(char target){
	CharNode* runner = top;
	while (runner->next!=nullptr && runner->data < target){
		runner = runner->next;
	}
	if (runner->data == target) {
		runner->words.displayWords();
		cout << endl;
	} else {
		cout << target << " does not exist." << endl;
	}
}

void Concordance::searchWord(string target){
	char trg = target[0];
	trg = tolower(trg);
	CharNode* runner = top;
	while (runner->next != nullptr && runner->data < trg){
		runner = runner->next;
	}
	if (runner->data==trg){
		cout << runner->words.searchWords(target) << " exists." << endl;
	} else {
		cout << target << " does not exist." << endl;
	}
}

void Concordance::displayConcordance() {
	CharNode* runner = top;
	while (runner!=nullptr) {
		cout << char(toupper(runner->data)) << ". ";
		runner->words.displayWords();
		cout << endl;
		runner = runner->next;
	}
}