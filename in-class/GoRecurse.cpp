#include <iostream>
using namespace std;

void Print1UpToN(int N){
	if (N > 0){
		Print1UpToN(N-1);
		cout << N << "\t";
	}
	

}


int main(){
	int input;
	
	while(true){
		cin >> input;
		cout << "Printing up to: " << input << endl;
		Print1UpToN(input);cout << endl;
	}
	return 0;
}