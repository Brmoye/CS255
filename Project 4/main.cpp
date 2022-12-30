#include <iostream>
#include "BST.h"

using namespace std;

int main() 
{
	BST tree;
	
	tree.Insert(36);
	tree.Insert(41);
	tree.Insert(12);
	tree.Insert(34);
	tree.Insert(52);
	tree.Insert(3);
	tree.Insert(38);
	tree.Insert(25);
	tree.Insert(40);
	tree.Insert(35);
	tree.Insert(76);
	tree.Insert(42);
	tree.Insert(43);
	tree.Insert(27);
	tree.Insert(39);
	tree.Insert(37);
	tree.Insert(111);
	tree.Insert(5);
	tree.Insert(2);
	
	tree.PrintInOrder(); cout << endl;
	cout << "Height: " << tree.CountHeight() << endl;
	cout << "Nodes: " << tree.CountNodes() << endl;
	
	return 0;
}