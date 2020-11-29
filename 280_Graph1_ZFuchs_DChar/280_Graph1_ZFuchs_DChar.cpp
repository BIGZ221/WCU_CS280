/*
    280
    Graph1
    ZFuchs, DChar
*/

#include "Graph.h"
using namespace std;

int main()
{
    fstream ifile("test.txt");
    int matrix[MAX][MAX];
    vector<string> fileCont;
    vector<string> cities;
    string line,command1, command2;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            matrix[i][j] = 0;
        }
    }
    while(getline(ifile, line)){
        istringstream row(line);
        row >> command1;
        row >> command2;
        command1 += " ";
        command1 += command2;
        if (command1 == "* graph" || command1 == "* digraph") {
            while (getline(ifile, line)) {
                if (line[0] == '*') {
                    int pos = line.find(" ");
                    pos = line.find(" ", pos + 1);
                    command1 = line.substr(0, pos);
                    break;
                } else {
                    fileCont.push_back(line);
                    createCities(fileCont, cities);
                }
            }
            createGraph(fileCont, cities, matrix);
        }
        if (command1 == "* matrix") {
            cout << "     "; 
			for(int i = 0; i< cities.size(); i++){
				cout.width(9);
                cout << right;
				cout << cities[i];
			}
            cout << endl << endl;

           for (int i = 0; i < cities.size(); i++) {
                for (int j = 0; j < cities.size(); j++) {
                    cout.width(8);
                    cout << right;

					if(j == 0){
                        cout << cities[i] << "  ";
					}
                    cout << matrix[i][j] << " ";
                }
                cout << endl << endl << endl << endl;
            }
        }
        if (command1 == "* adjacent") {
            int pos = line.find(" ");
            pos = line.find(" ", pos + 1);
            command1 = line.substr(pos + 1, line.length());
           adjacent(command1, matrix, cities);
        }
        if (command1 == "* dfs") {
            int pos = line.find(" ");
            pos = line.find(" ", pos + 1);
            command1 = line.substr(pos+1, line.length());
            depthFirstSearch(command1, matrix, cities);
        }
        cout << endl;
    }
}