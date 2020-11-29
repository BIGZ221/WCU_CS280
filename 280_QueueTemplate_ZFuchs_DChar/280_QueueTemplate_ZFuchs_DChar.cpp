/*
	280
	QueueTemplate
	ZFuchs, DChar
*/
#include "Queue.h"
#include <iostream>
using namespace std;

int main()
{
	Queue<int> s1 = Queue<int>();
	Queue<char> s2 = Queue<char>();
	srand(time(NULL));

	cout << "Inserting 5 random integers in the range [-50, 100]." << endl; 
	cout << "Expected :" << endl; 
	cout << "Five random Intergers." << endl; 
	cout << "Actual :" << endl;

	for (int i = 0; i < 5; i++) {
		int j;
		j = rand() % 151 - 50;
		s1.append(j);
	}
	s1.displayFR();
	cout << endl << endl << "Serving the first 2 integers" << endl;
	cout << "Expected:" << endl;
	cout << "Random Integer" << endl << "Random Integer" << endl;
	cout << "Actual:" << endl;
	cout << s1.serve() << endl;
	cout << s1.serve() << endl << endl;
	
	cout << "Displaying the queue from front to rear" << endl;
	cout << "Expected:" << endl;
	cout << "3 random integers" << endl;
	cout << "Actual" << endl;
	s1.displayFR();

	cout << endl << endl << "Displaying the queue from rear to front" << endl;
	cout << "Expected:" << endl;
	cout << "3 random integers" << endl;
	cout << "Actual" << endl;
	s1.displayRF();
	cout << endl << endl;

	cout << "Inserting 5 random characters in the range [a, Z]." << endl;
	cout << "Expected :" << endl;
	cout << "Five random Characters." << endl;
	cout << "Actual :" << endl;

	for (int i = 0; i < 5; i++) {
		char j;
		j = rand() % 26+ 97;
		s2.append(j);
	}
	s2.displayFR();
	cout << endl << endl << "Serving the first 2 characters" << endl;
	cout << "Expected:" << endl;
	cout << "Random character" << endl << "Random character" << endl;
	cout << "Actual:" << endl;
	cout << s2.serve() << endl;
	cout << s2.serve() << endl << endl;

	cout << "Displaying the queue from front to rear" << endl;
	cout << "Expected:" << endl;
	cout << "3 random characters" << endl;
	cout << "Actual" << endl;
	s2.displayFR();

	cout << endl << endl << "Displaying the queue from rear to front" << endl;
	cout << "Expected:" << endl;
	cout << "3 random characters" << endl;
	cout << "Actual" << endl;
	s2.displayRF();
	cout << endl;
}
