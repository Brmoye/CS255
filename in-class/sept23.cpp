#include <iostream>;

using namespace std;

int main() 
{
	int year = 19;
	// POSTFIX
	cout << year << endl;
	cout << year++ << endl;
	cout << year << endl;
	
	year = 19;
	// PREFIX
	cout << year << endl;
	cout << ++year << endl;
	cout << year << endl;
	

	return 0;
}