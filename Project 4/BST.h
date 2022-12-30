#ifndef BST_H
#define BST_H

#include <cmath>
#include <iostream>
#include <algorithm>
/***************************************************************************
 * Name: Brian Moye
 * Class: CS 255-01
 * File name: BST.h
 * Date: December 6, 2021
 * Assignment: Project 4
 * Description: Experiment with BST and relate height to number of nodes
 * Much of this code was copied from what we did in class with Dr. Jenkins
 * or some of the other projects she provided code for.
 ***************************************************************************/
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

class BST
{
	private:
		BNode* root;
		bool Insert(int e, BNode*& b);
		void PrintInOrder(BNode* b) const;
		void PrintPreOrder(BNode* b) const;
		void PrintPostOrder(BNode* b) const;
		int CountHeight(BNode* b) const;
		void CountNodes(BNode* b, int& n) const;
	
	public:
		BST();
		bool Insert(int e);
		void PrintInOrder() const;
		void PrintPreOrder() const;
		void PrintPostOrder() const;
		int CountHeight() const;
		int CountNodes() const;
};

#endif