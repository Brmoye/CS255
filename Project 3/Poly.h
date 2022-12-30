#ifndef POLY_H
#define POLY_H

#include <cmath>
#include <iostream>
using namespace std;

class Poly;


class Node{
    //Term Data Representation
	int coeff;
	int degree;
    //Get to Next Node Data Representation
	Node* next;  
    //Operations upon the Node Data
	Node();
	Node(int c, int d);
	Node(int c, int d, Node* n);
	friend class Poly;
    friend istream& operator>>(istream& is, Poly& p);
	friend ostream& operator<<(ostream& os, const Poly& p);
	friend Poly operator+(const Poly& p1, const Poly& p2);
};

class Poly{
    //Poly Data Representation
	Node* head;
    //Private Help Method
	void Copy(const Poly& p);

public:
	Poly();
	Poly(const Poly& p);
	Poly& operator= (const Poly& p);
	~Poly();
	void AddTerm(int c, int d);
	double Eval(double x);
	void Reset();
	void Derivative();
	friend istream& operator>>(istream& is, Poly& p);
	friend ostream& operator<<(ostream& os, const Poly& p);
	friend Poly operator+(const Poly& p1, const Poly& p2);

};

#endif
