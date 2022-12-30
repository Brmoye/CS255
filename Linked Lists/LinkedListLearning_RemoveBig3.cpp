/*
 * Brian Moye working alone.
 */
#include <iostream>
using namespace std;
//****************************
// LinkedList.h class headers
//****************************

class Node
{
	int data;
	Node* next;
	Node();
	Node(int d);
	Node(int d, Node* n);
	friend class LinkedList;
};


class LinkedList
{
	Node * head;
public:
	LinkedList();
	LinkedList(const LinkedList& l);
	LinkedList& operator=(const LinkedList l);
	~LinkedList();
    bool Insert(int e);
	bool Remove(int e);
	void Print()const;


};

//************************************
// LinkedList.cpp class implementation
//************************************
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

void LinkedList::Print()const
{
	Node* curr = head;
	while (curr != nullptr)
	{
		cout << curr->data << "\t";
		curr = curr->next;
	}
}

LinkedList::LinkedList(const LinkedList& l)
{
	//build a new list for the calling object based upon the contents of the parameter
	if (l.head == nullptr)
	{
		head = nullptr;
	}
	else
	{
		Node* oldCurrent = l.head, *copyCurrent;
		
		head = new Node(oldCurrent-> data);
		oldCurrent = oldCurrent-> next;
		copyCurrent = head;
		
		while (oldCurrent != nullptr)
		{
			copyCurrent->next = new Node(oldCurrent-> data);
			oldCurrent = oldCurrent-> next;
			copyCurrent = copyCurrent-> next;
		}
	}
}

LinkedList& LinkedList::operator=(const LinkedList l)
{
	//make sure calling object and parameter are not the same list then
	//deallocate calling operator then 
	//rebuild a new list for the calling object based upon the contents of the parameter
	bool sameList = false;
	
	Node* current = head, *passed = l.head;
	
	while ((current != nullptr || passed != nullptr) && current-> data == passed-> data)
	{
		current = current-> next;
		passed = passed-> next;
	}
	if (current == passed)
	{
		sameList = true;
	}
	if (sameList == false)
	{
		Node* temp;
		while (head != nullptr)
		{
			temp = head-> next;
			delete head;
			head = temp;
		}
		
		Node* oldCurrent = l.head, *copyCurrent;
		
		head = new Node(oldCurrent-> data);
		oldCurrent = oldCurrent-> next;
		copyCurrent = head;
		
		while (oldCurrent != nullptr)
		{
			copyCurrent->next = new Node(oldCurrent-> data);
			oldCurrent = oldCurrent-> next;
			copyCurrent = copyCurrent-> next;
		}
	}
	return *this;
}
LinkedList::~LinkedList()
{
	//deallocate each item in the list and reset head to nullptr
	Node* temp;
	while (head != nullptr)
	{
		temp = head-> next;
		delete head;
		head = temp;
	}
}
    
	

bool LinkedList::Insert(int e)
{
    bool result = true;
    if (head == nullptr || e < head->data)
        head = new Node(e, head);
    else
	{ 
        Node* curr = head, *prev = head;
        while (curr != nullptr && e >= curr->data)
		{
            prev = curr;
            curr = curr->next;        
        }
        if ( e != prev->data)
            prev->next = new Node(e, prev->next);
        else
		{
            cout << "no duplicates" << endl;
            result = false;
        }
    }
    return result;
}

bool LinkedList::Remove(int e)
{
	bool success = true;
	
	if (head == nullptr)
	{
		success = false;
		cout << "Empty list, nothing to remove." << endl;
	}
	else if (head-> data == e)
	{
		head = head-> next;
	}
	else
	{
		Node* curr = head, *prev = head;
		
		while (curr != nullptr && e != curr-> data)
		{
			prev = curr;
			curr = curr-> next;
		}
		if (curr != nullptr && e == curr-> data)
		{
			prev-> next = curr-> next;
			delete curr;
			curr = nullptr;
		}
		else
		{
			success = false;
		}
	}
	
	return success;
}


//************************************
// Driver
//************************************


int main() 
{
	LinkedList l1;
	
	l1.Remove(10);
	
	l1.Insert(3);
	l1.Insert(10);
	l1.Insert(8);
	l1.Insert(6);
	l1.Print(); cout << endl;
	
	l1.Insert(17);
	l1.Print(); cout << endl;
	l1.Insert(17);
	
	l1.Insert(12);
	l1.Print(); cout << endl;
	
	l1.Remove(10);
	l1.Print(); cout << endl;
	
	if(!l1.Remove(10))
	{
		cout << "Item not found" << endl;
	}
	l1.Print(); cout << endl;
	
	cout << endl;
	cout << "Testing Linked List copy" << endl;
	
	LinkedList l2(l1);
	cout << "Copied l1: " << endl;
	l1.Print(); cout << endl << endl;
	
	cout << "to l2:" << endl;
	l2.Print(); cout << endl << endl;
	
	l2.Insert(7);
	cout << "l2 - Insert 7:" << endl;
	l2.Print(); cout << endl << endl;
	
	cout << "l1:" << endl;
	l1.Print(); cout << endl << endl;
	
	l1.Insert(22);
	cout << "l1 - Insert 22:" << endl;
	l1.Print(); cout << endl;
	
	cout << "l2:" << endl;
	l2.Print(); cout << endl << endl;
	
	cout << "l2 - Remove 6:" << endl;
	l2.Remove(6);
	l2.Print(); cout << endl << endl;
	
	cout << "l1:" << endl;
	l1.Print(); cout << endl << endl;
	
	l1 = l2;
	cout << "l1 = l2:" << endl;
	l1.Print(); cout << endl << endl;
	
	cout << "l2:" << endl;
	l2.Print(); cout << endl << endl;
	
	l1.Insert(13);
	cout << "l1 - Insert 13:" << endl;
	l1.Print(); cout << endl << endl;
	
	l1.Remove(3);
	cout << "l1 - Remove 3:" << endl;
	l1.Print(); cout << endl << endl;
	
	l1.Remove(22);
	cout << "l1 - Remove 22:" << endl;
	l1.Print(); cout << endl << endl;

	cout << "l1:" << endl;
	l1.Print(); cout << endl << endl;
	
	cout << "l2:" << endl;
	l2.Print(); cout << endl << endl;
	
	l2 = l1;
	cout << "l2 = l1:" << endl;
	
	cout << "l1:" << endl;
	l1.Print(); cout << endl << endl;
	
	cout << "l2:" << endl;
	l2.Print(); cout << endl << endl;
	
	
	
	cout << "DOES IT GET HERE?" << endl;
	return 0;
}

