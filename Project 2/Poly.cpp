#include "Poly.h"
#include <string>

/***************************************************************************
 * Name: Brian Moye
 * Class: CS 255-01
 * File name: Poly.cpp
 * Date: October 28, 2021
 * Assignment: Project 2
 * Description: Build your own polynomial class
 ***************************************************************************/
 
 /**************************************************************************
 * Function Name: Poly
 * Incoming: N/A
 * Outgoing: int array
 * Return Value: N/A
 * Description: Constructor
 **************************************************************************/
Poly::Poly()
{
	Reset();
}

 /**************************************************************************
 * Function Name: Eval
 * Incoming: double, int array
 * Outgoing: double
 * Return Value: double
 * Description: Evaluates the polynomial for a given value
 **************************************************************************/
double Poly::Eval(double x)
{
	double evaluated = 0;
	
	for (double i = 0; i < static_cast<double>(MAX) - 1; ++i)
	{
		evaluated += (pow(x, i) * terms[static_cast<int>(i)]);
	}
	
	return evaluated;
}

 /**************************************************************************
 * Function Name: Reset
 * Incoming: int array
 * Outgoing: N/A
 * Return Value: N/A
 * Description: Sets the array to all zeros
 **************************************************************************/
void Poly::Reset()
{
	for (unsigned int i = 0; i < MAX; ++i)
	{
		terms[i] = 0;
	}
}

 /**************************************************************************
 * Function Name: operator+=
 * Incoming: Poly
 * Outgoing: Poly
 * Return Value: N/A
 * Description: Adds the p array to the calling one
 **************************************************************************/
void Poly::operator+=(const Poly& p)
{
	for (int i = 0; i < static_cast<int>(MAX); ++i)
	{
		terms[i] += p.terms[i];
	}
}

/**************************************************************************
 * Function Name: Derivative
 * Incoming: Poly
 * Outgoing: Poly
 * Return Value: N/A
 * Description: Takes the derivative of a polynomial
 **************************************************************************/
void Poly::Derivative()
{
	for (int i = 1; i < static_cast<int>(MAX); ++i)
	{
		terms[i - 1] = terms[i] * i;
	}
}

/**************************************************************************
 * Function Name: operator>>
 * Incoming: istream, Poly
 * Outgoing: Poly, istream
 * Return Value: istream
 * Description: Takes user input and stores it in an array in Poly class
 **************************************************************************/
istream& operator>>(istream& is, Poly& p)
{
	size_t found_first = 0, found_second = 0;
	string input;
	int scalar = 0, exponent = 0, count = 0;
	const int STR_SIZE = input.size();
	bool cont = true;
	
	getline(is, input);
	
	while(cont)
	{
		if (input.compare(0, 1, "<") != 0)
		{
			cout << "Invalid input, must be of the form: <ax^b(+ax^b)>" << endl;
			break;
		}
		
		if (count == 0)
		{
			// get the position of the first "x^" in the string
			found_first = input.find("x^", 1);
			
			// create a substring from the 2nd character to skip the "<"
			// 	to the character before the "x^" and convert it to an int
			scalar = stoi(input.substr(1, found_first - 1));
			
			// get the position of the first "+"
			found_second = input.find("+", found_first + 2);
			
			// if there is no "+" go to the end of the string
			if (found_second == string::npos)
			{
				// disregard the terminating null character
				found_second = STR_SIZE - 1;
				
				// break out of the while loop after this iteration
				cont = false;
			}
			
			exponent = stoi(input.substr(found_first + 2, found_second - 1)); 
		}
		else
		{
			found_first = input.find("x^", found_second);
			scalar = stoi(input.substr(found_second + 1, found_first - 1));
			
			found_second = input.find("+", found_first + 2);
			
			if (found_second == string::npos)
			{
				found_second = STR_SIZE - 1;
				cont = false;
			}
			
			exponent = stoi(input.substr(found_first + 2, found_second - 1));
		}
		
		if (exponent > 20)
		{
			cout << "Invalid input, polynomials larger than x^20 not supported." << endl;
			break;
		}
		else
		{
			p.terms[exponent] = scalar;
		}
	
		++count;
	}
	
	return is;
}

/**************************************************************************
 * Function Name: operator<<
 * Incoming: ostream, Poly
 * Outgoing: Poly, ostream
 * Return Value: ostream
 * Description: Takes a Poly object and outputs it for the user to see
 **************************************************************************/
ostream& operator<<(ostream& os, const Poly& p)
{
	int numInts = 0;
	
	cout << "<";
	
	// MAX being 21 cause weird things to happen sometimes when displaying, 
	//		so I subtracted it to 20 here.
	for (int i = static_cast<int>(MAX) - 1; i >= 0; --i)
	{
		if (p.terms[i] != 0)
		{
			++numInts;
			
			// if there's only a constant term, display just the scalar
			if (numInts == 1 && i == 0)
			{
				cout << p.terms[i];
			}
			// display for the start of the polynomial
			else if (numInts == 1)
			{
				cout << p.terms[i] << "x^" << i;
			}
			// display for "x^0"
			else if (i == 0)
			{
				cout << "+" << p.terms[i];
			}
			else
			{
				cout << "+" << p.terms[i] << "x^" << i;
			}
		}
	}
	cout << ">";
	
	return os;
}

/**************************************************************************
 * Function Name: operator+
 * Incoming: Poly, Poly
 * Outgoing: N/A
 * Return Value: Poly
 * Description: Adds one Poly to another and returns it without changing
 * 		the added Poly's
 **************************************************************************/
Poly operator+(const Poly& p1, const Poly& p2)
{
	Poly added;
	
	for (int i = 0; i < static_cast<int>(MAX); ++i)
	{
		added.terms[i] = p1.terms[i] + p2.terms[i];
	}
	
	return added;
}

/**************************************************************************
 * Function Name: operator*
 * Incoming: Poly, Poly
 * Outgoing: N/A
 * Return Value: Poly
 * Description: Multiplies one Poly by another and returns them 
 *		without changing the Poly's
 **************************************************************************/
Poly operator*(const Poly& p1, const Poly& p2)
{
	Poly multiplied;
	
	for (int i = 0; i < static_cast<int>(MAX); ++i)
	{
		multiplied.terms[i] = p1.terms[i] * p2.terms[i];
	}
	
	return multiplied;
}

