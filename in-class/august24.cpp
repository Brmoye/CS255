/************************************************************
 * Name: Brian Moye
 * Class: CS 255-01
 * Date: August 24, 2021
 * Assignment: In-class Exercise
 * Description: A series of functions
 * 		to manipulate arrays (1-D and 2-D)
 ************************************************************/

#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

/************************************************************
 * Constants
 ************************************************************/
const int MAX = 10;
const int ROW = 10;
const int COL = 10;

/************************************************************
 * Function Declarations
 ************************************************************/
void FillArray(int ar[], int& size);
void PrintArray(int list[], int size);
void FillMatrix(int mat[][COL], int& row, int& col);
void PrintMatrix(int mat[][COL], int row, int col);

/************************************************************
 * Driver
 ************************************************************/
int main()
{
	//srand(time(NULL));
	/*
	int list[MAX];
	int size = 0;
	int list2[MAX];
	int size2 = 0;

	FillArray(list, size);
	PrintArray(list, size);
	cout << endl;
	FillArray(list, size);
	PrintArray(list, size);
	cout << endl;
	FillArray(list2, size2);
	PrintArray(list2, size2);
	cout << endl;
	*/

	int table[ROW][COL];
	int row = 0, col = 0;
	FillMatrix(table, row, col);
	PrintMatrix(table, row, col);
	

	return 0;
}

/************************************************************
 * Function Definitions
 ************************************************************/

/************************************************************
 * Function Name: FillArray
 * Incoming Parameters: NA
 * Outgoing Parameters: Modified Integer array
 * 						modified array size
 * Return Value: NA
 * Description: Function to randomly generate
 * 	the usable size of the array and fill the 
 *  array with items randomly in the range of [0..20]
 ************************************************************/
void FillArray(int ar[], int& size)
{
	size = rand() % MAX + 1;
	for(int i = 0; i < MAX; ++i)
	{
		ar[i] = rand() % 21;
	}
}

/************************************************************
 * Function Name: PrintArray
 * Incoming Parameters: Integer Array and size
 * Outgoing Parameters: NA
 * Return Value: NA
 * Description: Function to print the logical contesnts
 * 		of the array
 ************************************************************/
void PrintArray(int list[], int size)
{
	for(int i = 0; i < size; ++i)
	{
		cout << list[i] << "\t";
	}
}

/************************************************************
 * Function Name: FillMatrix
 * Incoming Parameters: 
 * Outgoing Parameters: 
 * Return Value: 
 * Description: 
 * 
 ************************************************************/
void FillMatrix(int mat[][COL], int& row, int& col)
{
	ifstream ifile;

	ifile.open("funtimes.txt");

	if(ifile.fail())
	{
		cout << "NO FILE FOUND" << endl;
		exit(1);
	}

	ifile >> row >> col;	

	for(int r = 0; r < row; ++r)
	{
		for(int c = 0; c < col; ++c)
		{
			ifile >> mat[r][c];
		}
	}
	
	ifile.close();
	
}

/************************************************************
 * Function Name: PrintMatrix
 * Incoming Parameters: 
 * Outgoing Parameters: 
 * Return Value: 
 * Description: 
 * 
 ************************************************************/
void PrintMatrix(int mat[][COL], int row, int col)
{
	for(int r = 0; r < row; ++r)
	{
		for(int c = 0; c < col; ++c)
		{
			cout << mat[r][c] << "\t";
		}

		cout << endl;
	}
}