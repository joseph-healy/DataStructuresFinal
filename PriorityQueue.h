#pragma once
#ifndef __PRIORITY_QUEUE_
#define __PRIORITY_QUEUE_

#include "Graph.h"

using namespace std;


/*Priority Queue class
Implemeneted by using a min heap
Implemented to be used with Vertex objects in the graph class
*/
class PriorityQueue
{
private:
	const int DEFAULT_SIZE = 5;
	int size;
	Vertex** heap; // dynapic array of verticies

	void heapify();
public:
	PriorityQueue();
	PriorityQueue(int size);
	PriorityQueue(Vertex* verticies[], int size);
	void removeMin();
	void insert(Vertex* val);
	~PriorityQueue();
};

/*     Pre:  None
*     Post:  This object is initialized using default values. Default size is 5
*  Purpose:  To intialize a Priority Queue object
*************************************************************************/
PriorityQueue::PriorityQueue()
{
	this->size = DEFAULT_SIZE;
	this->heap = new Vertex*[size];

	for (int i = 0; i < size; i++)
		heap[i] = NULL;

}

/*     Pre:  A valid size
*     Post:  This object is initialized using the passed in size.
*  Purpose:  To intialize a Priority Queue object
*************************************************************************/
PriorityQueue::PriorityQueue(int size)
{
	this->size = size + 1; // to accomadate for the null value at the beggining
	this->heap - new Vertex*[this->size];

	for (int i = 0; i < size; i++)
		heap[i] = NULL;
}

/*     Pre:  An array of pointers to vertex objects A valid size
*     Post:  This object is initialized using the provided verticies. Calls the heapify function
*  Purpose:  To intialize a Priority Queue object
*************************************************************************/
PriorityQueue::PriorityQueue(Vertex* verticies[], int size)
{
	this->size = size + 1; // to accomadate for the null value at the beggining
	this->heap = new Vertex*[this->size];
	heap[0] = NULL;
	for (int i = 0; i < size; i++)
	{
		heap[i + 1] = verticies[i];
	}

	heapify();
	
}

/*     Pre:  an initialized Priority queue
*     Post:  The heap array is heapified, minimum value "at the top" or in the front of the array
*  Purpose:  To intialize a Priority Queue object
*************************************************************************/
void PriorityQueue::heapify()
{
	for (int i = size / 2; i > 0; i--)
	{
		int k = i;
		Vertex* v = heap[k];
		bool isHeap = false;
		while (!isHeap && 2 * k <= size)
		{
			int j = 2 * k;
			if (j < size) //two kiddos
			{
				if (heap[j]->data > heap[j + 1]->data)
					j++;
				if (v->data <= heap[j]->data)
					isHeap = true;
				else
				{
					heap[k] = heap[j];
					k = j;
				}
			}
		}
		heap[k] = v;
	}
}

/*     Pre:  an initialized Priority queue
*     Post:  The minimum element of the queue is removed
*  Purpose:  To remove the minimum element from a priority queue
*************************************************************************/
void PriorityQueue::removeMin()
{
	heap[1] = heap[size - 1]; //heap[1] is root, heap[size-1] is the last element
	this->size = this->size - 1;
	heapify();
}

/*     Pre:  an initialized Priority queue
*     Post:  val is inserted into the appropriate place on the queue
*  Purpose:  To insert an element into the queue
*************************************************************************/
void PriorityQueue::insert(Vertex* val)
{
	Vertex** temp = new Vertex*[this->size + 1];
	temp[0] = NULL;
	for (int i = 1; i < this->size; i++)
	{
		temp[i] = heap[i];
	}

	this->size++;
	temp[this->size] = val;
	heap = temp;
	heapify();
}

PriorityQueue::~PriorityQueue()
{
}


#endif