#include <iostream>

using namespace std;

int main()
{
	int* ptr; // declares an integer pointer variable
			  // statically allocated variable to main
	ptr = nullptr; // initializes the pointer to null
	ptr = new int; // dynamically allocates a single integer
				   // and assigns its address to ptr
	
	*ptr = 10; // stores 10 in the integer variable referred to by ptr
	
	int* ptr2 = ptr; // another poiner pointing to the 
					// dynamically allocated integer
					
	//delete ptr; // deallocates the integer variable that ptr points to
	
	//ptr = nullptr;
	
	cout << "Value pointed to by ptr: " << *ptr << endl;
	cout << "Value in ptr: " << ptr << endl;
	cout << "Value in ptr2: " << ptr2 << endl;
	
	return 0;
}