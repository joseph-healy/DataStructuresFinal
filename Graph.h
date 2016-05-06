#pragma once
#ifndef _GRAPH_H
#define _GRAPH_H

#include <iostream>
#include "Set.h"
#include "LinkedList.h"
#include "PriorityQueue.h"
#include "HelperStructs.h"

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