#include <iostream>

using namespace std;

int main()
{
	// statically allocated memory is automatically allocated and therefore automatically deallocated.
	// dynamically allocated memory needs to be dynamically deallocated.
	
	
	int* ar = nullptr; 	// creates an integer pointer that can point to an integer
					   	// it is set to nullptr, which implies it points to "nothing"
					   	// the pointer variable ar is a statically allocated variable, 
					   	// space can be and is decided at compile time.
	
	int size = 0;		// size is a statically allocated integer variable initialized to 0
	
	cout << "How many elements do you want in your array?" << endl;
	cin >> size;
	
	ar = new int[size];	// dynamically allocated integer array of size, size
	
	for(int i = 0; i < size; ++i)
	{
		ar[i] = i * 10;
	}
	
	for(int i = 0; i < size; ++i)
	{
		cout << ar[i] << "\t";
	}
	
	cout << endl;
	
	delete [] ar; // dynamically deallocate the memory ar points to
	
	ar = nullptr;
					   
	return 0;
}