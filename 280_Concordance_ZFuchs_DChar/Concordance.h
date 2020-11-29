#pragma once
#include "WordList.h"
#include <iostream>
using namespace std;
struct CharNode {
	CharNode* next = nullptr,* prev = nullptr;
	char data;
	WordList words;
};

class Concordance {
private:
	CharNode* top;
public:
	Concordance();
	void loadConcordance(string); //load the concordance reading from the file
	void append(string); //adding a single string to the concordance
	void displayConcordance();
	void displayLetter(char);
	void searchWord(string);
};