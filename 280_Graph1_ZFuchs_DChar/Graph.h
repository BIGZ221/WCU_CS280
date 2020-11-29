#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>

using namespace std;
const int MAX = 8;

void createCities(vector<string> &fileCont, vector<string>& cities) {
	string one, two, three, vertex;
	for(unsigned int i = 0; i < fileCont.size(); i++){
		istringstream vertices(fileCont[i]);
		while (vertices >> vertex) {
			if (vertex != "<>" && vertex != ">") {
				if(cities.size() == 0){
					cities.push_back(vertex);
				} else if (find(cities.begin(), cities.end(), vertex) == cities.end()){
					cities.push_back(vertex);
				}
			}
		}
	}
}

void createGraph(vector<string> fileCont, vector<string> cities, int matrix[MAX][MAX]){
	string from, op, to;
	int fromIndex, toIndex;
	for (unsigned int i  = 0; i < fileCont.size(); i++){
		istringstream vertex(fileCont[i]);
		vertex >> from;
		vertex >> op;
		if(op == "<>"){
			while(vertex >> to){
				for(unsigned int i = 0; i < cities.size(); i++){
					if (from == cities[i]) {
						fromIndex = i;
					}
					if(to == cities[i]){
						toIndex = i;
					}	
				}
				matrix[fromIndex][toIndex] = 1;
				matrix[toIndex][fromIndex] = 1;
			}
		}
		if(op == ">"){
			while(vertex >> to){
				for(int i = 0; i < cities.size(); i++){
					if (from == cities[i]) {
						fromIndex = i;
					}
					if(to == cities[i]){
						toIndex = i;
					}	
				}
				matrix[fromIndex][toIndex] = 1;
			}
		}
	}
}

void depthFirstSearch(string start, int matrix[MAX][MAX], vector<string> cities){
	int s;
	vector<bool> visited(cities.size(), false);

	for(int i = 0; i < cities.size(); i++){
		if (start == cities[i]) {
			s = i;
		}
	}

    stack<int> stack;
    stack.push(s);
	cout << "Depth first search of " << start << ": ";
    while(!stack.empty()){
        s = stack.top();
        stack.pop();
        if(!visited[s]){
            cout << cities[s] << " ";
			visited[s] = true;
        }	

		for(int j = cities.size()-1; j >= 0; j--){
			if(matrix[s][j] == 1 && visited[j] == false){
				stack.push(j);
			}
		}
    }
}

void adjacent(string start, int matrix[MAX][MAX], vector<string> cities){
	int s;
	bool found = false;
	vector<string> adj;
	for (int i = 0; i < cities.size(); i++) {
		if (start == cities[i]) {
			s = i;
			found = true;
		}
		else if(i == cities.size() - 1 && !found){
			cout << start << " is not in the map" << endl;
			return;
		}
	}
	for (int i = 0; i < cities.size(); i++){
		if(matrix[s][i] == 1){
			adj.push_back(cities[i]);
		}
	}
	cout << "Adjacent cities to " << start << ": ";
	if(adj.size() == 0){
		cout << "There are no adjacent cities" << endl;
	}
	for(int i = 0; i < adj.size(); i++){
		cout << adj[i] << " ";
	}
}