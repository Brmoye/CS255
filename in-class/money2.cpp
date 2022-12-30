/******************************************************************
 * Name: Brian Moye & Georgia Dabbs
 * Class: CS 255-01
 * File name: money2.cpp
 * Date: September 28, 2021
 * Assignment: Money Class
 * Description: Define a Money class using two ints for dollars 
 * 		and cents and the methods to use it. For the purposes of 
 * 		this example any user inputted cent amount over 100 will 
 * 		be assumed to be as if they were submitting a dollar amount 
 * 		plus x amount of change. Ex: 7.111 = 8.11.
 ******************************************************************/

#include <iostream>
#include <math.h>

using namespace std;

/******************************************************************
 * Class Declaration
 ******************************************************************/
class Money
{
	private:
		// Class variables
		int dollars;
		int cents;
	
	public:
		// Constructors
		Money();
		Money(int dol);
		Money(int dol, int cen);
		
		// Mutators
		void setDollars(int dol);
		void setCents(int cen);
		
		// Accessors
		int getDollars()const;
		int getCents()const;
		
		// Methods
		int valueAsCents() const;
		static Money valueAsDollarsAndCents(int cents);
		
		// Input/Output
		friend ostream& operator<< (ostream& os, const Money& right);
		friend istream& operator>> (istream& is, Money& right);
		
		// Math
		friend Money operator+ (const Money& left, const Money& right);
		friend Money operator- (const Money& left, const Money& right);
		
		// Increment operations
		friend Money operator++ (Money& amount, int); // postfix
		friend Money operator++ (Money& amount); // prefix
		Money operator-- (int); // postfix
		Money operator-- (); // prefix
		
		// Relational operations
		friend bool operator== (const Money& left, const Money& right);
		friend bool operator!= (const Money& left, const Money& right);
		friend bool operator< (const Money& left, const Money& right);
		friend bool operator<= (const Money& left, const Money& right);
		friend bool operator> (const Money& left, const Money& right);
		friend bool operator>= (const Money& left, const Money& right);
};


/******************************************************************
 * Constructors
 ******************************************************************/
Money::Money()
{
	dollars = 0;
	cents = 0;
}

Money::Money(int dol)
{
	dollars = dol;
	cents = 0;
}

Money::Money(int dol, int cen)
{
	dollars = dol;
	cents = cen;
}

/******************************************************************
 * Class Functions
 ******************************************************************/
 
/******************************************************************
 * Function Name: setDollars
 * Incoming: int
 * Outgoing: int
 * Return Value: N/A
 * Description: Function sets the dollar amount of the object
 * 		calling the function.
 ******************************************************************/
void Money::setDollars(int dol)
{
	dollars = dol;
}

/******************************************************************
 * Function Name: setCents
 * Incoming: int
 * Outgoing: int
 * Return Value: N/A
 * Description: Function sets the cent amount of the object
 * 		calling the function.
 ******************************************************************/
void Money::setCents(int cen)
{
	cents = cen;
}

/******************************************************************
 * Function Name: getDollars
 * Incoming: N/A
 * Outgoing: int
 * Return Value: int
 * Description: Function returns the dollar amount of the object
 * 		calling the function.
 ******************************************************************/
int Money::getDollars() const
{
	return dollars;
}

/******************************************************************
 * Function Name: getCents
 * Incoming: N/A
 * Outgoing: int
 * Return Value: int
 * Description: Function returns the cent amount of the object
 * 		calling the function.
 ******************************************************************/
int Money::getCents() const
{
	return cents;
}

/******************************************************************
 * Function Name: valueAsCents
 * Incoming: N/A
 * Outgoing: int
 * Return Value: int
 * Description: Function returns the dollar and cent amount of the 
 * 		object calling the function as cents.
 ******************************************************************/
int Money::valueAsCents() const
{
	if (this->getDollars() < 0)
	{
		// if dollars is negative, takes the absolute value of cents and 
		// 	dollars * 100, to convert dollars to cents, then adds them and
		// 	returns that value * -1 to make it negative again
		return -1 * (abs(this->getCents()) + abs(this->getDollars() * 100));
	}
	
	else
	{
		return (this->getCents() + this->getDollars() * 100);
	}
}

