/** 
 * Name: Brian Moye
 * Date: 08/22/2021
 * Course: CS255-01
 * Description: Homework review #1 asked us to write a loop that prints the alphabet backwards. Write a loop
 * that takes 10 integers from a file and returns the minimum. And write a loop to fill an integer array with
 * random values in the range of [20.. 40] all in one file.
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime> 
#include <string>

using namespace std;

int main()
{
    const int ARRAY_SIZE = 12;
    int numbers[ARRAY_SIZE] ;
    int randomNumbers[ARRAY_SIZE];
    int count = 0;
    int minNum = 0;

    // The following two lines were provided in class by Dr. Jenkins
    for (char letter = 'Z'; letter >= 'A'; --letter)
    {
        cout << letter << '\t' << int(letter) << endl;
    }

    // The following I looked at the projects I did at NWSCC for the C++ class there
    // the book used for that class was Gaddis, T. (2017). Starting Out with C++ from Control Structures to Objects. 9th Edition.
    ifstream myFile("integers.txt");

    if (myFile.is_open()) 
    {
        while (count < ARRAY_SIZE && myFile.good()) {
            myFile >> numbers[count];
            ++count;
        }

        myFile.close();

        minNum = numbers[0];

        for (int i = 0; i < count; ++i)
        {
            if (numbers[i] < minNum)
            {
                minNum = numbers[i];
            }
        }

        cout << "The minimum is: " << minNum << endl;
    }

    // The following I pulled in part from the book Malik, D. S. (2018). C++ Programming: Program Design including Data Strutures, 8th Edition
    
	srand(time(0));
	
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        randomNumbers[i] = rand() % 20 + 20;
    }

    for (int num = 0; num < ARRAY_SIZE; ++num)
    {
        cout << randomNumbers[num] << ' ';
    }

    cout << endl;

    return 0;

}

