#pragma once
#ifndef _BST_H
#define _BST_H

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


	void insert(Node<T>* node, T data);
	void destroySubtree(Node<T>* node);
	T get(Node<T>* tree, T value);
public:
	Set();
	~Set();
	void insert(T data);
	bool isEmpty();
	T get(T value);
};

/*      Pre:  None
*     Post:  This object is initialized using default values
*  Purpose:  To intialize a Set object
*************************************************************************/
template<typename T>
Set<T>::Set()
{
	root = NULL;
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
Set<T>::destroySubtree(Node<T>* node)
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
void Set<T>::insert(Node<T>* node, T data)
{
	if (tree == NULL)
	{
		tree = new Node<T>(data);
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

/*      Pre:  An initialized set object
*     Post:  if value is in the set it is returned, otherwise return is NULL. wrapper for a recursive function
*  Purpose:  to return a value from the set
*************************************************************************/
template<typename T>
T Set<T>::get(T value)
{
	return get(root, value)
}

/*      Pre:  An initialized set object
*     Post:  if value is in the set it is returned, otherwise return is NULL
*  Purpose:  to return a value from the set
*************************************************************************/
template<typename T>
T Set<T>::get(Node<T>* tree, T value)
{
	if (tree == NULL)
		return NULL;
	if (tree->mData == value)
		return tree->mData;
	if (tree->mData > value)
		return get(tree->mLeft, value);

	return get(tree->mRight, value);
}
#endif