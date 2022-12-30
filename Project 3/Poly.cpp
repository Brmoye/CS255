#include "Poly.h"
#include <string>
// ***********************************************
// Shell code provided by Dr. Janet T. Jenkins
// You should comment each method and add
// header comments below these comments
// ***********************************************

/***************************************************************************
 * Name: Brian Moye
 * Class: CS 255-01
 * File name: Poly.cpp
 * Date: November 30, 2021
 * Assignment: Project 3
 * Description: Use a Linked List to implement the previous polynomial project
 ***************************************************************************/
 
Node::Node():coeff(0), degree(0){}
Node::Node(int c, int d):coeff(c), degree(d), next(nullptr){}
Node::Node(int c, int d, Node* n):coeff(c), degree(d), next(n){}
	
 /**************************************************************************
 * Function Name: Poly
 * Incoming: N/A
 * Outgoing: N/A
 * Return Value: N/A
 * Description: Constructor
 **************************************************************************/
Poly::Poly():head(nullptr)
{
	
}

 /**************************************************************************
 * Function Name: Copy
 * Incoming: Poly
 * Outgoing: Poly
 * Return Value: N/A
 * Description: Performs a deep copy of the Linked List if it isn't empty
 **************************************************************************/
void Poly::Copy(const Poly& p)
{
	if(p.head != nullptr)
	{
		Node* temp = p.head;
		Node* curr = head;

		head = new Node(temp-> coeff, temp-> degree);
		
		temp = temp-> next;
		
		while(temp != nullptr)
		{
			curr-> next = new Node(temp-> coeff, temp-> degree);
			temp = temp-> next;
			curr = curr-> next;
		}
	}
}

 /**************************************************************************
 * Function Name: Poly
 * Incoming: Poly
 * Outgoing: Poly
 * Return Value: N/A
 * Description: Copy Constructor
 **************************************************************************/
Poly::Poly(const Poly& p)
{
	Copy(p);
}

 /**************************************************************************
 * Function Name: operator=
 * Incoming: Poly
 * Outgoing: Poly
 * Return Value: N/A
 * Description: Copy Assignment Operator
 **************************************************************************/
Poly& Poly::operator= (const Poly& p)
{
	if (this == &p)
		return *this;
	if (head != nullptr)
		Reset();
	Copy(p);
	return *this;
	
}

 /**************************************************************************
 * Function Name: ~Poly
 * Incoming: N/A
 * Outgoing: N/A
 * Return Value: N/A
 * Description: Destructor
 **************************************************************************/
Poly::~Poly()
{
	Reset();
}

 /**************************************************************************
 * Function Name: AddTerm
 * Incoming: int, int
 * Outgoing: N/A
 * Return Value: N/A
 * Description: Add's items to the linked list
 **************************************************************************/
void Poly::AddTerm(int c, int d)
{
	if(head == nullptr || head-> degree < d)
	{
		head = new Node(c, d, head);
	}
	else
	{
		Node* prev = head;
		Node* curr = head;
		
		while(curr != nullptr && d < curr-> degree)
		{
			prev = curr;
			curr = curr-> next;
		}
		if(curr == nullptr)
		{
			prev-> next = new Node(c,d);
		}
		else if(curr-> degree == d)
		{
			curr-> coeff += c;
		}
		else 
		{
			prev-> next = new Node(c,d, curr);
		}
	}
}

 /**************************************************************************
 * Function Name: Eval
 * Incoming: double
 * Outgoing: double
 * Return Value: double
 * Description: Evaluates the polynomial for a given value
 **************************************************************************/
double Poly::Eval(double x)
{
	Node* curr = head;
    double evaluated = 0;
	
	while(curr != nullptr)
	{
		evaluated += curr-> coeff * pow(x, curr-> degree);
		curr = curr-> next;
	}
	
	return evaluated;
}

/**************************************************************************
 * Function Name: Reset
 * Incoming: N/A
 * Outgoing: Poly
 * Return Value: N/A
 * Description: Deletes each node in the linked list to clear it
 **************************************************************************/
void Poly::Reset()
{
	Node* temp = head;

	while(head != nullptr)
	{
		temp = head-> next;
		delete head;
		head = temp;
	}
}

/**************************************************************************
 * Function Name: Derivative
 * Incoming: N/A
 * Outgoing: Poly
 * Return Value: N/A
 * Description: Gets the derivative of the given polynomial
 **************************************************************************/
void Poly::Derivative()
{
	if(head != nullptr)
	{
		Node* curr = head;
		Node* prev = head;

		while(curr != nullptr)
		{
			if(curr-> degree == 0)
			{
				prev-> next = nullptr;
				delete curr;
				curr = nullptr;
			}
			else
			{
				curr-> coeff = curr-> coeff * curr-> degree;
				curr-> degree -= 1;
				prev = curr;
				curr = curr-> next;
			}
		}
	}
}

/**************************************************************************
 * Function Name: operator>>
 * Incoming: iostream, Poly
 * Outgoing: Poly
 * Return Value: iostream
 * Description: Takes user input and assigns it to a polynomial
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
			cont = false;
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
	
		p.AddTerm(scalar, exponent);

	
		++count;
	}

	return is;
}

/**************************************************************************
 * Function Name: operator<<
 * Incoming: ostream, Poly
 * Outgoing: N/A
 * Return Value: ostream
 * Description: Prints a given polynomial
 **************************************************************************/
ostream& operator<<(ostream& os, const Poly& p)
{
    if(p.head != nullptr)
	{
		Node* curr = p.head;

		cout << "<";
		while(curr != nullptr)
		{
			if(curr-> degree == p.head-> degree)
			{
				cout << curr-> coeff << "x^" << curr-> degree;
			}
			else if(curr-> degree != 0)
			{
				cout << "+" << curr-> coeff << "x^" << curr-> degree;
			}
			else
			{
				cout << "+" << curr-> coeff;
			}
			curr = curr-> next;
		}

		cout << ">";
	}
	else
	{
		cout << "<>";
	}
	
	return os;
}

/**************************************************************************
 * Function Name: operator+
 * Incoming: Poly, Poly
 * Outgoing: N/A
 * Return Value: Poly
 * Description: Returns two given polynomials added together
 **************************************************************************/
Poly operator+(const Poly& p1, const Poly& p2)
{
	Poly result;
	Node* first = p1.head;
	Node* second = p2.head;
	
	while(first != nullptr)
	{
		result.AddTerm(first-> coeff, first-> degree);
		first = first->next;
		cout << "First" << endl;
	}
	while(second != nullptr)
	{
		result.AddTerm(second-> coeff, second-> degree);
		second = second-> next;
		cout << "Second" << endl;
	}

	return result;
}



