/***************************************************************************
 * Name: Brian Moye
 * Class: CS 255-01
 * File name: MoyeBrian-255-P1.cpp
 * Date: October 4, 2021
 * Assignment: Fraction Calculator
 * Description: 
 ***************************************************************************/
 
#include <iostream>
#include "Fraction.h"
#include <windows.h>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <algorithm>

using namespace std;

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

void menuSelectionChecker(vector<string> const& entries, int choice)
{
	if (choice < 0 || choice > entries.size() - 1)
	{
		clear_screen();
		cout << "Invalid selection, please choose again." << endl;
		displayMenu(entries);
	}
}

Fraction generateRandomFraction()
{
	Fraction temp(rand() % 20 + 1, rand() % 20 + 1);

	return temp;
}

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

Fraction compareFractions(const Fraction& left, const Fraction& right)
{
	const vector<string> relations = {"<", ">", "<=", ">=", "!=", "=="};
	int selection;
	string temp;
	Fraction f;
	
	selection = 1;//rand() % 5 + 1;
	
	switch (selection)
	{
		case 0:
			return f;
		
		default: case 1:
			cout << endl;
			cout << "True or False: " << left << " " << relations[selection - 1] << " " << right << endl;
			cin >> temp;
			cout << endl;
			
			transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
			
			if ((temp == "true" && left < right) || (temp == "false" && left > right))
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
			compareFractions(left, right);
	}
}

int main() 
{
	srand(time(NULL));
	
	Fraction one, two, didSomething;
	int choice;
	const vector<string> mainMenu{"Please select an option below:", "0. Exit", 
		"1. Add/Subtract/Multiply/Divide/Increment/Decrement fractions.", "2. Compare two fractions.", 
		"3. Practice fraction reduction.", "4. Choose new fractions"};
	const vector<string> randomOrInputFractions{"Would you like to enter your own fraction(s) or have them be random?", 
		"1. Enter your own.", "2. Have them be random."};
	
	cout << "Welcome to the Fraction Calculator." << endl;
	
	chooseNewFractions(randomOrInputFractions, one, two);
	
	while (true)
	{
		clear_screen();
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
				didSomething = doMath(one, two);
				break;
				
			case 2: 
				clear_screen();
				compareFractions(one, two);
				break;
				
			case 3:
				//clear_screen();
				//reductionPractice();
				break;
				
			case 4:
				clear_screen();
				chooseNewFractions(randomOrInputFractions, one, two);
				break;
		}
	}
	
	return 0;
}