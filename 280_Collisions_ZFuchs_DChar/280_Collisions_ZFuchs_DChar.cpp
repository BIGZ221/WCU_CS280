/*
    280
    Collisions
    ZFuchs, DChar
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int hash2(string str) {
    int sum = 0;
    for (int i = 0; i < str.size(); i++) {
        sum += int(str[i]);
    }
    sum += str.size() - str.size() % 2;
    return sum % 167;
}

void insert(string hashtable[], string str) {
    int index = hash2(str);
    while (hashtable[index] != "") {
        index++;
        index = index % 167;
    }
    hashtable[index] = str;
}

int retrieve(string hashtable[], string str) {
    int index = hash2(str);
    int start = index;
    while (hashtable[index] != str) {
        index++;
        index = index % 167;
        if (index == start) {
            cout << "That value does not exist in this hashtable. Check spelling and capitalization." << endl;
            return -1;
        }
    }
    return index;
}

string lowerCase(string str) {
    string temp = str;
    for (int i = 0; i < str.size(); i++) {
        temp[i] = tolower(str[i]);
    }
    return temp;
}

int main()
{
    string hashtable[167];
    string str, command, line;
    int index;
    bool run = true;
    for (int i = 0; i < 167; i++) {
        hashtable[i] = "";
    }
    ifstream ifile("names.txt");
    while (getline(ifile, str)) {
        index = hash2(str);
        while (hashtable[index] != "") {
            index++;
            index=index % 167;
        }
        hashtable[index] = str;
    }

    while (run) {
        str = command = "";
        cout << endl;
        cout << "================================================MENU================================================" << endl;
        cout << "Insert \t Inserts the string you provide. \t \t \t \t Syntax: insert example" << endl;
        cout << "Retrieve Retrieves the index of the specified value if it exists. \t Syntax: retrieve example" << endl;
        cout << "Exit \t Exits the program Syntax: exit" << endl;
        getline(cin, line);
        istringstream row(line);
        row >> command;
        row >> str;
        command = lowerCase(command);
        if (command == "insert") {
            insert(hashtable, str);
            cout << "The value has been added to the hashtable." << endl;
        }
        else if (command == "retrieve") {
            int retrievedIndex = retrieve(hashtable, str);
            if (retrievedIndex != -1) {
                cout << str << " was found at position " << retrievedIndex << endl;
            }
        } 
        else if (command == "exit") {
            run=false;
        }
        else  {
            cout << "Invalid command" << endl;
        }
    }
}
