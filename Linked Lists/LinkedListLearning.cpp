#include <iostream>
using namespace std;
//****************************
// LinkedList.h class headers
//****************************

class Node{
	int data;
	Node* next;
	Node();
	Node(int d);
	Node(int d, Node* n);
	friend class LinkedList;
};


class LinkedList{
	Node * head;
public:
	LinkedList();
	bool InsertAtFront(int e);
	bool InsertAtEnd(int e);
	Node* Find(int e)const; //if find it, return Node* to found,
							//else return nullptr
	bool RemoveFront();

	int GetSum()const;
	void Print()const;

};

//************************************
// LinkedList.cpp class implementation
//************************************
Node::Node(){
	next = nullptr;
}
Node::Node(int d){
	data = d;
	next = nullptr;
}
Node::Node(int d, Node* n){
	data = d;
	next = n;
}
LinkedList::LinkedList(){
	head = nullptr;
}
bool LinkedList::InsertAtFront(int e){
	head = new Node(e, head);
	return true;

}
void LinkedList::Print()const{
	Node* curr = head;
	while (curr != nullptr){
		cout << curr->data << "\t";
		curr = curr->next;
	}
}



//************************************
// Driver
//************************************


int main() {
	LinkedList l1;
	l1.InsertAtFront(3);
	l1.InsertAtFront(10);
	l1.InsertAtFront(8);
	l1.Print();

	return 0;
}

