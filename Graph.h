#pragma once
#ifndef _GRAPH_H
#define _GRAPH_H

#include <iostream>
#include "Set.h"
#include "LinkedList.h"

//pair struct, 
//to be used to pair a vertex with a distance/weight in an adjancency list
template<typename T, typename R>
struct pair
{
	T x;
	R y;
};

class Graph
{

private:
	struct Vertex
	{
		int data;
		LinkedList<pair<Vertex*, int>> adjacencyList;

	};
	struct Edge
	{
		Vertex v1, v2;
	};

	Set<Vertex*> verticies;
	Set<Edge*> edges;
	Vertex* source;

public: 

	Graph();
	Graph(int v, int e);
	Graph(int v[]);
	
};

#endif