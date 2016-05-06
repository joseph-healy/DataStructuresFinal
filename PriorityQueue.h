#pragma once
#ifndef __PRIORITY_QUEUE_
#define __PRIORITY_QUEUE_


using namespace std;

#include "HelperStructs.h"

/*Priority Queue class
Implemeneted by using a min heap
Implemented to be used with Vertex objects in the graph class
*/
class PriorityQueue
{
private:
	const int DEFAULT_SIZE = 10;
	int size; //values filled in array
	int realSize; // actual size of array to be used in resizing
	Vertex** heap; // dynapic array of verticies

	void heapify();
public:
	PriorityQueue();
	PriorityQueue(Vertex* verticies[], int size);
	void removeMin();
	void insert(Vertex* val);
	Vertex* getMin();
	~PriorityQueue();
};

/*     Pre:  None
*     Post:  This object is initialized using default values. Default size is 5
*  Purpose:  To intialize a Priority Queue object
*************************************************************************/
PriorityQueue::PriorityQueue()
{
	this->size = 0;
	this->heap = new Vertex*[DEFAULT_SIZE];
	this->realSize = DEFAULT_SIZE;

	heap[0] = NULL;

}

/*     Pre:  An array of pointers to vertex objects A valid size
*     Post:  This object is initialized using the provided verticies. Calls the heapify function
*  Purpose:  To intialize a Priority Queue object
*************************************************************************/
PriorityQueue::PriorityQueue(Vertex* verticies[], int size)
{
	this->size = size + 1; // to accomadate for the null value at the beggining

	if (size > DEFAULT_SIZE)
	{
		this->heap = new Vertex*[this->size];
		realSize = this->size;
	}
	else
	{
		this->heap = new Vertex*[DEFAULT_SIZE];
		realSize = DEFAULT_SIZE;
	}

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
				if (heap[j]->distance > heap[j + 1]->distance)
					j++;
				if (v->distance <= heap[j]->distance)
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
	this->size++;
	if (this->size > realSize)
	{
		Vertex** temp = new Vertex*[realSize*2];
		temp[0] = NULL;
		for (int i = 1; i < this->size; i++)
		{
			temp[i] = heap[i];
		}
		temp[this->size] = val;
		heap = temp;
	}
	else
	{
		heap[this->size] = val;
	}

	heapify();
}

Vertex* PriorityQueue::getMin()
{
	return heap[1];
}

PriorityQueue::~PriorityQueue()
{
}


#endif