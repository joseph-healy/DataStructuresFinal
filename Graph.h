#pragma once
#ifndef _GRAPH_H
#define _GRAPH_H

#include <iostream>
#include "Set.h"
#include "LinkedList.h"
#include "PriorityQueue.h"

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
	LinkedList<MyPair<Vertex*, int>> adjacencyList;
};

struct Edge
{
	Vertex* v1;
	Vertex* v2;
	int weight;
};

class Graph
{

private:
	
	Set<Vertex*> verticies;
	Set<Edge*> edges;
	Vertex* source;

public: 
	Graph();
	Graph(Edge edges[], int n);
	void Dijkstra();
};

#endif