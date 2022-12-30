#include <iostream>
using namespace std;

class BNode{
	int data;
	BNode* left;
	BNode* right;
	BNode();
	BNode(int d);
	BNode(int d, BNode* l, BNode*r);
	friend class BST;
};
BNode::BNode(){
	left = right = nullptr;
}
BNode::BNode(int d){
	data = d;
	left = right = nullptr;
}
BNode::BNode(int d, BNode* l, BNode*r){
	data = d;
	left = l;
	right = r;
}
class BST{
	BNode* root;
	bool InsertHelper(int e, BNode*& b);
	void PrintInOrderHelper(BNode* b)const;
	void PrintPreOrderHelper(BNode* b)const;
	void PrintPostOrderHelper(BNode* b)const;
	BNode* FindHelper(int e, BNode* b)const;
	
public:
	BST();
	bool Insert(int e);
	void PrintInOrder()const;
	void PrintPreOrder()const;
	void PrintPostOrder()const;
	BNode* Find(int e)const;
};

BST::BST(){
	root = nullptr;
}
bool BST::Insert(int e){
	return InsertHelper(e, root);
}
bool BST::InsertHelper(int e, BNode*& b){
	bool success = false;
	if (b == nullptr){
		b = new BNode(e);
		success = true;
	}
	else{
		if (e < b->data)
			success = InsertHelper(e, b->left);
		else if (e > b->data)
			success = InsertHelper(e, b->right);
		else{
			cout << "No duplicates!" <<endl;
			success = false;
		}
	}


	return success;
}
void BST::PrintInOrder()const{
	PrintInOrderHelper(root);
}
void BST::PrintInOrderHelper(BNode* b)const{
	if ( b != nullptr){
		PrintInOrderHelper(b->left);	//Recurse Left
		cout << b << ": " << b->data << endl;		//Process Root
		PrintInOrderHelper(b->right);	//Recurse Right
	}
}

void BST::PrintPreOrder()const{
	PrintPreOrderHelper(root);
}
void BST::PrintPreOrderHelper(BNode* b)const{
	if ( b != nullptr){
		
		cout << b->data << "\t";		//Process Root
		PrintPreOrderHelper(b->left);	//Recurse Left
		PrintPreOrderHelper(b->right);	//Recurse Right
	}
}

void BST::PrintPostOrder()const{
	PrintPostOrderHelper(root);
}
void BST::PrintPostOrderHelper(BNode* b)const{
	if ( b != nullptr){
		PrintPostOrderHelper(b->left);	//Recurse Left		
		PrintPostOrderHelper(b->right);	//Recurse Right
		cout << b->data << "\t";		//Process Root
	}
}

BNode* BST::FindHelper(int e, BNode* b)const{
	BNode* temp = nullptr;
	if (b != nullptr){
		if (e == b->data)
			temp = b;		
		else if (e < b->data)
			temp = FindHelper(e, b->left);
		else 
			temp = FindHelper(e, b->right);		
	}

	return temp;
}
BNode* BST::Find(int e)const{
	return FindHelper(e, root);
}

int main(){
	BST tree;
	tree.Insert(50);
	tree.PrintInOrder(); 
	cout << endl;
	
	tree.Insert(25);
	tree.PrintInOrder(); 
	cout << endl;

	tree.Insert(100);
	tree.PrintInOrder(); 
	cout << endl;

	tree.Insert(45);
	tree.PrintInOrder(); 
	cout << endl;

	tree.Insert(75);
	tree.PrintInOrder(); 
	cout << endl;
	cout << endl;

	cout << "50? " << tree.Find(50) << endl;	
	cout << "25? " << tree.Find(25) << endl;	
	cout << "100? " << tree.Find(100) << endl;	
	cout << "45? " << tree.Find(45) << endl;	
	cout << "75? " << tree.Find(75) << endl;	
	cout << "5? " << tree.Find(5) << endl;	
	cout << "30? " << tree.Find(30) << endl;	
	cout << "47? " << tree.Find(47) << endl;	
	cout << "60? " << tree.Find(60) << endl;	
	cout << "80? " << tree.Find(80) << endl;	
	return 0;
}













