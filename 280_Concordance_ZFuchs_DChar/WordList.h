#pragma once
#include <iostream>
using namespace std;
struct WordNode {
	string data;
	WordNode* next = nullptr, * prev = nullptr;
};

class WordList {
private:
	WordNode* top;
public:
	WordList();
	void appendWord(string);
	string searchWords(string);
	void displayWords();
};
