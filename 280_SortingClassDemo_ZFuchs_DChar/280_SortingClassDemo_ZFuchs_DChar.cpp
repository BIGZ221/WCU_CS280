/*
	SortingClassDemo
	280
	DChar, ZFuchs
*/
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

const int MAX_CHARS = 10;
const int MAX_STRINGS = 1000;

void cr(int n = 1) {
	for (int i = 0; i < n; i++)
		cout << endl;
}

class Sorter {
private:
	string workspace[MAX_STRINGS];
	string randomString();
public:
	Sorter();
	void load();
	void display();
	void insertionSort();
	void bubbleSort();
	void selectionSort();
	void shellSort();
	void quickSort(int, int);
	bool isSorted();
};
Sorter::Sorter() {
}

string Sorter::randomString() {
	string s = "";
	for (int i = 0; i < MAX_CHARS; i++) {
		char randomChar = char(rand() % 26 + 97);
		s += randomChar;
	}
	return s;
}

void Sorter::load() {
	for (int i = 0; i < MAX_STRINGS; i++)
		workspace[i] = randomString();
}

void Sorter::display() {
	for (int i = 0; i < MAX_STRINGS; i++)
		cout << workspace[i] << " ";
	cout << endl;
}

void Sorter::insertionSort() {
	int j;
	string key;
	for (int i = 1; i < MAX_STRINGS; i++) {
		key = workspace[i];
		j = i - 1;
		while (j >= 0 && workspace[j] > key) {
			workspace[j + 1] = workspace[j];
			j--;
		}
		workspace[j + 1] = key;
	}
}

void Sorter::bubbleSort() {
	string holder;
	for (int j = 0; j < MAX_STRINGS - 1; j++) {
		for (int i = 0; i < MAX_STRINGS - 1; i++) {
			holder = workspace[i];
			if (workspace[i] > workspace[i + 1]) {
				workspace[i] = workspace[i + 1];
				workspace[i + 1] = holder;
			}
		}
	}
}

void Sorter::selectionSort() {
	string min, temp;
	int next;
	for (int i = 0; i < MAX_STRINGS; i++) {
		min = workspace[i];
		next = i;
		for (int j = i + 1; j < MAX_STRINGS; j++) {
			if (workspace[j] < min) {
				min = workspace[j];
				next = j;
			}
		}
		temp = workspace[i];
		workspace[i] = workspace[next];
		workspace[next] = temp;
	}
}

void Sorter::shellSort() {
	int gap = MAX_STRINGS / 2;
	bool Switch;
	while (gap > 0) {
		do {
			Switch = false;
			for (int i = 0; i < MAX_STRINGS - gap; i++) {
				if (workspace[i] > workspace[i + gap]) {
					swap(workspace[i], workspace[i + gap]);
					Switch = true;
				}
			}
		} while (Switch == true);
		gap = gap / 2;
	}
}

void Sorter::quickSort(int first=0, int last=MAX_STRINGS-1) {
	int low = first;
	int high = last;
	int d = (low + high) / 2;
	string partition = workspace[d];
	do {
		while (workspace[low] < partition) {
			low++;
		}
		while (workspace[high] > partition) {
			high--;
		}
		if (low <= high) {
			swap(workspace[low], workspace[high]);
			low++;
			high--;
		}
	} while (low < high);
	if (first < high) {
		quickSort(first, high);
	}
	if (low < last) {
		quickSort(low, last);
	}
}

bool Sorter::isSorted() {
	for (int i = 0; i < MAX_STRINGS - 1; i++) {
		if (workspace[i] > workspace[i + 1]) {
			return false;
		}
	}
	return true;
}

int main() {
	srand(time(NULL));
	clock_t start, stop;
	Sorter s1 = Sorter();
	s1.load();
	Sorter s2 = Sorter(s1);
	Sorter s3 = Sorter(s1);
	Sorter s4 = Sorter(s1);
	Sorter s5 = Sorter(s1);

	start = clock();
	s1.insertionSort();
	stop = clock();
	if (!s1.isSorted()) {
		cout << "Error: insertion sort failed";
		cr(2);
		exit(EXIT_FAILURE);
	} else {
		double elapsedTime = ((double)stop - start) / CLOCKS_PER_SEC;
		cout << "Insertion Sort Time: " << elapsedTime << endl;
	}
	cr(2);

	start = clock();
	s2.bubbleSort();
	stop = clock();
	if (!s2.isSorted()) {
		cout << "Error: bubble sort failed";
		cr(2);
		exit(EXIT_FAILURE);
	} else {
		double elapsedTime = ((double)stop - start) / CLOCKS_PER_SEC;
		cout << "Bubble Sort Time: " << elapsedTime << endl;
	}
	cr(2);

	start = clock();
	s3.selectionSort();
	stop = clock();
	if (!s3.isSorted()) {
		cout << "Error: selection sort failed";
		cr(2);
		exit(EXIT_FAILURE);
	} else {
		double elapsedTime = ((double)stop - start) / CLOCKS_PER_SEC;
		cout << "Selection Sort Time: " << elapsedTime << endl;
	}
	cr(2);

	start = clock();
	s4.shellSort();
	stop = clock();
	if (!s4.isSorted()) {
		cout << "Error: shell sort failed";
		cr(2);
		exit(EXIT_FAILURE);
	} else {
		double elapsedTime = ((double)stop - start) / CLOCKS_PER_SEC;
		cout << "Shell Sort Time: " << elapsedTime << endl;
	}
	cr(2);

	start = clock();
	s5.quickSort();
	stop = clock();
	if (!s5.isSorted()) {
		cout << "Error: quick sort failed";
		cr(2);
		exit(EXIT_FAILURE);
	} else {
		double elapsedTime = ((double)stop - start) / CLOCKS_PER_SEC;
		cout << "Quick Sort Time: " << elapsedTime << endl;
	}
}