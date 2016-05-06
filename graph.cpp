#include "Graph.h"


/*      Pre:  None
*     Post:  This object is initialized using default values
*  Purpose:  To intialize a Set object
*************************************************************************/
Graph::Graph()
{
	source = NULL;
}

/*     Pre:  An array of initialized Edge objects, and the amount of elements in that array
*     Post:  A weighted graph is generated from the provided edges
*  Purpose:  To intialize a weighted graph
*************************************************************************/
Graph::Graph(Edge edges[], int n)
{
	source = edges[0].v1;
	verticies.insert(source);
	verticies.insert(edges[0].v2);

	MyPair<Vertex*, int> tmp{ edges[0].v2, edges[0].weight };
	source->adjacencyList.addItem(tmp);

	for (int i = 1; i < n; i++)
	{
		verticies.insert(edges[i].v1);
		verticies.insert(edges[i].v2);
		this->edges.insert(&edges[i]);

		MyPair<Vertex*, int> adjacencyPair{ edges[i].v2, edges[i].weight };  
		verticies.get(edges[i].v1)->adjacencyList.addItem(adjacencyPair);
	}
}

void Graph::Dijkstra()
{

}
