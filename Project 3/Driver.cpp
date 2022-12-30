#include <iostream>
#include "Poly.h"
using namespace std;

int main(){
	Poly p, p2;
	cout << "enter a poly" << endl;
	cin >> p;
	cout << p << endl;
	cout << "enter another poly" << endl;
	cin >> p2;
	cout << p + p2<< endl;
	Poly p3(p);
	cout << p3 << endl;
	cout << p << endl;
	p.Reset();
	cout << p << endl;
	cout << p3 << endl;
	p.AddTerm(3,4);
	p.AddTerm(2,5);
	cout << p << endl;
	
	return 0;
}
