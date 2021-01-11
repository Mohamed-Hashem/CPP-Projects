#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <functional>
#include <algorithm>
#include "Node.h"
using namespace std;

template <class T>
class Tree
{
private:
	Node<T> * rootPtr;
	void insert_Helper(Node<T> * , T);
	void inOrder_Helper(Node<T> *);
	void postOrder_Helper(Node<T> *);
	void preOrder_Helper(Node<T> *);
	T maxValue_Helper(Node<T> *);
	T minValue_Helper(Node<T> *);

public:
	Tree();
	void insert(const T &);
	void inOrder();
	void postOrder();
	void preOrder();
	T maxValue();
	T minValue();
	~Tree();
};

template <class T>
Tree<T>::Tree()
{
	rootPtr = nullptr;
}

template <class T>
void Tree<T>::insert(const T & value)
{
	if (rootPtr == nullptr)
		rootPtr = new Node<T> (value);
	else
		insert_Helper(rootPtr , value);

}

template <class T>
void Tree<T>::insert_Helper(Node <T> *temp , T value)
{
	if (value <= temp->data)
	{
		if (temp->leftPtr == nullptr)
			temp->leftPtr = new Node<T>(value);
		else
			insert_Helper(temp->leftPtr , value);
	}
	else if (value > temp->data)
	{
		if (temp->rightPtr == nullptr)
			temp->rightPtr = new Node<T>(value);
		else
			insert_Helper(temp->rightPtr , value);
	}
}

template <class T>
void Tree<T>::inOrder()
{
	inOrder_Helper(rootPtr);
}

template <class T>
void Tree<T>::inOrder_Helper(Node<T> * temp)
{
	if (temp != nullptr)
	{
		inOrder_Helper(temp->leftPtr);
		cout << temp->data << " ";
		inOrder_Helper(temp->rightPtr);
	}
}

template <class T>
void Tree<T>::postOrder()
{
	postOrder_Helper(rootPtr);
}

template <class T>
void Tree<T>::postOrder_Helper(Node<T> *temp)
{
	if (temp != nullptr)
	{
		postOrder_Helper(temp->leftPtr);
		postOrder_Helper(temp->rightPtr);
		cout << temp->data << " ";
	}
}

template <class T>
void  Tree<T>::preOrder()
{
	preOrder_Helper(rootPtr);
}

template <class T>
void Tree<T>::preOrder_Helper(Node<T> *temp)
{
	if (temp != nullptr)
	{
		cout << temp->data << " ";
		preOrder_Helper(temp->leftPtr);
		preOrder_Helper(temp->rightPtr);
	}
}

template <class T>
T Tree<T>::maxValue()
{
	return maxValue_Helper(rootPtr);
}

template <class T>
T Tree<T>::maxValue_Helper(Node<T> * temp)
{
	if (temp->rightPtr == nullptr)
		return temp->data;

	return maxValue_Helper(temp->rightPtr);
}

template <class T>
T Tree<T>::minValue()
{
	return minValue_Helper(rootPtr);
}

template <class T>
T Tree<T>::minValue_Helper(Node<T> *temp)
{
	if (temp->leftPtr == nullptr)
		return temp->data;

	return minValue_Helper(temp->leftPtr);
}

template <class T>
Tree<T>::~Tree()
{
	delete rootPtr;
}

