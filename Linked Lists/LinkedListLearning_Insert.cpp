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
    bool Insert(int e);
	bool RemoveFront();


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

void LinkedList::Print()const{
	Node* curr = head;
	while (curr != nullptr){
		cout << curr->data << "\t";
		curr = curr->next;
	}
}


bool LinkedList::RemoveFront(){
	bool result = false;
	if (head != nullptr){
		Node* temp = head;
		head = head->next;
		delete temp;   //deallocate what temp points to
		result = true;
	}
	return result;
}

bool LinkedList::Insert(int e){
    bool result = true;
    if (head == nullptr || e < head->data)
        head = new Node(e, head);
    else{ 
        Node* curr = head, *prev = head;
        while (curr != nullptr && e > curr->data){
            prev = curr;
            curr = curr->next;        
        }
        if (e != prev->data)
            prev->next = new Node(e, prev->next);
        else{
            cout << "no duplicates" << endl;
            result = false;
        }
    }
    return result;
}
//************************************
// Driver
//************************************


int main() {

	return 0;
}

