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
	Leave an open spot in circular array implementation
	
	Data Representation:
		Front
		Back
		
	Methods Upon Data:
		Enqueue (Insert)
		Dequeue (Remove)
	
*/


class Queue
{
	private:
		const int MAX = 5;
		int data[MAX];
		int front;
		int back;
	public:
		Queue();
		bool Enq(int item);
		bool Deq(int& item);
		void Print() const;	
};

Queue::Queue()
{

}

bool Queue::Enq(int item)
{
	
}

bool Queue::Deq(int& item)
{
	
}

void Queue::Print() const
{
	
}

int main()
{
	Queue q;
	int value;
	
	q.Enq(3);
	q.Print(); cout << endl;
	q.Enq(4);
	q.Print(); cout << endl;
	q.Enq(1);
	
	q.Deq(value);
	cout << value << endl;	// 3 would be removed
	
	return 0;	
}