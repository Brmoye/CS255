#include <iostream>

using namespace std;

// class declaration - needs data representation and the operations on that data
class Fraction
{
		// data representation
		// data members & methods
		// methods have a calling object
	private:
		int num;
		int den;
		
	public:
		// constructor
		Fraction();		// constructor that will initialize
		Fraction(int n);
		Fraction(int n, int d);
		void print() const;	// method that will output the object
		void input();
		int getNum()const;
		int getDen()const;
		void setNum(int n);
		void setDen(int d);
		void setNumAndDen(int n, int d);
		void multiplyBy(const Fraction& op);
		void addTo(const Fraction& op);
		Fraction multiply(const Fraction& right) const;
		Fraction add(const Fraction& right) const;
		//Fraction operator*(const Fraction& right) const;
		
		friend Fraction operator* (const Fraction& left, const Fraction& right);
		friend Fraction operator/ (const Fraction& left, const Fraction& right);
		Fraction operator+(const Fraction& right) const;
		friend Fraction operator- (const Fraction& left, const Fraction& right);
		
		friend ostream& operator<< (ostream& os, const Fraction& right);
		friend istream& operator>> (istream& is, Fraction& right);
		
		friend bool operator== (const Fraction& left, const Fraction& right);
		friend bool operator!= (const Fraction& left, const Fraction& right);
		friend bool operator< (const Fraction& left, const Fraction& right);
		friend bool operator<= (const Fraction& left, const Fraction& right);
		friend bool operator> (const Fraction& left, const Fraction& right);
		friend bool operator>= (const Fraction& left, const Fraction& right);
		
		friend Fraction operator++ (Fraction& f, int); // postfix
		friend Fraction operator++ (Fraction& f); // prefix
		
		Fraction operator-- (int); // postfix
		Fraction operator-- (); // prefix
		
		Fraction reduce(Fraction op);
		
};

// class Fraction definition
// Fraction:: is class specifier

// Constructors
Fraction::Fraction()
{
	cout << "Fraction Constructor - no data" << endl;
	num = 0;
	den = 1;
}

Fraction::Fraction(int n)
{
	cout << "Fraction Constructor - data_1" << endl;
	num = n;
	den = 1;
}

Fraction::Fraction(int n, int d)
{
	cout << "Fraction Constructor - data_2" << endl;
	num = n;
	if(d == 0)
	{
		d = 1;
	}
	den = d;
}

// Methods



void Fraction::print()const
{
	cout << num << "/" << den << endl;
}

void Fraction::input()
{
	char dummy;
	cin >> num;
	cin >> dummy;
	cin >> den;
}

int Fraction::getNum()const
{
	return this-> num;
}

int Fraction::getDen()const
{
	return this-> den;
}

void Fraction::setNum(int n)
{
	this-> num = n;
}

void Fraction::setDen(int d)
{
	if(d == 0)
		d = 1;
	this-> den = d;
}

void Fraction::setNumAndDen(int n, int d)
{
	this-> num = n;
	if(d == 0)
		d = 1;
	this-> den = d;
}

void Fraction::multiplyBy(const Fraction& op)
{
    num *= op.num;
    den *= op.den;
}

void Fraction::addTo(const Fraction& op)
{
	num *= op.den;
	num += op.num * den;
	
	den *= op.den;
}

Fraction Fraction::multiply(const Fraction& right) const
{
	Fraction tempResult;
	
	tempResult.num = num * right.num;
	tempResult.den = den * right.den;
	
	return tempResult;
}

Fraction Fraction::add(const Fraction& right) const
{
    Fraction tempFraction;

    tempFraction.num = num * right.den;
    tempFraction.num += right.num * den;
    tempFraction.den = den * right.den;

    return tempFraction;
}

Fraction operator*(const Fraction& left, const Fraction& right)
{
	Fraction temp;
	
	temp.num = left.num * right.num;
	temp.den = left.den * right.den;
	
	return temp;
}

Fraction operator/(const Fraction& left, const Fraction& right)
{
	Fraction temp;
	
	temp.num = left.num * right.den;
	temp.den = left.den * right.num;
	
	return temp;
}

Fraction Fraction::operator+(const Fraction& right) const
{
	Fraction tempFraction;

    tempFraction.num = num * right.den;
    tempFraction.num += right.num * den;
    tempFraction.den = den * right.den;

    return tempFraction;
}

Fraction operator-(const Fraction& left, const Fraction& right)
{
	Fraction result;
	
	result.num = left.num * right.den;
	result.num -= right.num * left.den;
	result.den = left.den * right.den;
	
	return result;
}

ostream& operator<<(ostream& os, const Fraction& right)
{
    os << right.num << '/' << right.den;
    return os;
}

istream& operator>>(istream& is, Fraction& right)
{
	char temp;
	is >> right.num;
	is >> temp;
	is >> right.den;
	if(right.den == 0)
		right.den = 1;
    return is;
}

bool operator== (const Fraction& left, const Fraction& right)
{
	return left.num * right.den == right.num * left.den;
}

bool operator!= (const Fraction& left, const Fraction& right)
{
	return !(left == right);
}

bool operator< (const Fraction& left, const Fraction& right)
{
	return left.num * right.den <  right.num * left.den;
}

bool operator<= (const Fraction& left, const Fraction& right)
{
	return (left < right || left == right);
}

bool operator> (const Fraction& left, const Fraction& right)
{
	return !(left < right || left == right);
}

bool operator>= (const Fraction& left, const Fraction& right)
{
	return (left > right || left == right);
}

Fraction Fraction::reduce(Fraction op)
{
	
}

/************************************************************
 * Function Name: operator++ (postfix)
 * Incoming: Fraction to be modified and dummy int for postfix
 * Outgoing: updated Fraction with increment
 * Return Value: previous Fraction prior to increment
 * Description: 
 ************************************************************/
Fraction operator++ (Fraction& f, int) // postfix
{
	Fraction temp = f;	// stores previous value
	
	f.num += f.den; 	// adds 1 to value
	return temp;		// returns previous value while passing back updated value
}

/************************************************************
 * Function Name: operator++ (prefix)
 * Incoming: Fraction to be modified
 * Outgoing: updated Fraction with increment
 * Return Value: updated Fraction with increment
 * Description: 
 ************************************************************/
Fraction operator++ (Fraction& f) // prefix
{
	f.num += f.den;
	return f;
}

Fraction Fraction::operator-- (int) // postfix
{
	Fraction temp = *this;
	num -= den;
	return temp;	
}

Fraction Fraction::operator-- () // prefix
{
	num -= den;
	return *this;
}

int main() 
{
	Fraction year(19, 1);	// Instantiates the Fraction class
	//Fraction f2(1, 4);		// Instantiates the Fraction class
	//Fraction result;		// Instantiates the Fraction class
	
	cout << year << endl;
	cout << year-- << endl;
	cout << year << endl;
	
	year.setNum(19);
	cout << "******************" << endl;
	cout << year << endl;
	cout << --year << endl;
	cout << year << endl;
	
	return 0;
}
