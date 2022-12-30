#include <iostream>

using namespace std;

int main()
{
	int ar[10] = {10, 20, 30, 40, 50};
	int size = 5;

	for(int i = 0; i < size; ++i)
	{
		cout << ar[i] << "\t";
	}

	cout << endl;

	for(int i = 0; i < size; ++i)
	{
		cout << *(ar + i) << "\t";
	}

	cout << endl;

	for(int *temp_ptr = ar, i = 0; i < size; ++temp_ptr, ++i)
	{
		cout << *temp_ptr << "\t";
	}

	cout << endl;

	return 0;
}