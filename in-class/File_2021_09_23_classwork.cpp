#include <iostream>
using namespace std;

//class declaration
class Fraction{
	//data representationdf
	int num;
	int den;
public:
	//constructor - called when an object is created
	Fraction(); //constructor that will initialize
	Fraction(int n); 
	Fraction(int n, int d);
	void Print()const; //method that will output the object
	void Input(); 
	int GetNum()const;
	int GetDen()const; 
	void SetNum(int n);
	void SetDen(int d);
	Fraction Multiply(const Fraction& right)const;
	//Fraction operator*(const Fraction& right)const;
	friend Fraction operator*(const Fraction& left, const Fraction& right);

	friend ostream& operator<<(ostream& os, const Fraction& right);
	friend istream& operator>>(istream& is,  Fraction& right);
   
	friend bool operator== (const Fraction& left, const Fraction& right);
	friend bool operator< (const Fraction& left, const Fraction& right);
	friend bool operator!= (const Fraction& left, const Fraction& right);
	friend bool operator> (const Fraction& left, const Fraction& right);
	friend bool operator<= (const Fraction& left, const Fraction& right);
	friend bool operator>= (const Fraction& left, const Fraction& right);

};

//class Fraction definition

Fraction::Fraction(){
	cout << "Fraction Constructor - no data" << endl;
	num = 0;
	den = 1;
}
Fraction::Fraction(int n){
	cout << "Fraction Constructor - data_1" << endl;
	num = n;
	den = 1;
}
Fraction::Fraction(int n, int d){
	cout << "Fraction Constructor - data_2" << endl;
	num = n;
	
	if (d == 0)
		den = 1;
	else
		den = d;
	

}
void Fraction::Print()const{
	cout << num << "/" << den;
}

void Fraction::Input(){
	char dummy;
	cin >> num;
	cin >> dummy;
	cin >> den;
}

int Fraction::GetNum()const{
	return num;
}
int Fraction::GetDen()const{
	return den;
}
void Fraction::SetNum(int n){
	num = n;
}
void Fraction::SetDen(int d){
	if (d == 0)
		d = 1;
	den = d;
}

Fraction Fraction::Multiply(const Fraction& right)const{
	Fraction temp;
	temp.num = num * right.num;
	temp.den = den * right.den;
	return temp;
}
/*Fraction Fraction::operator*(const Fraction& right)const{
	Fraction temp;
	temp.num = num * right.num;
	temp.den = den * right.den;
	return temp;
}
*/
Fraction operator*(const Fraction& left, const Fraction& right){
	Fraction temp;
	temp.num = left.num * right.num;
	temp.den = left.den * right.den;
	return temp;

}

ostream& operator<<(ostream& os, const Fraction& right){
	os << right.num << "/" << right.den;
	return os;
}
istream& operator>>(istream& is,Fraction& right){
	char dummy;
	is >> right.num;
	is >> dummy;
	is >> right.den;
	if (right.den == 0)
		right.den = 1;
	return is;
}

bool operator== (const Fraction& left, const Fraction& right){
	return left.num * right.den == right.num * left.den;
}
bool operator< (const Fraction& left, const Fraction& right){
	return left.num * right.den < right.num * left.den;
}
bool operator!= (const Fraction& left, const Fraction& right){
	return left.num * right.den != right.num * left.den;

}
bool operator> (const Fraction& left, const Fraction& right){
	return left.num * right.den > right.num * left.den;
}
bool operator<= (const Fraction& left, const Fraction& right){
	return left.num * right.den <= right.num * left.den;
}
bool operator>= (const Fraction& left, const Fraction& right){
	return left.num * right.den >= right.num * left.den;
}



int main(){

	Fraction f1(2,4); //Instantiates the Fraction class
	Fraction f2(1,2);
	


	return 0;
}
