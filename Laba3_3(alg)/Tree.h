#pragma once
#include "Iterator.h"
#include <stack>
#include <queue>
#include <iomanip>
#include <iostream>
#include "../../3.2 алг/3.2 алг/Class.h"
#include "../../3.2 алг/3.2 алг/Class.cpp"

class Tree
{
public:

	class Node//элемент дерева
	{
	public:
		~Node();
		Node() {};

		int data;//значение
		Node *next = next;
		Node *rgt = nullptr;//правый узел
		Node*lft = nullptr;//левый узел
		Node *parent = nullptr;//батюшка родимый
		Node(int k);
		void Delete();
	};
	~Tree();
	Tree() {  };
	Node *root = nullptr;//корень дерева
	Node *last = nullptr;//итак понятно
	Node *prevlast = nullptr;
	size_t size = 0;

	void insert(int newelem);
	void print_Tree(Node * p, int level);
	void TreeSort(Node* elem);
	Iterator * Dcreate_iterator()const;
	Iterator * Bcreate_iterator()const;
	void BackTravers(Node* root, void *null);
	void SymTravers(Node* root, void *null);
	void DirectTravers(Node* root, void *null);
	int Search(Node *root, int elem);
	int remove(int elem, Node *node);
	bool isEmpty(Node *root);
    Tree(int key);
	
	class DIterator : public Iterator
	{
	public:
		DIterator(Node * root)
		{
			current = root;
		};
		int next() override;
		bool has_next() override;

	private:
		LinkedList<Node*> lst;
		Node * current;
	};

	class BIterator : public Iterator
	{
	public:
		BIterator(Node * root)
		{
			current = root;
		};
		int next() override;
		bool has_next() override;

	private:
		LinkedList<Node*> lst;
		Node * current;
	};
};
