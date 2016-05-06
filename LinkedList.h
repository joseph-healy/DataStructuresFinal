#pragma once
#ifndef __LINKED_LIST_H
#define __LINKED_LIST_H

#include <iostream>

using namespace std;

template<typename T>
class LinkedList
{

private:

	template <typename R>
	struct Node
	{
		R       mData;
		Node<R> *mNext;

		/*      Pre:  None
		*     Post:  This object is initialized using default values
		*  Purpose:  To intialize node object
		*************************************************************************/
		Node()
		{
			mData = R();
			mNext = NULL;
		}

		/*      Pre:  None
		*     Post:  This object is initialized using specified data
		*  Purpose:  To intialize node object
		*************************************************************************/
		Node(R data)
		{
			mData = data;
			mNext = NULL;
		}

		/*      Pre:  None
		*     Post:  This object is initialized using specified data with the
		*            specified children attached
		*  Purpose:  To intialize node object
		*************************************************************************/
		Node(R data, Node<R>* next)
		{
			mData = data;
			mNext = next;
		}
	};

	Node<T>* head;
	Node<T>* current;

public:
	LinkedList();
	LinkedList(T val);
	~LinkedList();
	void addItem(T val);
	void removeItem();
	bool isEmpty();
	int size();
	void getNodes(T nodeArr[], int n);
};

/*     Pre:  None
*     Post:  This object is initialized using default values
*  Purpose:  To intialize a Linked List object
*************************************************************************/
template<typename T>
LinkedList<T>::LinkedList()
{
	head = current = NULL;
}

/*     Pre:  <T> is a data type with well defined behaviour for =
*     Post:  This object is initialized using default values
*  Purpose:  To intialize a Linked List object
*************************************************************************/
template<typename T>
LinkedList<T>::LinkedList(T val)
{
	head = current = new Node<T>(val);
}

/*     Pre:  An initialized linked list
*     Post:  This object is deleted, all pointers deleted
*  Purpose:  To delete the object without memory issues
*************************************************************************/
template<typename T>
LinkedList<T>::~LinkedList()
{
	while (head != NULL)
		removeItem();
}

/*     Pre:  <T> is a data type with well defined behaviour for =
*     Post:  A node containing val is added onto the end of the list
*  Purpose:  To add an item to the list
*************************************************************************/
template<typename T>
void LinkedList<T>::addItem(T val)
{
	if (head == NULL)
	{
		head = current = new Node<T>(val, NULL);
	}
	else
	{
		current = head;
		while (current->mNext != NULL)
		{
			current = current->mNext;
		}

		current->mNext = new Node<T>(val, NULL);
	}
}

/*     Pre:  An initialized linked list
*     Post:  The last node in the list is removed, and the pointer deleted
*  Purpose:  To remove the last node from the list, also to be used by the destructor
*************************************************************************/
template<typename T>
void LinkedList<T>::removeItem()
{
	if (head == NULL)
		return;
	if (head->mNext == NULL)
	{
		delete head;
		current = head = NULL;
		return;
	}
	
	current = head;
	while (current->mNext->mNext != NULL)
		current = current->mNext;

	delete current->mNext;
	current->mNext = NULL;
}

/*     Pre:  an initialized linked list
*     Post:  returns true if the list is empty, otherwise false
*  Purpose:  To check if the list is empty
*************************************************************************/
template<typename T>
bool LinkedList<T>::isEmpty()
{
	if (head == NULL)
		return true;
	return false;
}

/*     Pre:  an initialized linked list
*     Post:  returns the number of nodes in the list
*  Purpose:  To find the size of the array
*************************************************************************/
template<typename T>
int LinkedList<T>::size()
{
	int ct = 0;
	current = head;
	while (current->mNext != NULL)
	{
		ct++;
		current = current->mNext;
	}

	return ct;
}

/*     Pre:  an initialized linked list, an empty array of T values, and the size of that array, size must not exceed the size of the linked list
*     Post:   fills the provided array with the values in the nodes
*  Purpose:  To gather all the values stored inside of the nodes for easy iteration
*************************************************************************/
template<typename T>
void LinkedList<T>::getNodes(T nodeArr[], int n)
{
	current = head;
	for (int i = 0; i < n; i++)
	{
		if (current != NULL)
		{
			nodeArr[i] = current->mData;
			current = current->mNext;
		}
		else
		{
			return;
		}
	}
}


#endif