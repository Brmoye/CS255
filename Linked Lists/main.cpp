#include <iostream>

using namespace std;

// Linked list's store the address of the first item in the list

/****************************************************************
 * LinkedList.h class header
 ****************************************************************/
class Node
{
	int data;	// data item (element)
	Node* next;	// address to the next Node
	
	Node(); // set next to null
	Node(int d); 	// set data to d and next to null
	Node(int d, Node* n); 	// set data to d and next to n
	
	friend class LinkedList;
};

class LinkedList
{
	Node * head;
	
	public:
		LinkedList();
		bool InsertAtFront(int e);
		bool InsertAtEnd(int e);
		Node* Find(int e) const; // if found, return Node*, else return nullptr
		bool RemoveFront();
		bool RemoveEnd();
		bool Insert(int e);
		bool InsertOrder(int item, int position);
		
		int GetSum() const;
		
		void Print() const;
		
};

/****************************************************************
 * LinkedList.cpp class implementation
 ****************************************************************/
Node::Node()
{
	next = nullptr;
}

Node::Node(int d)
{
	data = d;
	next = nullptr;
}

Node::Node(int d, Node* n)
{
	data = d;
	next = n;
}

LinkedList::LinkedList()
{
	head = nullptr;
}

bool LinkedList::InsertAtFront(int e)
{
	head = new Node(e, head);
	
	return true;
}

bool LinkedList::InsertAtEnd(int e)
{
	Node* ptr = head;
	if (head == nullptr)
	{
		InsertAtFront(e);
	}
	
	else
	{
		while (ptr->next != nullptr)
		{
			ptr = ptr-> next;
		}
		
		ptr->next = new Node(e);
	}
	
	return true;
}

Node* LinkedList::Find(int e) const
{
	Node* ptr = head;
	

	while (ptr != nullptr && ptr-> data != e) // short-circuiting, if the 
		// left side is false it doesn't even check the right
	{
		ptr = ptr-> next;
	}
	
	return ptr;
}

bool LinkedList::RemoveFront()
{
	bool result = false;
	Node* ptr = head;
	
	if (head != nullptr)
	{
		head = ptr-> next;
		delete ptr; // deallocate what ptr points to
		result = true;
	}
	
	else
	{
		result = false;
	}
	
	return result;
}

bool LinkedList::RemoveEnd()
{
	bool result = true;
	if (head == nullptr)
	{
		result = false;
	}
	else if (head-> next == nullptr)
	{
		delete head;
		head = nullptr;
	}
	else
	{
		Node* curr = head;
		Node* prev;
		
		while (curr != nullptr && curr->next != nullptr)
		{
			prev = curr;
			curr = curr-> next;
		}
		prev-> next = nullptr;
		delete curr;
		curr = nullptr;
	}
		
	return result;
}

bool LinkedList::Insert(int e)
{
	bool result = true;
	
	if (head == nullptr || e < head-> data)
	{
		head = new Node(e, head);
	}
	else
	{
		Node* curr = head, *prev = head;
		
		while (curr != nullptr && e >= curr-> data)
		{
			prev = curr;
			curr = curr-> next;
		}
		if (e != prev-> data)
		{
			prev-> next = new Node(e, prev-> next);
		}
		else
		{
			cout << "No duplicates" << endl;
			result = false;
		}
	}
	
	return result;
}

bool LinkedList::InsertOrder(int item, int position = 1)
{
	Node* curr = head;
	Node* prev = head;
	bool result = false;
	int count = 1;
	
	if (position == 1)
	{
		InsertAtFront(item);
		result = true;
	}
	else
	{
		while (curr != nullptr && count != position)
		{
			prev = curr;
			curr = curr-> next;
			++count;
		}
		if (count == position)
		{
				prev-> next = new Node(item, curr);
				result = true;
		}
		else
		{
			result = false;
		}
	}
	
	return result;
}

int LinkedList::GetSum() const
{
	Node* ptr = head;
	int sum = 0;

	while (ptr != nullptr)
	{
		sum += ptr-> data;
		ptr = ptr-> next;
	}
	
	return sum;
}

void LinkedList::Print() const
{
	Node* curr = head;
	while (curr != nullptr)
	{
		cout << curr-> data << "\t";
		curr = curr-> next;
	}
}

/****************************************************************
 * Driver
 ****************************************************************/
int main() 
{
	LinkedList l1;
	l1.Insert(3);
	l1.Insert(10);
	l1.Insert(10);
	l1.Insert(10);
	//l1.Insert(10);
	l1.Insert(8);
	l1.Insert(6);
	l1.Print(); cout << endl;
	
	l1.Insert(17);
	l1.Print(); cout << endl;
	l1.Insert(17);
	
	l1.Insert(12);
	l1.Print(); cout << endl;
	
	l1.Insert(12);
	l1.Print(); cout << endl;

	
	cout << "DOES IT GET HERE?" << endl;
	
	return 0;
}