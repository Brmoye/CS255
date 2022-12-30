/***************************************************************************
 * Name: Brian Moye
 * Class: CS 255-01
 * File name: MoyeBrian-255-P1.cpp
 * Date: October 4, 2021
 * Assignment: Fraction Calculator
 * Description: A program to let someone practice doing math or comparisons
 * 	on fractions. Not, strictly speaking, a calculator in the usual sense.
 ***************************************************************************/
 
#include <iostream>		// console input/output
#include "Fraction.h"	// Fraction class
#include <windows.h>	// to clear console
#include <vector>		// for vectors
#include <stdlib.h>		// for rand, srand
#include <time.h>		// for time
#include <string>		// for strings
#include <algorithm>	// for transform

using namespace std;

// function declaration so it can be used in scope
void menuSelectionChecker(vector<string> const& entries, int choice);

/***************************************************************************
 * Function Name: clear_screen
 * Incoming: char
 * Outgoing: N/A
 * Return Value: N/A
 * Description: Function I found online that clears the Windows console 
 * 	screen when called because system("cls") is a no-no.
 *  https://stackoverflow.com/questions/5866529/how-do-we-clear-the-console-in-assembly/5866648#5866648
 ***************************************************************************/
void clear_screen(char fill = ' ') 
{ 
    COORD tl = {0,0};
    CONSOLE_SCREEN_BUFFER_INFO s;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);   
    GetConsoleScreenBufferInfo(console, &s);
    DWORD written, cells = s.dwSize.X * s.dwSize.Y;
    FillConsoleOutputCharacter(console, fill, cells, tl, &written);
    FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
    SetConsoleCursorPosition(console, tl);
}

/***************************************************************************
 * Function Name: displayMenu
 * Incoming: vector
 * Outgoing: int
 * Return Value: int
 * Description: displays a menu for the user to make a selection
 ***************************************************************************/
int displayMenu(vector<string> const& entries)
{
	int choice;
	
	for (int entry = 0; entry < entries.size(); entry++)
	{
		cout << entries[entry] << endl;
	}
	
	cin >> choice;
	
	menuSelectionChecker(entries, choice);
	
	return choice;
}

/***************************************************************************
 * Function Name: menuSelectionChecker
 * Incoming: vector, int
 * Outgoing: n/a
 * Return Value: n/a
 * Description: checks for mostly valid user selection. Does not currently
 *	work perfectly for all of the functions, but could implement a fix.
 ***************************************************************************/
void menuSelectionChecker(vector<string> const& entries, int choice)
{
	if (choice < 0 || choice > entries.size() - 1)
	{
		clear_screen();
		cout << "Invalid selection, please choose again." << endl;
		displayMenu(entries);
	}
}

/***************************************************************************
 * Function Name: generateRandomFraction
 * Incoming: n/a
 * Outgoing: Fraction
 * Return Value: Fraction
 * Description: returns a randomly generated Fraction
 ***************************************************************************/
Fraction generateRandomFraction()
{
	// generates a fraction with a random numerator and denominator 
	//	between 1 and 20
	Fraction temp(rand() % 20 + 1, rand() % 20 + 1);

	return temp;
}

/***************************************************************************
 * Function Name: getUserFractions
 * Incoming: Fraction, Fraction
 * Outgoing: Fraction, Fraction
 * Return Value: n/a
 * Description: gets user input for 1 or 2 fractions
 ***************************************************************************/
void getUserFractions(Fraction& one, Fraction& two)
{
	const vector<string> isItRandom{"Would you like to enter both fractions or have one be random?", 
		"1. Enter one.", "2. Enter both."};

	clear_screen();
	
	if (displayMenu(isItRandom) == 1)
	{
		cout << "Enter a fraction in the form 2/3: ";
		cin >> one;
		
		two = generateRandomFraction();
	}
	
	else
	{
		cout << "Enter a fraction in the form 2/3: ";
		cin >> one;
		
		cout << endl << "Enter another fraction: ";
		cin >> two;
	}
}

/***************************************************************************
 * Function Name: chooseNewFractions
 * Incoming: vector, Fraction, Fraction
 * Outgoing: Fraction, Fraction
 * Return Value: n/a
 * Description: lets the user pick new fractions
 ***************************************************************************/
void chooseNewFractions(vector<string> const& menu, Fraction& one, Fraction& two)
{
	int choice = displayMenu(menu);
	
	switch (choice)
	{
		case 1:
			getUserFractions(one, two);
			break;
			
		default: case 2: 
			one = generateRandomFraction();
			two = generateRandomFraction();
			break;
	}
}

/***************************************************************************
 * Function Name: doMath
 * Incoming: Fraction, Fraction
 * Outgoing: Fraction, Fraction
 * Return Value: Fraction
 * Description: does the math operations on the Fractions without
 *	changing them.
 ***************************************************************************/
