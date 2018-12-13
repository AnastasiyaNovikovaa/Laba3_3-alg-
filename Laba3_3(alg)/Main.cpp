
#include "Tree.h"
#include <iostream>

using namespace std;

int main() {
	Tree A;
	A.insert(6);
	A.insert(10);
	A.insert(3);
	A.insert(5);
	A.insert(16);
	A.insert(17);
	A.insert(2);
	A.insert(1);
        A.insert(7);
	A.insert(24);
	A.insert(4);
	
	cout << "Laboratory lab 3\n";
	cout << "by Novikova Anastasiya";
	cout << endl;
	cout << "Papa-papaaa, our tree:";
	cout << "The tree head is the element on the left. Read bottom-up.";
	cout << endl;

	A.showTree(A.root, 0, 0);
	cout << "Size of tree=" << A.size;
	cout << endl;
	cout << "Find the element 10:\n";
	A.Search( 10);
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
	
	cout << "Delete 24:\n";
	A.remove(24);
	cout << "Size of tree=" << A.size;
	cout << endl;
	if (A.size>0)
	{
		A.showTree(A.root,0, 0);
	}
	cout << endl;
	system("pause");
	return 0;
	
}
