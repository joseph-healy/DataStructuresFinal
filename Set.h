#pragma once
#ifndef _SET_H
#define _SET_H

#include <iostream>

using namespace std;


template<typename T>
class Set
{
private: 
	template <typename R>
	struct Node
	{
		
		R       mData;
		Node<R> *mLeft, *mRight;

		/*      Pre:  None
		*     Post:  This object is initialized using default values
		*  Purpose:  To intialize date object
		*************************************************************************/
		Node()
		{
			mData = R();
			mLeft = NULL;
			mRight = NULL;
		}

		/*      Pre:  None
		*     Post:  This object is initialized using specified data
		*  Purpose:  To intialize date object
		*************************************************************************/
		Node(R data)
		{
			mData = data;
			mLeft = NULL;
			mRight = NULL;
		}

		/*      Pre:  None
		*     Post:  This object is initialized using specified data with the
		*            specified children attached
		*  Purpose:  To intialize date object
		*************************************************************************/
		Node(R data, Node<R> *left, Node<R> *right)
		{
			mData = data;
			mLeft = left;
			mRight = right;
		}
	};
	Node<T>* root;
	int size;

	void insert(Node<T>* &node, T data);
	void destroySubtree(Node<T>* &node);
	bool search(Node<T>* &tree, T value);
	T get(Node<T>* &tree, T value);
	void gatherNodes(T* arr, int &i, Node<T>* &node);

public:
	Set();
	~Set();
	void insert(T data);
	bool isEmpty();
	bool contains(T value);
	T get(T value);
	int nodeCount();
	T* getNodes();
};

/*      Pre:  None
*     Post:  This object is initialized using default values
*  Purpose:  To intialize a Set object
*************************************************************************/
template<typename T>
Set<T>::Set()
{
	root = NULL;
	size = 0;
}

/*      Pre:  None
*     Post:  This object is deleted, all pointers deleted
*  Purpose:  To delete the set object
*************************************************************************/
template<typename T>
Set<T>::~Set()
{
}

/*      Pre:  An initialized set object
*     Post:  The subtree/subset of node is deleted, all pointers are deleted
*  Purpose:  To delete a subtree/subset
*************************************************************************/
template<typename T>
void Set<T>::destroySubtree(Node<T>* &node)
{
	if (node == NULL)
		return;

	destroySubtree(node->mLeft);
	destroySubtree(node->mRight);

	delete node;
}

/*      Pre:  An initialized set object
*     Post:  data is inserted into the tree, no duplicates are allowed. Wrapper for another recursive function call
*  Purpose:  To insert a value into the set
*************************************************************************/
template<typename T>
void Set<T>::insert(T data)
{
	insert(root, data);
}

/*      Pre:  An initialized set object
*     Post:  data is inserted into the tree, no duplicates are allowed. 
*  Purpose:  To insert a value into the set recursively
*************************************************************************/
template<typename T>
void Set<T>::insert(Node<T>* &node, T data)
{
	if (node == NULL)
	{
		node = new Node<T>(data);
		this->size++;
		cout << "size incremented - " << this->size << endl;
		return;
	}

	//sets cannot have duplicates
	if (node->mData == data)
		return;

	if (data < node->mData)
		insert(node->mLeft, data);
	if (data > node->mData)
		insert(node->mRight, data);
}

/*      Pre:  An initialized set object
*     Post:  data is inserted into the tree, no duplicates are allowed. Wrapper for another recursive function call
*  Purpose:  To insert a value into the set
*************************************************************************/
template<typename T>
bool Set<T>::isEmpty()
{
	if (root == NULL)
		return true;
	else
		return false;
}

/*     Pre:  An initialized set object
*     Post:  Returns true if the value is found, otherwise false. wrapper for a recursive function
*  Purpose:  to find out if the set has a particular value inside of it
*************************************************************************/
template<typename T>
bool Set<T>::contains(T value)
{
	return search(root, value);
}

/*     Pre:  An initialized set object
*     Post:  Returns true if the value is found, otherwise false
*  Purpose:  to find out if the set has a particular value inside of it
*************************************************************************/
template<typename T>
bool Set<T>::search(Node<T>* &tree, T value)
{
	if (tree == NULL)
		return false;
	if (tree->mData == value)
		return true;
	if (tree->mData > value)
		return search(tree->mLeft, value);

	return search(tree->mRight, value);
}

/*      Pre:  An initialized set object
*     Post:  if value is in the set it is returned, otherwise return is NULL. wrapper for a recursive function
*  Purpose:  to return a value from the set
*************************************************************************/
template<typename T>
T Set<T>::get(T value)
{
	return get(root, value);
}

/*      Pre:  An initialized set object
*     Post:  if value is in the set it is returned, otherwise return is NULL
*  Purpose:  to return a value from the set
*************************************************************************/
template<typename T>
T Set<T>::get(Node<T>* &tree, T value)
{
	if (tree == NULL)
		return NULL;
	if (tree->mData == value)
		return tree->mData;
	if (tree->mData > value)
		return get(tree->mLeft, value);

	return get(tree->mRight, value);
}

/*     Pre:  An initialized set object
*     Post:  the return value is the number of nodes in the set, this is a wrapper function for a recursive function
*  Purpose:  to know the size of a set
*************************************************************************/
template<typename T>
int Set<T>::nodeCount()
{
	return size;
}

/*     Pre:  An initialized set object
*     Post:  Returns an array filled with the values from the nodes
*  Purpose:  to collect the nodes of a set for easier iteration. wrapper for a recursive function
*************************************************************************/
template<typename T>
T* Set<T>::getNodes()
{
	T* arr = new T[nodeCount()];
	int i = 0;
	gatherNodes(arr, i, root);

	return arr;
}

/*     Pre:  An initialized set object
*     Post:  fills an array with the values from the nodes in pre order
*  Purpose:  recursive function to collect the nodes of a set for easier iteration. 
*************************************************************************/
template<typename T>
void Set<T>::gatherNodes(T* arr, int &i, Node<T>* &node)
{
	if (node != NULL)
	{
		gatherNodes(arr, i, node->mLeft);
		arr[i] = node->mData;
		i++;
		gatherNodes(arr, i, node->mRight);
	}
}

#endif