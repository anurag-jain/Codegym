/*
The below code is a basic implementation of a undirected graph using adjacency list. This can easily be extended to directed and weighted graphs. See comments in code for related annotations.

There are two variations of graph representations
1: Adjacency matrix
	Pro:
		Good for finding if an edge exists between two nodes in O(1) time.
		Easy implementation.
	Con:
		Takes O(n^2) memory even if the graph is sparse.
		Hard to add a new vertex. O(V^2).

2: Adjacency list
	Pro:
		Saves space. O(|V|+|E|) in average case; O(V^2) in worst case.
		Adding a new vertex is easier.
	Cons:
		Inefficient to find if an edge from vertex u to vertex v exists or not. O(V).

*/
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <ctime>
#include <vector>
#include <iterator>


struct adjNode
{
	//Add int weight parameters(two for directed graphs) in case of weighted graphs.
	int dest;
	adjNode *next;
};

struct vertex
{
	adjNode *head;
};

struct graph
{
	int V;
	vertex *array;
};

struct adjNode* createAdjNode(int dst)
{
	adjNode *adj = (adjNode *) malloc(sizeof(adjNode));
	adj->dest = dst;
	adj->next = NULL;

	return adj;
}

struct graph* createGraph(int numVertex)
{
	graph *newGraph = (graph *) malloc(sizeof(graph));
	newGraph->V = numVertex;

	newGraph->array = (vertex *)malloc(numVertex*sizeof(vertex));

	for(int i=0;i<numVertex;i++)
	{
		newGraph->array[i].head = NULL;  // Can also be referenced as newGraph->(array+i)->head
	}

	return newGraph;
}

void createEdge(graph *g, int src, int dest)
{
	adjNode *node = createAdjNode(dest);
	node->next = g->array[src].head;
	g->array[src].head = node;

	//Since its a undirected graph we add another edge from destination to source. No applicable for directed graph.
	node = createAdjNode(src);
	node->next = g->array[dest].head;
	g->array[dest].head = node;
}

void printGraph( graph *g)
{

	for(int i=0;i<g->V;i++)
	{
		adjNode *iterator = g->array[i].head;
		printf("\n Adjacent vertex for %d\n head", i);
		while(iterator)
		{
			printf("--> %d", iterator->dest);
			iterator=iterator->next;
		}
	}
}


int main(int argc, char * argv[])
{

	int numVertex = 5;

	graph *newGraph = createGraph(numVertex);

  	createEdge(newGraph, 0, 1);
    createEdge(newGraph, 0, 4);
    createEdge(newGraph, 1, 2);
    createEdge(newGraph, 1, 3);
    createEdge(newGraph, 1, 4);
    createEdge(newGraph, 2, 3);
    createEdge(newGraph, 3, 4);

    printGraph(newGraph);

    return 0;

}