Fraction doMath(const Fraction& left, const Fraction& right)
{
	int choice;
	const vector<string> mathMenu{"Please select an option below:", "0. Main menu", "1. Addition",
		"2. Subtraction", "3. Multiplication", "4. Division", "5. Increment", "6. Decrement"};
	Fraction temp, temp2;
	
	while (true)
	{
		choice = displayMenu(mathMenu);
		switch (choice)
		{
			default: case 0:
				clear_screen();
				return temp;
				
			case 1:
				cout << endl;
				cout << left << " + " << right << " = ";
				cin >> temp;
				cout << endl;
				
				if (temp == left + right)
				{
					cout << "Correct!" << endl;
				}
				
				else 
				{
					cout << "Incorrect, correct answer is " << left + right << endl; 
				}
				
				cout << endl;
				
			 	continue;
				
			case 2:
				cout << endl;
				cout << left << " - " << right << " = ";
				cin >> temp;
				cout << endl;
				
				if (temp == left - right)
				{
					cout << "Correct!" << endl;
				}
				
				else 
				{
					cout << "Incorrect, correct answer is " << left - right << endl; 
				}
				
				cout << endl;
				
			 	continue;
				
			case 3:
				cout << endl;
				cout << left << " * " << right << " = ";
				cin >> temp;
				cout << endl;
				
				if (temp == left * right)
				{
					cout << "Correct!" << endl;
				}
				
				else 
				{
					cout << "Incorrect, correct answer is " << left * right << endl; 
				}
				
				cout << endl;
				
			 	continue;
			
			case 4:
				cout << endl;
				cout << "(" << left << ")" << " / " << "(" << right << ")" << " = ";
				cin >> temp;
				cout << endl;
				
				if (temp == left / right)
				{
					cout << "Correct!" << endl;
				}
				
				else 
				{
					cout << "Incorrect, correct answer is " << left / right << endl; 
				}
				
				cout << endl;
				
			 	continue;
				
			case 5:
				cout << endl;
				cout << left << "++ = ";
				cin >> temp;
				cout << endl;
				temp2 = left;
				++temp2;
				
				if (temp == temp2)
				{
					cout << "Correct!" << endl;
				}
				
				else 
				{
					cout << "Incorrect, correct answer is " << temp2 << endl; 
				}
				
				cout << endl;
				
			 	continue;
				
			case 6:
				cout << endl;
				cout << left << "-- = ";
				cin >> temp;
				cout << endl;
				temp2 = left;
				--temp2;
				
				if (temp == temp2)
				{
					cout << "Correct!" << endl;
				}
				
				else 
				{
					cout << "Incorrect, correct answer is " << temp2 << endl; 
				}
				
				cout << endl;
				
			 	continue;
		}
	}
}

/***************************************************************************
 * Function Name: compareHelper
 * Incoming: Fraction, Fraction, string
 * Outgoing: string
 * Return Value: string
 * Description: converts user inputted string to lowercase and returns it,
 * 	found it online when searching for a tolower bult-in function for C++
 *	https://stackoverflow.com/questions/3403844/tolower-function-for-c-strings
 ***************************************************************************/
string compareHelper(const Fraction& left, const Fraction& right, string operation)
{
	string correctOrNot;
	
	cout << endl;
	cout << "True or False: " << left << " " << operation << " " << right << endl;
	cin >> correctOrNot;
	cout << endl;
	
	// converts the user input to all lowercase letters for comparison
	transform(correctOrNot.begin(), correctOrNot.end(), correctOrNot.begin(), ::tolower);
	
	return correctOrNot;
}

/***************************************************************************
 * Function Name: compareFractions
 * Incoming: Fraction, Fraction
 * Outgoing: Fraction
 * Return Value: Fraction
 * Description: does comparison operations on two fractions and tells the 
 *	user if they are correct or not.
 ***************************************************************************/
