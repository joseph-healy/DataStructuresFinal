#pragma once
#ifndef __HELPER_STRUCTS_H
#define __HELPER_STRUCTS_H

#include "LinkedList.h"

//pair struct, 
//to be used to pair a vertex with a distance/weight in an adjancency list
template<typename T, typename R>
struct MyPair
{
	T x;
	R y;
};

struct Vertex
{
	int data;
	int distance;
	Vertex* previous;
	LinkedList<MyPair<Vertex*, int>> adjacencyList;
};

struct Edge
{
	Vertex* v1;
	Vertex* v2;
	int weight;
};

#endif