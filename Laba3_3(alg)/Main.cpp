
#include "Tree.h"
#include <iostream>

using namespace std;

int main() {
	Tree A;
	A.insert(3);
	A.insert(5);
	A.insert(2);
	A.insert(1);
	A.insert(7);
	A.insert(6);
	A.insert(16);
	A.insert(17);
	A.insert(10);
	A.insert(24);
	A.insert(13);
	A.insert(5);
	A.insert(4);
	A.insert(3);
	A.insert(15);
	A.insert(20);
	A.insert(1);
	A.insert(4);
	A.insert(18);
	A.insert(2);
	A.insert(14);
	cout << "Laboratory lab 3\n";
	cout << "by Novikova Anastasiya";
	cout << endl;
	cout << "Papa-papaaa, our tree:";
	cout << "The tree head is the element on the left. Read bottom-up.";
	cout << endl;

	A.print_Tree(A.root,0 );
	cout << "Size of tree=" << A.size;
	cout << endl;
	cout << "Find the element 10:\n";
	A.Search(A.root, 10);
	cout << endl;
	cout << "Back traversal of the tree in depth\n";
	A.BackTravers(A.root,  NULL);
	cout << endl;
	cout << "Symmetrical tree traversal in depth\n";
	A.SymTravers(A.root, NULL);
	cout << endl;
	cout << "Direct tree traversal in depth\n";
	A.DirectTravers(A.root, NULL);

	cout << endl;
	cout << endl;
	cout << "Traversing the tree in depth with iterator\n";
	Iterator* diterator = A.Dcreate_iterator();
	while (diterator->has_next())
	{
		std::cout << " " << diterator->next();
	}
	cout << endl;
	cout << endl;
	
	cout << "Traversing the tree in width with iterator\n";
	Iterator* biterator1 = A.Bcreate_iterator();
	while (biterator1->has_next())
	{
		std::cout << " " << biterator1->next();
	}
	cout << endl;
	
	cout << "Delete 18:\n";
	A.remove(18, A.root);
	cout << "Size of tree=" << A.size;
	cout << endl;
	if (A.size>0)
	{
		A.print_Tree(A.root, 0);
	}
	cout << endl;
	system("pause");
	return 0;
	
}
