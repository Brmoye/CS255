#include <iostream>;

using namespace std;

// class declaration
class Fraction
{
		// data representation
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
		void multiplyBy(const Fraction& op);
		void addTo(const Fraction& op);
		Fraction multiply(const Fraction& right) const;
		Fraction add(const Fraction& right) const;
		
};

// class Fraction definition
// Fraction:: is class specifier
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

int main() 
{
	Fraction f1;		// Instantiates the Fraction class
	Fraction f2;		// Instantiates the Fraction class
	Fraction f3;		// Instantiates the Fraction class
    Fraction f4;
	Fraction result;
	
	cout << "Enter a Fraction in the form num/den: ";
	f1.input();
	f1.print();
	
	cout << endl;
	
	cout << "Enter a Fraction in the form num/den: ";
	f2.input();
	f2.print();
	
	cout << endl;
	cout << "The fractions added together = ";

    result = f1.add(f2);
	result.print();
	
	cout << endl << "Multiplied: ";
	
	result = f1.multiply(f2);
	result.print();
	
	

	return 0;
}
