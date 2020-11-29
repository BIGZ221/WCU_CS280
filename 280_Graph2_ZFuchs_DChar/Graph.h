#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
const int MAX = 8;

void createCities(vector<string>& fileCont, vector<string>& cities) {
	string one, two, three, vertex, weight;
	for (unsigned int i = 0; i < fileCont.size(); i++) {
		istringstream vertices(fileCont[i]);
		while (vertices >> vertex) {
			if (vertex != "<>" && vertex != ">") {
				vertices >> weight;
				if (cities.size() == 0) {
					cities.push_back(vertex);
				}
				else if (find(cities.begin(), cities.end(), vertex) == cities.end()) {
					cities.push_back(vertex);
				}
			}
		}
	}
}

void createGraph(vector<string> fileCont, vector<string> cities, int matrix[MAX][MAX]) {
	string from, op, to, temp;
	int fromIndex=0, toIndex=0, weight;
	for (unsigned int i = 0; i < fileCont.size(); i++) {
		istringstream vertex(fileCont[i]);
		vertex >> from;
		vertex >> op;
		if (op == ">") {
			while (vertex >> to) {
				for (int i = 0; i < cities.size(); i++) {
					if (from == cities[i]) {
						fromIndex = i;
					}
					if (to == cities[i]) {
						toIndex = i;
					}
				}
				vertex >> temp;
				weight = stoi(temp);
				matrix[fromIndex][toIndex] = weight;
			}
		}
	}
}

void depthFirstSearch(string start, int matrix[MAX][MAX], vector<string> cities) {
	int s;
	vector<bool> visited(cities.size(), false);

	for (int i = 0; i < cities.size(); i++) {
		if (start == cities[i]) {
			s = i;
		}
	}

	stack<int> stack;
	stack.push(s);
	cout << "Depth first search of " << start << ": ";
	while (!stack.empty()) {
		s = stack.top();
		stack.pop();
		if (!visited[s]) {
			cout << cities[s] << " ";
			visited[s] = true;
		}

		for (int j = cities.size() - 1; j >= 0; j--) {
			if (matrix[s][j] == 1 && visited[j] == false) {
				stack.push(j);
			}
		}
	}
}

void breadthFirstSearch(string start, int matrix[MAX][MAX], vector<string> cities) {
	int s;
	vector<bool> visited(cities.size(), false);

	for (int i = 0; i < cities.size(); i++) {
		if (start == cities[i]) {
			s = i;
		}
	}

	queue<int> queue;
	visited[s] = true;
	queue.push(s);
	cout << "Breadth first search of " << start << ": ";
	while (!queue.empty()) {
		s = queue.front();
		cout << cities[s];
		queue.pop();

		for (int j = 0; j < cities.size(); j++) {
			if (matrix[s][j] > 0 && visited[j] == false) {
				visited[j]=true;
				queue.push(j);
			}
		}
	}
}

int minDistance(vector<int> distances, vector<bool> visited) {
	int min = INT_MAX, minIndex=0;
	for (int i = 0; i < distances.size(); i++) {
		if (visited[i] == false && distances[i] <= min) {
			min = distances[i];
			minIndex = i;
		}
	}
	return minIndex;
}

void dijkstra(string start, string target, int matrix[MAX][MAX], vector<string> cities) {
	int startIndex = -1, targetIndex = -1, min = INT_MAX;
	for (int i = 0; i < cities.size(); i++) {
		if (start == cities[i]) {
			startIndex = i;
		}
		if (target == cities[i]) {
			targetIndex = i;
		}
	}

	vector<bool> visited(cities.size(), false);
	vector<int> distances(cities.size(), INT_MAX);
	vector<string> nodes(cities.size());
	distances[startIndex] = 0;

	for(int i=0; i < cities.size(); i++){
		int index = minDistance(distances, visited);
		visited[index] = true;
		for (int j = 0; j < cities.size(); j++) {
			if (visited[j] != true && matrix[index][j] > 0 && distances[index] != INT_MAX && (distances[index] + matrix[index][j]) < distances[j]) {
				distances[j] = distances[index] + matrix[index][j];
				nodes[j] = cities[index];
			}
		}
	}
	
	cout << "Distance to target " << target << " starting at " << start << ": " << distances[targetIndex] << endl;

}

void adjacent(string start, int matrix[MAX][MAX], vector<string> cities) {
	int s;
	bool found = false;
	vector<string> adj;
	for (int i = 0; i < cities.size(); i++) {
		if (start == cities[i]) {
			s = i;
			found = true;
		}
		else if (i == cities.size() - 1 && !found) {
			cout << start << " is not in the map" << endl;
			return;
		}
	}
	for (int i = 0; i < cities.size(); i++) {
		if (matrix[s][i] == 1) {
			adj.push_back(cities[i]);
		}
	}
	cout << "Adjacent cities to " << start << ": ";
	if (adj.size() == 0) {
		cout << "There are no adjacent cities" << endl;
	}
	for (int i = 0; i < adj.size(); i++) {
		cout << adj[i] << " ";
	}
}