/*
	280
	BST1
	ZFuchs, DChar
*/
#include <iostream>
#include "BST1.h"
using namespace std;

int main()
{
	BST1 bst1 = BST1();
	cout << "Inserting 30 50 10 70 5 35 20 35 15 0 40 65" << endl << endl;
	bst1.insert(30);
	bst1.insert(50);
	bst1.insert(10);
	bst1.insert(70);
	bst1.insert(5);
	bst1.insert(35);
	bst1.insert(20);
	bst1.insert(35);
	bst1.insert(15);
	bst1.insert(0);
	bst1.insert(40);
	bst1.insert(65);

	cout << "Displaying" << endl; 
	cout << "Expected:" << endl; 
	cout << "in order:     0   5  10  15  20  30  35  35  40  50  65  70" << endl; 
	cout << "pre order:   30  10   5   0  20  15  50  35  35  40  70  65" << endl;
	cout << "post order:   0   5  15  20  10  35  40  35  65  70  50  30" << endl; 
	cout << "Actual:" << endl;
	cout << "in order: ";  
	bst1.displayInOrder();
	cout << endl;
	cout << "pre order: "; 
	bst1.displayPreOrder();
	cout << endl;
	cout << "post order: "; 
	bst1.displayPostOrder();
	cout << endl << endl;

	cout << "Counting Leaves" << endl; 
	cout << "Expected:" << endl; 
	cout << "5" << endl; 
	cout << "Actual:" << endl;
	cout << bst1.countLeaves() << endl << endl;

	cout << "Calculating Height" << endl; 
	cout << "Expected:" << endl; 
	cout << "4" << endl; 
	cout << "Actual:" << endl;
	cout << bst1.height() << endl << endl;

	cout << "Finding 40" << endl << "Expected:" << endl << "found, value is 40" << endl << "Actual:" << endl;
	bst1.find(40);

	cout << endl << "Finding 33" << endl << "Expected:" << endl << "not found" << endl << "Actual:" << endl;
	bst1.find(33);

	cout << endl << "Deleting 0" << endl;
	cout << "Expected: " << endl << "   5  10  15  20  30  35  35  40  50  65  70" << endl << "Actual: " << endl;
	bst1.remove(0);
	cout << endl;

	cout << "Deleting 50" << endl;
	cout << "Expected: " << endl << "   5  10  15  20  30  35  35  40  65  70" << endl << "Actual: " << endl;
	bst1.remove(50);
	cout << endl;

	cout << "Deleting 33" << endl;
	cout << "Expected: " << endl << "Did not delete 33" << endl << "Actual: " << endl;
	bst1.remove(33);
	cout << endl;
}
