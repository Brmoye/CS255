#ifndef POLY_H
#define POLY_H

#include <cmath>
#include <iostream>
using namespace std;

const unsigned int MAX = 21;

class Poly{
	int terms[MAX];

public:
	Poly();
	double Eval(double x);
	void Reset();
	void operator+=(const Poly& p);
	void Derivative();
	friend istream& operator>>(istream& is, Poly& p);
	friend ostream& operator<<(ostream& os, const Poly& p);
	friend Poly operator+(const Poly& p1, const Poly& p2);
	friend Poly operator*(const Poly& p1, const Poly& p2);
};

#endif