/******************************************************************
 * Function Name: valueAsDollarsAndCents
 * Incoming: int
 * Outgoing: int, int
 * Return Value: Money
 * Description: Function returns the dollar and cent amount of the 
 * 		object calling the function.
 ******************************************************************/
Money Money::valueAsDollarsAndCents(int cents)
{
	Money temp;
	
	temp.setDollars(trunc(cents / 100));
	temp.setCents(cents % 100);
	
	return temp;
}

/******************************************************************
 * Function Name: operator<<
 * Incoming: ostream, Money
 * Outgoing: N/A
 * Return Value: ostream
 * Description: Function prints the dollar and cent amount of the 
 * 		object.
 ******************************************************************/
ostream& operator<<(ostream& os, const Money& right)
{
	// if dollars == 0 & cents < 0
	if(right.getDollars() == 0 && right.getCents() < 0)
	{
		// if -10 < cents < 0
		if (right.cents < 0 && right.cents > -10)
		{
			cout << "-" << right.getDollars() << ".0" << abs(right.getCents());
		}
		
		// if cents < -10
		else if(right.cents < -10)
		{
			cout << "-" << right.getDollars() << "." << abs(right.getCents());
		}
		
		
		else
		{
			cout << "-" << right.getDollars() << ".0" << right.getCents();
		}
	}
	
	// if dollars != 0 & cents < 10
    else if (right.cents < 10)
	{
		if (right.cents < 0 && right.cents > -10)
		{
			cout << right.getDollars() << ".0" << abs(right.getCents());
		}
		
		else if(right.cents < -10)
		{
			cout << right.getDollars() << "." << abs(right.getCents());
		}
		
		else
		{
			cout << right.getDollars() << ".0" << right.getCents();
		}
	}
	
	else 
	{
		cout << right.getDollars() << "." << right.getCents();
	}
	
    return os;
}

/******************************************************************
 * Function Name: operator>>
 * Incoming: istream, Money
 * Outgoing: int, int
 * Return Value: istream
 * Description: Function receives user input and sets the dollar 
 * 		and cent amounts of the object.
 ******************************************************************/
istream& operator>>(istream& is, Money& right)
{
	char decimal;
	is >> right.dollars;
	is >> decimal;
	is >> right.cents;
	while (right.cents >= 100) 
	{ 
		right.cents -= 100; 
		++right.dollars; 
	}
    return is;
}

/******************************************************************
 * Function Name: operator+
 * Incoming: Money, Money
 * Outgoing: Money
 * Return Value: Money
 * Description: Function uses the valueAsCents function to convert
 * 		both objects to just cent values, adds them, then uses 
 *		valueAsDollarsAndCents to convert back to dollars and cents, 
 *		and returns a new Money object with those values.
 ******************************************************************/
Money operator+ (const Money& left, const Money& right)
{
	return right.valueAsDollarsAndCents(left.valueAsCents() + right.valueAsCents());
}

/******************************************************************
 * Function Name: operator-
 * Incoming: Money, Money
 * Outgoing: Money
 * Return Value: Money
 * Description: Function uses the valueAsCents function to convert
 * 		both objects to just cent values, subtracts them, then uses 
 *		valueAsDollarsAndCents to convert back to dollars and cents, 
 *		and returns a new Money object with those values.
 ******************************************************************/
Money operator- (const Money& left, const Money& right)
{
	return left.valueAsDollarsAndCents(left.valueAsCents() - right.valueAsCents());
}

/******************************************************************
 * Function Name: operator++ (postfix)
 * Incoming: Money to be modified and dummy int for postfix
 * Outgoing: updated Money with increment
 * Return Value: previous Money prior to increment
 * Description: Increments dollar value by 1
 ******************************************************************/
Money operator++ (Money& amount, int)
{
	Money temp = amount;
	
	amount.dollars = amount.dollars += 1;
	
	return temp;
}

/******************************************************************
 * Function Name: operator++ (prefix)
 * Incoming: Money to be modified
 * Outgoing: updated Money with increment
 * Return Value: updated Money with increment
 * Description: Increments dollar value by 1
 ******************************************************************/
Money operator++ (Money& amount)
{
	return ++amount.dollars;
}

/******************************************************************
 * Function Name: operator-- (postfix)
 * Incoming: Money to be modified
 * Outgoing: updated Money with decrement
 * Return Value: updated Money with decrement
 * Description: Decrements dollar value by 1
 ******************************************************************/
