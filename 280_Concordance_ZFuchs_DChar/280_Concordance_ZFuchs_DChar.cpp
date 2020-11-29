/*
	280
	Concordance
	ZFuchs, DChar
*/
#include "Concordance.h"
#include <iostream>
using namespace std;

int main() {
	Concordance c1 = Concordance();
	Concordance c2 = Concordance();
	c1.loadConcordance("test.txt");
	c2.loadConcordance("test2.txt");
	c1.displayConcordance();
	cout << endl << endl;
	c2.displayConcordance();
}