#include "Tree.h"
#include <stdexcept>
#include <string>
#include <iostream>
#include <windows.h>

using namespace std;

Tree::Node::~Node()
{
	free(this);
}
Tree::~Tree()
{
	root->Delete();
	if (root->lft != nullptr)
		root->lft = nullptr;
	if (root->rgt != nullptr)
		root->rgt = nullptr;
	root = nullptr;
}

void Tree::Node::Delete()
{
	if (this == nullptr) return;
	this->lft->Delete();
	this->rgt->Delete();
	free(this);
}
void Tree::insert(int newelem)
{
	Node *elem = new Node;
	elem->data = newelem;
	if (root == nullptr)
	{
		root = elem;
		last = root;
	}
	else
	{
		Node *current = last;
		while (current->parent != nullptr && current == current->parent->rgt)
			current = current->parent;

		if (current->parent != nullptr)
		{
			if (current->parent->rgt != nullptr)//� �������� ���� ������ ����
			{
				current = current->parent->rgt;//��������� �� ����
				while (current->lft != nullptr)//���� � ���� ���� �����
					current = current->lft;
			}

			else current = current->parent;//��� ������� ����,������� � ������
		}
		else
		{   //�� � �����
			while (current->lft != nullptr)
				current = current->lft;
		}

		if (current->lft != nullptr)//������� ������
		{
			current->rgt = elem;
			prevlast = last;
			last = current->rgt;
		}

		else
		{
			current->lft = elem;
			prevlast = last;
			last = current->lft;
		}
		elem->parent = current;
		elem->lft = nullptr;
		elem->rgt = nullptr;
	}

	size++;

	TreeSort(last);
}
int Tree::remove(int value, Node *node)
{
	if (size == 0)
	{
		throw out_of_range("Tree is empty");
		
	}
	else
	{
		if (size == 1)
		{
			if (root->data == value)
			{
				free(root);
				cout << "Tree is empty\n";
				
				size--;
				return 0;
			}
		}
		else
		{
			if (node->lft != nullptr && node->data != value)
			{
				remove(value, node->lft);
			}
			if (node->rgt != nullptr &&node->data != value)
			{
				remove(value, node->rgt);
			}

			if (node != nullptr && node->data == value)
			{
				node->data = last->data;
				if (node->rgt != nullptr)
				{
					Node *help = node->rgt;
					TreeSort(help);
				}
				if (node->lft != nullptr)
				{
					Node *help1 = node->lft;
					TreeSort(help1);
				}

				if (last == last->parent->lft)
					last->parent->lft = nullptr;
				if (last == last->parent->rgt)
					last->parent->rgt = nullptr;
				TreeSort(prevlast);
				size--;
			}
		}
	}
}
void Tree::print_Tree(Node * p, int level)
{
	if (p)
	{
		print_Tree(p->rgt, level + 1);
		for (int i = 0; i < level; i++) cout << "   ";
		cout << p->data << endl;
		print_Tree(p->lft, level + 1);
	}
}
void Tree::TreeSort(Node* elem)
{
	while (elem->parent != nullptr && elem->data > elem->parent->data) {
		int temp = elem->data;

		if (elem->data > elem->parent->data) {
			elem->data = elem->parent->data;
			elem->parent->data = temp;
		}

		elem = elem->parent;
	}
}
Tree::Tree(int key)
{
	root = new Node(key);
}

Iterator*Tree::Bcreate_iterator() const
{
	if (this == nullptr && this->root == nullptr) throw std::exception("ERROR");
	return new BIterator(this->root);
}
int Tree::BIterator::next()
{
	if (lst.get_size() == 0)
		lst.push_back(current);
	current = lst.at(0);
	lst.pop_front();
	const int key = current->data;
	if (current->lft) {
		lst.push_back(current->lft);
	}
	if (current->rgt) {
		lst.push_back(current->rgt);
	}
	return key;
}
bool Tree::BIterator::has_next()
{
	return (lst.get_size() || current->lft != nullptr && current->rgt != nullptr);
}
int Tree::DIterator::next()
{
	if (current != nullptr) {
		const int key = current->data;
		if (current->rgt != nullptr)
			lst.push_front(current);
		current = current->lft;
		return key;
	}
	if (current == nullptr) {
		current = lst.at(0);
		lst.pop_front();
		current = current->rgt;
		next();
	}
}
bool Tree::DIterator::has_next()
{
	return (lst.get_size() || current != nullptr);
}
Iterator * Tree::Dcreate_iterator()const //� �������
{
	if (this == nullptr && this->root == nullptr) throw std::exception("ERROR");
	return new DIterator(this->root);
}
Tree::Node::Node(int k)
{
	/*height = 1;*/
	data = k;
	lft = rgt = nullptr;
}
void Tree::BackTravers(Node* root, void *null)
{
	if (root) {
		BackTravers(root->lft, null);
		BackTravers(root->rgt, null);
		printf("%d ", root->data);
	}
}
void Tree::SymTravers(Node* root, void *null) {
	if (root) {
		SymTravers(root->lft, null);
		printf("%d ", root->data);
		SymTravers(root->rgt, null);
	}
}
void Tree::DirectTravers(Node* root, void *null) 
{
	if (root) {
		printf("%d ", root->data);
		DirectTravers(root->lft, null);
		DirectTravers(root->rgt, null);
	}
}
int Tree::Search(Node *root, int findelem)
{
	Node *elem = new Node;
	elem->data = findelem;

	if (root)
	{
		if (root->data != elem->data)
		{
			Search(root->lft, findelem);
			Search(root->rgt, findelem);
		}
		else
		{
			cout << "Finded element= " << root->data;
			return root->data;
		}
	}
	else
	{
		//cout << "Element not finded\n ";
	}
}
bool Tree::isEmpty(Node *root)
{
	if (size == 0)
		return true;
	else
		return false;
}
