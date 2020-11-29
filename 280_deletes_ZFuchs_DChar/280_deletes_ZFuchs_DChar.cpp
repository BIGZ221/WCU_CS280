/*
    280
    Deletes
    ZFuchs, DChar
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

const int max = 167;

struct names {
    string data = "";
    int status = 0; // -1 Deleted    0 Empty     1 Occupied
};

int hash2(string str) {
    int sum = 0;
    for (int i = 0; i < str.size(); i++) {
        sum += int(str[i]);
    }
    sum += str.size() - str.size() % 2;
    return sum % max;
}

string lowerCase(string str) {
    string temp = str;
    for (int i = 0; i < str.size(); i++) {
        temp[i] = tolower(str[i]);
    }
    return temp;
}

void insert(names hashtable[], string str) {
    int index = hash2(str);
    while (hashtable[index].data != "") {
        index++;
        index = index % max;
    }
    hashtable[index].data = str;
    hashtable[index].status = 1;
}

int retrieve(names hashtable[], string str) {
    int index = hash2(str);
    int start = index;
    while (hashtable[index].data != str) {
        index++;
        index = index % max;
        if (index == start || hashtable[index].status == 0) {
            cout << "That value does not exist in this hashtable. Check spelling and capitalization." << endl;
            return -1;
        }
    }
    return index;
}

bool deleteName(names hashtable[], string str) {
    int index = hash2(str);
    int start = index;
    while (hashtable[index].data != str) {
        index++;
        index = index % max;
        if (index == start || hashtable[index].status == 0) {
            return false;
        }
    }
    hashtable[index].data = "";
    hashtable[index].status = -1;
    return true;
}

int main()
{
    names hashtable[max];
    string str, command, line;
    int index;
    bool run = true;
    for (int i = 0; i < max; i++) {
        hashtable[i].data = "";
        hashtable[i].status = 0;
    }
    ifstream ifile("names.txt");
    while (getline(ifile, str)) {
        index = hash2(str);
        while (hashtable[index].data != "") {
            index++;
            index = index % max;
        }
        hashtable[index].data = str;
        hashtable[index].status = 1;
    }

    while (run) {
        str = command = "";
        cout << endl;
        cout << "================================================MENU================================================" << endl;
        cout << "Insert \t Inserts the string you provide. \t \t \t \t Syntax: insert example" << endl;
        cout << "Retrieve Retrieves the index of the specified value if it exists. \t Syntax: retrieve example" << endl;
        cout << "Delete \t Deletes the data if it exists inside of the hashtable. \t Syntax: delete example" << endl;
        cout << "Exit \t Exits the program \t \t \t \t \t \t Syntax: exit" << endl;
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
        else if (command == "delete") {
            bool completed = deleteName(hashtable, str);
            if (completed == false) {
                cout << "The value did not exist inside of the hashtable and could not be deleted." << endl;
            }
            else {
                cout << str << " was deleted from the hashtable." << endl;
            }
        }
        else if (command == "exit") {
            run = false;
        }
        else {
            cout << "Invalid command" << endl;
        }
    }

}