void compareFractions(const Fraction& left, const Fraction& right)
{
	const vector<string> relations = {"<", ">", "<=", ">=", "!=", "=="};
	string userInput;
	Fraction f;
	
	for (int selection = 0; selection < 6; ++selection)
	{
		switch (selection)
		{
			case 0:
				userInput = compareHelper(left, right, relations[selection]);
				
				if ((userInput == "true" && left < right) || (userInput == "false" && left > right))
				{
					cout << "Correct!" << endl;
				}
				
				else 
				{
					cout << "Incorrect, correct answer is "; 
					if (!(left < right) == 0)
					{
						cout << "True" << endl; 
					}
					
					else
					{
						cout << "False" << endl; 
					}
				}
				
				cout << endl;
				continue;
				
			case 1:
				userInput = compareHelper(left, right, relations[selection]);
				
				if ((userInput == "true" && left > right) || (userInput == "false" && left < right))
				{
					cout << "Correct!" << endl;
				}
				
				else 
				{
					cout << "Incorrect, correct answer is "; 
					if (!(left > right) == 0)
					{
						cout << "True" << endl; 
					}
					
					else
					{
						cout << "False" << endl; 
					}
				}
				
				cout << endl;
				continue;
			
			case 2:
				userInput = compareHelper(left, right, relations[selection]);
				
				if ((userInput == "true" && left <= right) || (userInput == "false" && left > right))
				{
					cout << "Correct!" << endl;
				}
				
				else 
				{
					cout << "Incorrect, correct answer is "; 
					if (!(left <= right) == 0)
					{
						cout << "True" << endl; 
					}
					
					else
					{
						cout << "False" << endl; 
					}
				}
				
				cout << endl;
				continue;
				
			case 3:
				userInput = compareHelper(left, right, relations[selection]);
				
				if ((userInput == "true" && left >= right) || (userInput == "false" && left < right))
				{
					cout << "Correct!" << endl;
				}
				
				else 
				{
					cout << "Incorrect, correct answer is "; 
					if (!(left >= right) == 0)
					{
						cout << "True" << endl; 
					}
					
					else
					{
						cout << "False" << endl; 
					}
				}
				
				cout << endl;
				continue;
				
			case 4:
				userInput = compareHelper(left, right, relations[selection]);
				
				if ((userInput == "true" && left != right) || (userInput == "false" && left == right))
				{
					cout << "Correct!" << endl;
				}
				
				else 
				{
					cout << "Incorrect, correct answer is "; 
					if (!(left != right) == 0)
					{
						cout << "True" << endl; 
					}
					
					else
					{
						cout << "False" << endl; 
					}
				}
				
				cout << endl;
				continue;
				
			case 5:
				userInput = compareHelper(left, right, relations[selection]);
				
				if ((userInput == "true" && left == right) || (userInput == "false" && left != right))
				{
					cout << "Correct!" << endl;
				}
				
				else 
				{
					cout << "Incorrect, correct answer is "; 
					if (!(left == right) == 0)
					{
						cout << "True" << endl; 
					}
					
					else
					{
						cout << "False" << endl; 
					}
				}
				
				cout << endl;
				continue;
				
			default: case 6:
				break;
		}
	}
}

/***************************************************************************
 * Function Name: reductionPractice
 * Incoming: Fraction
 * Outgoing: n/a
 * Return Value: n/a
 * Description: asks the user to reduce a random fraction and checks their 
 * 	answer.
 ***************************************************************************/
void reductionPractice(const Fraction& toBeReduced)
{
	Fraction userInput, reducedFrac, reducedUserFrac;
	
	cout << "Please reduce " << toBeReduced << " if possible, if not enter " << toBeReduced << endl;
	cin >> userInput;
	cout << endl;
	
	reducedFrac = toBeReduced;
	reducedFrac.reduce();
	reducedUserFrac = userInput;
	reducedUserFrac.reduce();
	
	if (isExact(userInput, reducedFrac) != 0)
	{
		cout << "Correct reduction!" << endl << endl;
	}
	
	else if (reducedUserFrac == reducedFrac)
	{
		cout << "Incorrect reduction, but equivalent." << endl;
		cout << "Correct answer was: " << reducedFrac << endl << endl;
	}
	
	else
	{
		cout << "Incorrect reduction." << endl;
		cout << "Correct answer was " << reducedFrac << endl << endl;
	}
}

/***************************************************************************
 * Driver
 ***************************************************************************/
int main() 
{
	srand(time(NULL));
	
	Fraction one, two, didSomething;
	int choice;
	const vector<string> mainMenu{"Please select an option below:", "0. Exit", 
		"1. Add/Subtract/Multiply/Divide/Increment/Decrement fractions.", "2. Compare two fractions", 
		"3. Practice fraction reduction with a random fraction.", "4. Choose new fractions"};
	const vector<string> randomOrInputFractions{"Would you like to enter your own fraction(s) or have them be random?", 
		"1. Enter your own.", "2. Have them be random."};
	
	cout << "Welcome to the Fraction Calculator." << endl;
	
	chooseNewFractions(randomOrInputFractions, one, two);
	
	while (true)
	{
		//clear_screen();
		cout << "Your fractions are: " << endl;
		cout << one << endl;
		cout << two << endl;
		cout << endl; // add some space
		
		choice = displayMenu(mainMenu);
		
		switch (choice)
		{
			default: case 0:
				return 0;
				
			case 1:
				clear_screen();
				// thought I might do something with the returned fraction, but 
				//	decided not to for now. Could change function to void.
				didSomething = doMath(one, two);
				break;
				
			case 2: 
				clear_screen();
				compareFractions(one, two);
				break;
				
			case 3:
				clear_screen();
				reductionPractice(generateRandomFraction());
				break;
				
			case 4:
				clear_screen();
				chooseNewFractions(randomOrInputFractions, one, two);
				break;
		}
	}
	
	return 0;
}