Money Money::operator-- (int)
 {
 	Money temp = *this;
 	
 	--dollars;
 	return temp;
 }
 
 /******************************************************************
 * Function Name: operator-- (prefix)
 * Incoming: Money to be modified
 * Outgoing: updated Money with decrement
 * Return Value: updated Money with decrement
 * Description: Decrements dollar value by 1
 ******************************************************************/
Money Money::operator-- ()
 {
 	return --dollars;
 }
	
/******************************************************************
 * Function Name: operator==
 * Incoming: Money, Money
 * Outgoing: N/A
 * Return Value: bool
 * Description: Tests if the two money objects have the same value
 ******************************************************************/
bool operator== (const Money& left, const Money& right)
{
	return (left.dollars == right.dollars && left.cents == right.cents);
}

/******************************************************************
 * Function Name: operator!=
 * Incoming: Money, Money
 * Outgoing: N/A
 * Return Value: bool
 * Description: Tests if the two money objects are not equal
 ******************************************************************/
bool operator!= (const Money& left, const Money& right)
{
	return !(left == right);
}

/******************************************************************
 * Function Name: operator<
 * Incoming: Money, Money
 * Outgoing: N/A
 * Return Value: bool
 * Description: Tests if the left Money object is less than the 
 * 		right Money object.
 ******************************************************************/
bool operator< (const Money& left, const Money& right)
{
	return (left.dollars < right.dollars && left.cents < right.cents);
}

/******************************************************************
 * Function Name: operator<=
 * Incoming: Money, Money
 * Outgoing: N/A
 * Return Value: bool
 * Description: Tests if the left Money object is less than or  
 * 		equal to the right Money object.
 ******************************************************************/
bool operator<= (const Money& left, const Money& right)
{
	return (left < right || left == right);
}

/******************************************************************
 * Function Name: operator>
 * Incoming: Money, Money
 * Outgoing: N/A
 * Return Value: bool
 * Description: Tests if the left Money object is greater than the 
 * 		right Money object.
 ******************************************************************/
bool operator> (const Money& left, const Money& right)
{
	return !(left < right || left == right);
}

/******************************************************************
 * Function Name: operator>=
 * Incoming: Money, Money
 * Outgoing: N/A
 * Return Value: bool
 * Description: Tests if the left Money object is greater than or
 * 		equal to the right Money object.
 ******************************************************************/
bool operator>= (const Money& left, const Money& right)
{
	return (left > right || left == right);
}

/******************************************************************
 * Driver
 ******************************************************************/
int main() 
{
	Money cash1;
	Money cash2(38);
	Money cash3(0,-38);
	Money cash4(0,39);
	Money cash5(-12,37);
	bool answer;
	
	cout << "********************" << endl;
	cout << "First: " << cash1 << endl;
	cout << "Second: " << cash2 << endl;
	cout << "Third: " << cash3 << endl;
	cout << "Fourth: " << cash4 << endl;
	cout << "Fifth: " << cash5 << endl;
	cout << "********************" << endl << endl;
	
	cout << "Type in dollars and cents in the form 00.00" << endl;
	cin >> cash1;

	cout << "You entered: " << cash1 << endl;
	
	cout << cash2 << " + " << cash5 << " = ";
	cout << cash2 + cash5 << endl;
	
	cout << cash2 << " - " << cash3 << " = ";
	cout << cash2 - cash3 << endl;
	
	cout << cash3 << " - " << cash4 << " = ";
	cout << cash3 - cash4 << endl;
	
	cout << cash1 << " + " << cash5 << " = ";
	cout << cash1 + cash5 << endl;
	
	cout << cash4 << " != " << cash3 << " == ";
	answer = cash4 != cash3;
	if (answer != 0)
	{
		cout << "True" << endl;
	}
	
	else
	{
		cout << "False" << endl;
	}
		
	cout << endl << cash1 << "++" << endl;
	cout << cash1++ << endl;
	cout << cash1 << endl << endl;
	
	cash1.setDollars(0);
	
	cout << "++" << cash1 << endl;
	cout << ++cash1 << endl;
	cout << cash1 << endl << endl;
	
	cout << "--" << cash2 << endl;
	cout << --cash2 << endl;
	
	return 0;
}