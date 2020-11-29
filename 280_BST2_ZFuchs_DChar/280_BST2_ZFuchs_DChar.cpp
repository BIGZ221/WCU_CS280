/*
	280
	BST2
	ZFuchs, DChar
*/

#include <iostream>
#include <iomanip>
#include "BST.h"
using namespace std;

int main()
{
	cout << boolalpha << setprecision(4);
	BST bst1 = BST();
	BST bst3 = BST();
	int x[] = {40, 10, 80, 70, 50, 30, 10, 90, 10, 60, 5, 25, 35};
	cout << "Inserting into BST1 Values: 40, 10, 80, 70, 50, 30, 10, 90, 10, 60, 5, 25, 35" << endl;
	cout << "Expected InOrder:   5  10  10  10  25  30  35  40  50  60  70  80  90" << endl;
	cout << "Expected PreOrder: 40  10  10  10   5  30  25  35  80  70  50  60  90" << endl;
	cout << "Expected PostOrder: 5  10  10  25  35  30  10  60  50  70  90  80  40" << endl << endl;
	for (int i = 0; i < sizeof(x)/4; i++) { //Divide by 4 because an integer in an array takes up 4 bytes
		bst1.insert(x[i]);
	}
	cout << "Actual InOrder:   ";
	bst1.displayInOrder();
	cout << endl << "Actual PreOrder:  ";
	bst1.displayPreOrder();
	cout << endl << "Actual PostOrder: ";
	bst1.displayPostOrder();
	cout << endl << endl << "Copying BST1 into BST2" << endl;
	cout << "Expected InOrder: 5  10  10  10  25  30  35  40  50  60  70  80  90" << endl;
	BST bst2 = BST(bst1.copy());
	cout << "Actual InOrder:";
	bst2.displayInOrder();
	cout << endl << endl << "Copying empty BST3 into BST4" << endl;
	cout << "Expected InOrder: " << endl;
	BST bst4 = BST(bst3.copy());
	cout << "Actual InOrder:";
	bst4.displayInOrder();
	cout << endl << endl << "Checking if BST1 and BST2 are equal" << endl;
	cout << "Expected: true" << endl;
	cout << "Actual:   " << bst1.equal(bst2) << endl << endl;
	cout << "Checking if BST1 and BST3 are equal" << endl;
	cout << "Expected: false" << endl;
	cout << "Actual:   " << bst1.equal(bst3) << endl << endl;
	cout << "Clearing BST2" << endl;
	cout << "Expected InOrder: " << endl;
	bst2.clear();
	cout << "Actual InOrder:   ";
	bst2.displayInOrder();
	cout << endl << endl << "Getting the size of BST1" << endl;
	cout << "Expected: 13" << endl;
	cout << "Actual:   " << bst1.getSize() << endl << endl;
	cout << "Getting the size of BST2" << endl;
	cout << "Expected: 0" << endl;
	cout << "Actual:   " << bst2.getSize() << endl << endl;
	cout << "Counting the leaves on BST1" << endl;
	cout << "Expected: 5" << endl;
	cout << "Actual:   " << bst1.leafCount() << endl << endl;
	cout << "Counting the leaves on BST2" << endl;
	cout << "Expected: 0" << endl;
	cout << "Actual:   " << bst2.leafCount() << endl << endl;
	cout << "Finding Max of BST1" << endl;
	cout << "Expected: 90" << endl;
	cout << "Actual:   " << bst1.findMax() << endl << endl;
	cout << "Finding Max of BST2" << endl;
	cout << "Expected: 0" << endl;
	cout << "Actual:   " << bst2.findMax() << endl << endl;
	cout << "Finding Min of BST1" << endl;
	cout << "Expected: 5" << endl;
	cout << "Actual:   " << bst1.findMin() << endl << endl;
	cout << "Finding Min of BST2" << endl;
	cout << "Expected: 0" << endl;
	cout << "Actual:   " << bst2.findMin() << endl << endl;
	cout << "Finding the Sum of BST1" << endl;
	cout << "Expected: 515" << endl;
	cout << "Actual:   " << bst1.findSum() << endl << endl;
	cout << "Finding the Sum of BST2" << endl;
	cout << "Expected: 0" << endl;
	cout << "Actual:   " << bst2.findSum() << endl << endl;
	cout << "Finding the Average of BST1" << endl;
	cout << "Expected: 39.62" << endl;
	cout << "Actual:   " << bst1.findAve() << endl << endl;
	cout << "Finding the Average of BST2" << endl;
	cout << "Expected: 0" << endl;
	cout << "Actual:   " << bst2.findAve() << endl << endl;
	cout << "Displaying BST1 Level by Level" << endl;
	cout << "Expected: 40 10 80 10 30 70 90 10 25 35 50 5 60" << endl;
	cout << "Actual:   ";
	bst1.levelByLevel();
	cout << endl << endl << "Displaying BST2 Level by Level" << endl;
	cout << "Expected: " << endl;
	cout << "Actual:   ";
	bst2.levelByLevel();
}
