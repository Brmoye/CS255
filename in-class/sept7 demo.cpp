#include <iostream>;

using namespace std;

int main() 
{
	int mat[2][3] = {{10, 20, 30}, {40, 50, 60}};

	cout << *(*(mat + 1) + 1);

	return 0;
}