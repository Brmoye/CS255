#include <iostream>

using namespace std;
/*
Stack
	Last In First Out - LIFO

	Data Representation:
		Top (Index, pointer)
		
	Methods Upon Data:
		Push (Insert)
		Pop (Remove)

Queue
	First In First Out - FIFO
	
	Data Representation:
		Front
		Back
		
	Methods Upon Data:
		Enqueue (Insert)
		Dequeue (Remove)

*/



// Stack class header
class Stack{
	private:
		const int MAX = 10;
		// data representation
		int data[MAX];	
		int top; 	// index to the top item in the stack (array)
	public:
		// operations upon the data
		Stack();
		bool Push(int item); 	// insert at top
		bool Pop(int& item);	// remove from top
		bool PeekTop(int& item) const; 	// get top value without removing
		bool IsEmpty() const;
		bool IsFull() const;
		void Print() const;
};

Stack::Stack()
{
	top = -1;	// indicates the stack is empty
}

bool Stack::Push(int item)
{
	bool success = false;
	
	if(!IsFull())
	{
		data[++top] = item;	// increment top and store value at the top
		success = true;
	}
	
	return success;
}

bool Stack::Pop(int& item)
{
	bool success = false;
	
	if(!IsEmpty())
	{
		item = data[top--];
		success = true;	
	}
	
	return success;
}

bool Stack::PeekTop(int& item) const
{
	bool success = false;
	
	if(!IsEmpty())
	{
		item = data[top];
		success = true;
	}
	
	return success;
}

bool Stack::IsEmpty() const
{
	return top == -1;
}

bool Stack::IsFull() const
{
	return top == MAX - 1;
}

void Stack::Print() const
{
	cout << "TOP" << endl;
	for(int i = top; i >= 0; --i)
	{
		cout << data[i] << endl;
	}
	cout << "BOTTOM" << endl;
}

int main()
{
	Stack s;
	int input, value;
	
	cout << "Enter a value to be pushed" << endl;
	cin >> input;
	
	while(input != -100)
	{
		s.Push(input);
		s.Print(); cout << endl;
		cin >> input;
	}
	while(s.Pop(value))
	{
		cout << "Popped: " << value << endl;	
	}
	cout << "Done" << endl;
	
	return 0;	
}