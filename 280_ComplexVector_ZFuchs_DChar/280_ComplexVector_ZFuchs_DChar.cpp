/*
	280
	ComplexVector
	ZFuchs, DChar
*/

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "Complex.h"
using namespace std;

void push(vector<Complex> &cV,double rPart, double iPart) {
	Complex temp = Complex(rPart, iPart);
	cV.push_back(temp);
}

void pop(vector<Complex> cV) {
	cV.back().display();
	cV.pop_back();
}

void at(vector<Complex> cV, int pos) {
	cV[pos].display(); 
}

void back(vector<Complex> cV) {
	cV.back().display();
}

void front(vector<Complex> cV) {
	cV.front().display();
}

void insert(vector<Complex> &cV, int pos, double rPart, double iPart) {
	Complex temp = Complex(rPart, iPart);
	cV.insert(cV.begin()+pos,temp); 
}

void erase(vector<Complex> &cV, int pos) {
	cV.erase(cV.begin() + pos);
}

void erase(vector<Complex> &cV, int posStart, int posStop) {
	cV.erase(cV.begin() + posStart, cV.begin()+posStop);
}

Complex addFriend(vector<Complex> &cV, int pos1, int pos2) {
	return add(cV[pos1], cV[pos2]);
}

Complex add(vector<Complex> &cV,int pos1,int pos2) {
	return (cV[pos1] + cV[pos2]);
}

void display(vector<Complex> cV) {
	for (int i = 0; i < cV.size(); i++) {
		cV[i].display();
	}
}

void disect(string str, int &cPart1, int &cPart2, int &cPart3) {
	int posFirst = str.find(" ");
	int posMiddle = str.find(" ", posFirst + 1);
	int posLast = str.rfind(" ");
	cPart1 = stoi(str.substr(posFirst + 1, str.length()-posFirst));
    cPart2 = stoi(str.substr(posMiddle + 1, posLast - posMiddle + 2));//dont touch
	cPart3 = stoi(str.substr(posLast));
}

void disect(string str, int& cPart1) {
	int posFirst = str.find(" ");
	cPart1 = stoi(str.substr(posFirst + 1, str.length() - posFirst));
}

void disect(string str, int& cPart1,int& cPart3) {
	int posFirst = str.find(" ");
	int posLast = str.rfind(" ");
	cPart1 = stoi(str.substr(posFirst + 1, str.length() - posFirst));
	cPart3 = stoi(str.substr(posLast));
}

int main()
{
	vector<Complex> cV;
	ifstream ifile("data.txt");
	string str,command,param1,param2,param3;
	int cPart1 = 0,cPart2 = 0,cPart3 = 0;
	while (getline(ifile, str)) {
		command = str.substr(0, str.find(' '));
		if (command == "push") {
			disect(str, cPart1, cPart2, cPart3);
			cout << "Pushing: " << cPart1 << " + " << cPart2 << "i" << endl;
			push(cV, cPart1, cPart2);
		} else if (command == "pop") {
			cout << "Popping" << endl;
			pop(cV);
		} else if (command == "at") {
			disect(str, cPart1);
			cout << "At position " << cPart1 << endl;
			at(cV, cPart1);
		} else if (command == "back") {
			cout << "What is at the back" << endl;
			back(cV);
		} else if (command == "front") {
			cout << "What is at the front" << endl;
			front(cV);
		} else if (command == "insert") {
			disect(str, cPart1, cPart2, cPart3);
			cout << "Inserting " << cPart2 << "+ " << cPart3 << "i at position" << cPart1 << endl;
			insert(cV, cPart1, cPart2, cPart3);
		} else if (command == "erase") {
			disect(str, cPart1, cPart3);
			if (cPart1 == cPart3) {
				cout << "Erasing at position " << cPart1 << endl;
				erase(cV, cPart1);
			} else {
				cout << "Erasing at position " << cPart1 << " to " << cPart3 << endl;
				erase(cV, cPart1, cPart3);
			}
		} else if (command == "addFriend") {
			disect(str, cPart1, cPart2, cPart3);
			cout << "Adding with the friend function" << endl;
			Complex d = addFriend(cV, cPart1, cPart2);
			cout << d << endl;
		} else if (command == "add+") {
			disect(str, cPart1, cPart2, cPart3);
			cout << "Adding with the overloaded operator" << endl;
			Complex d = add(cV, cPart1, cPart2);
			cout << d << endl;
		} else if (command == "display") {
			cout << "Displaying" << endl;
			display(cV);
		} else {
			cout << "command not recognized" << endl;
		}
	}
}
