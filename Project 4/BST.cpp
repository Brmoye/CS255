#include "BST.h"
#include <algorithm>

/***************************************************************************
 * Name: Brian Moye
 * Class: CS 255-01
 * File name: BST.cpp
 * Date: December 6, 2021
 * Assignment: Project 4
 * Description: Experiment with BST and relate height to number of nodes
 * Much of this code was copied from what we did in class with Dr. Jenkins
 * or some of the other projects she provided code for.
 ***************************************************************************/
// The following code was copied from class with Dr. Jenkins
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

BST::BST():root(nullptr)
{
	
}

bool BST::Insert(int e)
{
	return Insert(e, root);
}

bool BST::Insert(int e, BNode*& b)
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
			success = Insert(e, b-> left);
		}
		else if(e > b-> data)
		{
			success = Insert(e, b-> right);
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
	PrintInOrder(root);
}

void BST::PrintInOrder(BNode* b) const
{
	if( b != nullptr)
	{
		PrintInOrder(b-> left); 	// Recurse left
		cout << b-> data << "\t";		// Process root
		PrintInOrder(b-> right);	// Recurse right
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
	PrintPostOrder(root);
}

void BST::PrintPostOrder(BNode* b) const
{
	if( b != nullptr)
	{
		PrintPostOrder(b-> left); 	// Recurse left
		PrintPostOrder(b-> right);	// Recurse right
		cout << b-> data << "\t";		// Process root    
	}
}

// Beginning of code not done in class

int BST::CountHeight() const
{
	int height = -1;
	if(root != nullptr)
	{
		height = CountHeight(root);
	}
	
	return height;
}

 /**************************************************************************
 * Function Name: CountHeight
 * Incoming: Node pointer
 * Outgoing: int
 * Return Value: int
 * Description: This function counts the height of the BST by recursive
 * calls to check for children of the node to the left first. If the node 
 * has a child it proceeds through the subtree checking each node for its 
 * own children. When it hits the bottom of the left nodes, it checks the 
 * right nodes as it moves back up the recursive calls. The function uses
 * ternary operators to achieve these checks. I learned about ternary
 * operators while taking Swift classes at NWSCC, but did get the idea
 * to use them for this from Synxis' answer on the following thread.
 * https://stackoverflow.com/questions/15723646/calculating-height-of-binary-search-tree
 **************************************************************************/
int BST::CountHeight(BNode* b) const
{
	int leftHeight = b-> left ? CountHeight(b-> left) : -1; 
	int rightHeight = b-> right ? CountHeight(b-> right) : -1;
	
	return 1 + max(leftHeight, rightHeight);
}

int BST::CountNodes() const
{
	int nodes = 0;
	
	CountNodes(root, nodes);
	
	return nodes;
}

void BST::CountNodes(BNode* b, int& n) const
{
	if(b != nullptr)
	{
		++n;
		CountNodes(b-> left, n);
		CountNodes(b-> right, n);
	}
}
