
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int hash1(string str) {
    int sum = 0;
    for (int i = 0; i < str.size(); i++) {
        sum += int(str[i]);
    }
    return (sum%150);
}

int hash2(string str) {
    int sum = 0;
    for (int i = 0; i < str.size(); i++) {
        sum += int(str[i]);
    }
    sum += str.size()-str.size()%2;
    return sum%167;
}

int sumCollisions(int collisionTable[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += collisionTable[i];
    }
    return sum;
}

int main()
{
    string str;
    int hashtable1[150];
    int hashtable2[167];
    
    int collisionTable1[150];
    int collisionTable2[167];

    int totalCollisions1, totalCollisions2;

    ifstream ifile1("names.txt");
    ifstream ifile2("names.txt");

    for (int i = 0; i < 150; i++) {
        hashtable1[i] = 0;
        collisionTable1[i] = 0;
    }

    for (int i = 0; i < 167; i++) {
        hashtable2[i] = 0;
        collisionTable2[i] = 0;
    }
    
    while (getline(ifile1, str)) {
        hashtable1[hash1(str)] += 1;
    }

    for (int i = 0; i < 150; i++) {
        if (hashtable1[i] > 1) {
            collisionTable1[i] += hashtable1[i]-1;
        }
    }

    while (getline(ifile2, str)) {
        hashtable2[hash2(str)] += 1;
    }

    for (int i = 0; i < 167; i++) {
        if (hashtable2[i] > 1) {
            collisionTable2[i] += hashtable2[i] - 1;
        }
    }
    totalCollisions1 = sumCollisions(collisionTable1, (sizeof(collisionTable1)/4));
    totalCollisions2 = sumCollisions(collisionTable2, (sizeof(collisionTable2)/4));

    cout << "Hash Value \t \t # of times a string hashed to this value \t \t # of collisions" << endl;
    for (int i = 0; i < 150; i++) {
        cout << "\t" << i << "\t \t \t \t \t" << hashtable1[i] << "\t \t \t \t \t" << collisionTable1[i] << endl;
    }
    cout << "Collisions in hashtable1: " << totalCollisions1 << endl << endl;
    cout << "Hash Value \t \t # of times a string hashed to this value \t \t # of collisions" << endl;
    for (int i = 0; i < 167; i++) {
        cout << "\t" << i << "\t \t \t \t \t" << hashtable2[i] << "\t \t \t \t \t" << collisionTable2[i] << endl;
    }
    cout << "Collisions in Table2: " << totalCollisions2 << endl;
}

