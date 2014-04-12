/*
This is breadth first search implementation for a connected undirected graph.
Time Complexity: O(V+E), where V is number of vertices in the graph and E is number of edges in the graph.
Applications:
1: Finding if there is a path between two vertices.
2: Useful for finding shortest path in terms of number of edges(hops).
3: Computing connected components of an undirected graph.
4: To check if a graph is bi-partile or not.
*/

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <ctime>
#include <vector>
#include <iterator>

//Graph structures.

struct adjNode
{
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

//Queue structures

struct queueNode
{
	int data;
	queueNode *next;
};

struct queue
{
	queueNode *front;
	queueNode *rear;
};

//Queue functions

struct queueNode *createQNode(int num)
{
	queueNode *newNode = (queueNode *)malloc(sizeof(queueNode));
	newNode->data 	= num;
	newNode->next	= NULL;

	return newNode;
}

struct queue *createQueue()
{
	queue *newQueue = (queue *)malloc(sizeof(queue));
	newQueue->front=newQueue->rear=NULL;
	return newQueue;
}

void enque(queue *myQueue , int num)
{
	queueNode *newNode = createQNode(num);

	if(myQueue->rear == NULL)
	{
		myQueue->front = myQueue->rear = newNode;
		return;
	}

	myQueue->rear->next = newNode;
	myQueue->rear = newNode;
}

int deque(queue *myQueue)
{
	if(myQueue->front == NULL)
	{
		printf("empty queue\n");
		return -1;
	}

	queueNode *temp = myQueue->front;
	myQueue->front = myQueue->front->next;
	int value = temp->data;
	free(temp);

	//Resetting rear pointer to NULL when front becomes NULL i.e queue gets empty.
	if(myQueue->front == NULL)
		myQueue->rear = NULL;

	return value;
}

//Graph functions.
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

void bredthFirstSearch(graph *g, int src )
{

	bool *visited		= (bool *)malloc(sizeof(bool)*g->V);

	for(int i=0;i<g->V;i++)
	{
		visited[i]=false;
	}

    struct queue *bfsQueue = createQueue();
    enque(bfsQueue, src);
    visited[src] =  true;

    while(bfsQueue->front != NULL)
    {
    	src = deque(bfsQueue);
    	printf(" ->%d ", src);

    	for( adjNode *i= g->array[src].head; i!= NULL ; i=i->next)
    	{
    		if(!visited[i->dest])
    		{
    			visited[i->dest] = true;
    			enque(bfsQueue,i->dest);
    		}
    	}

    }

}


int main(int argc, char *argv[])
{

	int numVertex = 10;

	graph *newGraph = createGraph(numVertex);

	createEdge(newGraph, 0, 1);
	createEdge(newGraph, 0, 2);
    createEdge(newGraph, 1, 2);
    createEdge(newGraph, 1, 3);
    createEdge(newGraph, 2, 3);
    createEdge(newGraph, 2, 4);
 	createEdge(newGraph, 3, 4);
 	createEdge(newGraph, 3, 5);
    createEdge(newGraph, 4, 5);
    createEdge(newGraph, 4, 6);
    createEdge(newGraph, 5, 6);
    createEdge(newGraph, 5, 7);
    createEdge(newGraph, 6, 7);
    createEdge(newGraph, 6, 8);
    createEdge(newGraph, 7, 8);
    createEdge(newGraph, 7, 9);
    createEdge(newGraph, 8, 9);

    bredthFirstSearch(newGraph, 0);

	return 0;
}