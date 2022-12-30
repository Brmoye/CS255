/* 
 * To-Do: Sum
 * 
 */
#include <iostream>

using namespace std;

class BNode
{
	int data;
	BNode* left;
	BNode* right;
	
	BNode();
	BNode(int d);
	BNode(int d, BNode* l, BNode* r);
	friend class BST;
};

BNode::BNode():left(nullptr), right(nullptr)
{
	
}

BNode::BNode(int d)
{
	data = d;
	left = right = nullptr;
}

BNode::BNode(int d, BNode* l, BNode* r)
{
	data = d;
	left = l;
	right = r;
}

class BST
{
	private:
		BNode* root;
		bool InsertHelper(int e, BNode*& b);
		void PrintInOrderHelper(BNode* b) const;
		void PrintPreOrder(BNode* b) const;
		void PrintPostOrderHelper(BNode* b) const;
		BNode* Search(int e, BNode* b) const;
		int Sum(BNode* b) const;
	
	public:
		BST();
		bool Insert(int e);
		void PrintInOrder() const;
		void PrintPreOrder() const;
		void PrintPostOrder() const;
		BNode* Search(int e) const;
		int Sum() const;
		int Min() const;
		int Max() const;
};

BST::BST():root(nullptr)
{
	
}

bool BST::Insert(int e)
{
	return InsertHelper(e, root);
}

bool BST::InsertHelper(int e, BNode*& b)
{
	bool success = false;
	
	if(b == nullptr)
	{
		b = new BNode(e);
		success = true;
	}
	else
	{
		if(e < b-> data)
		{
			success = InsertHelper(e, b-> left);
		}
		else if(e > b-> data)
		{
			success = InsertHelper(e, b-> right);
		}
		else
		{
			cout << "No duplicates!" << endl;
			success = false;
		}
	}
	
	return success;
}

void BST::PrintInOrder() const
{
	PrintInOrderHelper(root);
}

void BST::PrintInOrderHelper(BNode* b) const
{
	if( b != nullptr)
	{
		PrintInOrderHelper(b-> left); 	// Recurse left
		cout << b-> data << "\t";		// Process root
		PrintInOrderHelper(b-> right);	// Recurse right
	}
}

void BST::PrintPreOrder() const
{
	PrintPreOrder(root);
}

void BST::PrintPreOrder(BNode* b) const
{
	if( b != nullptr)
	{
		cout << b << ": " << b-> data << "\t";		// Process root
		PrintPreOrder(b-> left); 	// Recurse left
		PrintPreOrder(b-> right);	// Recurse right
	}
}
	
void BST::PrintPostOrder() const
{
	PrintPostOrderHelper(root);
}

void BST::PrintPostOrderHelper(BNode* b) const
{
	if( b != nullptr)
	{
		PrintPostOrderHelper(b-> left); 	// Recurse left
		PrintPostOrderHelper(b-> right);	// Recurse right
		cout << b-> data << "\t";		// Process root    
	}
}

BNode* BST::Search(int e) const
{
	return Search(e, root);
}

BNode* BST::Search(int e, BNode* b) const
{
	BNode* temp = nullptr;
	
	if(b != nullptr)
	{
		if(e == b-> data)
		{
			temp = b;
		}
		else if(e < b-> data)
		{
			temp = Search(e, b-> left);
		}
		else
		{
			temp = Search(e, b-> right);
		}
	}
	
	return temp;
}

int BST::Sum() const
{
	return Sum(root);
}

//unfinished
int BST::Sum(BNode* b) const
{
	//BNode* temp = b;
	int sum = 0;
	
	if(b != nullptr)
	{
		sum += b-> data;
		
	}
	
	return sum;
}

int BST::Min() const
{
	BNode* temp = root;
	
	while(temp-> left != nullptr)
	{
		temp = temp-> left;
	}
	
	return temp-> data;
}

int BST::Max() const
{
	BNode* temp = root;
	
	while(temp-> right != nullptr)
	{
		temp = temp-> right;
	}
	
	return temp-> data;
}

int main() 
{
	BST tree;
	
	tree.Insert(50);
	tree.PrintInOrder(); cout << endl;
	
	tree.Insert(25);
	tree.PrintInOrder(); cout << endl;
	
	tree.Insert(100);
	tree.PrintInOrder(); cout << endl;
	
	tree.Insert(45);
	tree.PrintInOrder(); cout << endl;
	
	tree.Insert(75);
	tree.PrintInOrder(); cout << endl;
	
	tree.PrintPreOrder(); cout << endl;
	cout << tree.Search(45); cout << endl;
	
	int min = tree.Min();
	cout << "Min: " << min << endl;
	
	int max = tree.Max();
	cout << "Max: " << max << endl;
	
	cout << "Does it get here?" << endl;

	return 0;
}