#pragma once
#include "Iterator.h"
#include <iomanip>
#include <iostream>
#include "../../3.2 алг/3.2 алг/Class.h"
#include "../../3.2 алг/3.2 алг/Class.cpp"

class Tree
{  
   private:
	class Node//элемент дерева
	{
	public:
		
		Node() {};
		int data;//значение
		Node *next = next;
		Node *rgt = nullptr;//правый узел
		Node*lft = nullptr;//левый узел
		Node *parent = nullptr;//батюшка родимый
		Node(int k);
		void Delete();
		 
	     private:
		~Node();
	 };
  public:
	Tree() {  };
	Node *root = nullptr;//корень дерева
	Node *last = nullptr;//последний элемент дерева
	Node *prevlast = nullptr;
	size_t size = 0;
	void TreeSort(Node* elem);
	void insert(int newelem);
	void showTree(Node* root, int p, int s);
	Iterator * Dcreate_iterator()const;
	Iterator * Bcreate_iterator()const;
	void BackTravers(Node* root, void *null);
	void SymTravers(Node* root, void *null);
	void DirectTravers(Node* root, void *null);
	bool Search(int findelem);
	void remove(int elem);
	bool isEmpty(Node *root);
	~Tree();

private:
	Tree(int key);
	void showLine(const char* c, int p, int s);
	void help_Search(int findelem, Node *node);
	bool help_Search_in_search(Node *node, int findelem);
	
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
