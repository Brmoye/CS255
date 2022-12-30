#include <iostream>
using namespace std;

class Stack{
	static const int MAX = 10;
	int top;
	int data[MAX];
public:
	Stack();
	bool Push(int e);
	bool Pop(int & e);
	bool IsEmpty()const;
	bool IsFull() const;
	void Print()const;
};

Stack::Stack(){
	top = -1; //indicates empty stack
}
bool Stack::Push(int e){
	bool success = false;
	if (!IsFull()){
		data[++top] = e;
		success = true;
	}
	return success;
}
bool Stack::Pop(int & e){
	bool success = false;
	if (!IsEmpty()){
		e = data[top--];
		success = true;
	}
	return success;
}
bool Stack::IsEmpty()const{
	return top == -1;
}
bool Stack::IsFull() const{
	return top == MAX - 1;
}
void Stack::Print()const{
	for (int i = top; i>=0; i--)
		cout << data[i] << endl;
}

int main(){
	Stack s;
	int x = 0;
	while (s.Push(x++)){
		s.Print(); cout << "****" << endl;
	}
	
	while (s.Pop(x)){
		cout << "Popped: " << x << endl;
		s.Print(); cout << "****" << endl;
	}
	return 0;
}
