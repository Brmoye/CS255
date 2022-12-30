/** 
 * Name: Brian Moye
 * Date: 08/23/2021
 * Course: CS255-01
 * Description: Homework review #2 asked us to write 5 functions in one file to
 * manipulate arrays in various ways.
 */
 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>


using namespace std;

int readFile(int fileValues[], string fileName);
void printArray(int someArray[], int numItems);
bool sumEvenOrOdd(int someArray[], int arraySize);
void numEvens(int** someArrays, int numRows, int numCols, int& countEvens);
void print2DArray(int** someArrays, int numRows, int numCols);

int main()
{
    int fileValues[9001];
    int arraySize;
    int someArrays[3][5] = { {412, 765, 672, 831, 167}, {232, 567, 276, 135, 918}, {47, 32, 75, 63, 84} };
    int numRows = 3;
	int numCols = 5;
	int countEvens = 0;
	int *callingArray[numRows];
    string userFile;
    
    // Assign pointers to array rows for function calls
    for (int i = 0; i < numRows; ++i) 
	{
	    callingArray[i] = someArrays[i];
	}

	// First function call
	cout << "Function 1:" << endl;
    cout << "Please input filename, include '.txt'" << endl;
    cin >> userFile;
	
    arraySize = readFile(fileValues, userFile);
	
    // Second function call
    cout << endl << "Function 2:" << endl;
    printArray(fileValues, arraySize);
    
    // Third function call
    cout << endl << "Function 3:" << endl;
    cout << "Sum of array is even: ";
    if(sumEvenOrOdd(fileValues, arraySize))
	{
		cout << "True" << endl;
	}
	
	else 
	{
		cout << "False" << endl;
	}
	
	// Fourth function call
	cout << endl << "Function 4:" << endl;
	numEvens(callingArray, numRows, numCols, countEvens);
	cout << "The number of evens in the arrays is: " << countEvens << endl;
	
	// Fifth function call
	cout << endl << "Function 5:" << endl;
	print2DArray(callingArray, numRows, numCols);
    
}

/* Function 1
 * Write a function that will take an integer array and a string file name as a parameter. 
 * The first value in the file will specify how many values are in the file.  Read that 
 * number of values from the file into the array starting at subscript 0.  Be sure to pass 
 * back the number of items in the array
 */ 
int readFile(int fileValues[], string fileName)
{
    int numVals = 0;
    int fileVal;
    ifstream theFile(fileName.c_str());

    if (theFile.good()) 
    {
        theFile >> numVals;
        for(int i = 0; i < numVals && theFile.good(); ++i)
        {
            theFile >> fileVal;
            fileValues[i] = fileVal;
        }
    }

    return numVals;
}

/* Function 2
 * Write a function that will take an integer array and the number of items in the array.  
 * Print these items.
 */
void printArray(int someArray[], int numItems)
{
	cout << "Number of items in the array: " << numItems << endl;
	cout << "[";
	for(int i = 0; i < numItems; ++i)
	{
		if(i == numItems - 1)
		{
			cout << someArray[i] << "]" << endl;
		}
		else 
		{
			cout << someArray[i] << ", ";
		}
	}
}

/* Function 3
 * Write a function that will take an integer array and its size as parameters.  Return true if 
 * the sum of the items in the array is even and false if it is odd
 */
bool sumEvenOrOdd(int someArray[], int arraySize)
{
	int sum = 0;
	
	for(int i = 0; i < arraySize; ++i)
	{
		sum += someArray[i];
	}
	
	if(sum % 2 == 0)
	{
		return true;
	}
	
	else
	{
		return false;
	}
}

/* Function 4
 * Write a function that takes in a 2-D array, the number of rows, & the number of columns.  Pass 
 * back as a parameter the number of even numbers in the 2-D array.
 *
 * I spent a lot of time trying to figure this out on my own, but couldn't so my brother
 * Charles Moye helped me with a lot of it. The compiler kept saying: 
 * [Error] cannot convert 'int (*)[5]' to 'int*'
 * and I was stuck, so my brother suggested pointers.
 */
void numEvens(int** someArrays, int numRows, int numCols, int& countEvens)
{
	for(int i = 0; i < numRows; ++i)
	{
		for(int j = 0; j < numCols; ++j)
		{
			if(someArrays[i][j] % 2 == 0)
			{
				++countEvens;
			}
		}
	}
}

/* Function 5
 * Write a function that takes in a 2-D array, the number of rows & the number of columns.  Print 
 * the contents of the 2-D array in row-major order
 */
void print2DArray(int** someArrays, int numRows, int numCols)
{
	cout << "[";
	for(int i = 0; i < numRows; ++i)
	{
		if(i > 0)
		{
			cout << " ";
		}
		
		cout << "[";
		
		for(int j = 0; j < numCols; ++j)
		{
			cout << setw(5) << someArrays[i][j];
			if(j != numCols - 1)
			{
				cout << ", ";
			}
		}
		if(i != numRows - 1)
		{
			cout << "]," << endl;
		}
	}
	cout << "]]" << endl;
}

