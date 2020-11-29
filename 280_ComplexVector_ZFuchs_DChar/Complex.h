#pragma once
#include <iostream>
using namespace std;

class Complex {
private:
	double rPart, iPart;
public:
	//constructors
	Complex();
	Complex(double, double);

	//getters/accessors
	double getReal();
	double getImag();

	//setters/mutators
	void set(double, double);
	void  setReal(double);
	void setImag(double);

	//utility
	bool equal(Complex);
	friend bool equal(Complex, Complex);
	void display();
	void load();

	//arithmetic
	void add(Complex);
	friend Complex add(const Complex, const Complex);
	friend Complex operator + (const Complex, const Complex);
	void mult(Complex);
	friend Complex mult(const Complex, const Complex);
	friend Complex operator * (const Complex, const Complex);
	friend ostream & operator << (ostream &out, Complex& c);
	friend istream & operator >> (istream& in, Complex& c);
};

Complex::Complex() {
	rPart = iPart = 0;
} //Complex

Complex::Complex(double rVal, double iVal) {
	rPart = rVal;  iPart = iVal;
} //Complex

//Accessors
double Complex::getReal() {
	return rPart;
}

double Complex::getImag() {
	return iPart;
}

//setters
void Complex::set(double rVal, double iVal) {
	rPart = rVal;  iPart = iVal;
} //set

void Complex::setReal(double val) {
	rPart = val;
}

void Complex::setImag(double val) {
	iPart = val;
}

//utility
void Complex::load() {
	cout << "Enter rp and ip: ";
	cin >> rPart >> iPart;
} //load

bool Complex::equal(Complex num) {
	if (rPart == num.rPart && iPart == num.iPart) {
		return true;
	}
	return false;
}

bool equal(Complex val1, Complex val2) {
	if (val1.rPart == val2.rPart && val1.iPart == val2.iPart) {
		return true;
	}
	return false;
}

void Complex::display() {
	cout << rPart;
	if (iPart >= 0) cout << " + " << iPart;
	else cout << " - " << -iPart;
	cout << "i" << endl;
} //display

//math
void Complex::add(const Complex val) {
	rPart += val.rPart;
	iPart += val.iPart;
} //add

Complex add(const Complex v1, const Complex v2) {
	Complex t = Complex();
	t.rPart = v1.rPart + v2.rPart;
	t.iPart = v1.iPart + v2.iPart;
	return t;
} //add friend

void Complex::mult(const Complex val) {
	rPart *= val.rPart;
	iPart *= val.iPart;
}

Complex mult(const Complex val1, const Complex val2) {
	Complex result = Complex();
	result.iPart = val1.iPart * val2.iPart;
	result.rPart = val1.rPart * val2.rPart;
	return result;
}

Complex operator + (const Complex v1, const Complex v2) {
	return add(v1, v2);
} //+

Complex operator * (const Complex val1, const Complex val2) {
	return mult(val1, val2);
}

ostream& operator << (ostream& out, Complex& c) {
	out << c.rPart;
	if (c.iPart >= 0) {
		out << " + ";
		out << c.iPart;
		out << "i";
	} else {
		out << " - ";
		out << c.iPart * -1;
		out << "i";
	}
	return out;
}

istream& operator >> (istream& in, Complex& c) {
	in >> c.rPart >> c.iPart;
	return in;
}