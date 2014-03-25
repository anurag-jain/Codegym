/*
This is an addition to the graph_basic.cpp. Here I've used STL list container to represent a graph as opposed to structures and pointers.
The advantage is that you need not deal with scary multi-level pointers and it has less number of structures, and thus faster to code.

std::list provides constant time insertion and erase operation anywhere in sequence, and iteration in both directions.
Read more at
http://www.cplusplus.com/reference/list/list/
*/

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <ctime>
#include <list>
#include <vector>
#include <iterator>


class Graph
{
	int v;	//Number of vertices.
	std::list<int> *adjList;	//Pointer to the array of adjacency list

public:
	Graph(int v);
	void addEdge(int v, int w);
	void printGraph();
};

Graph::Graph(int numVertex)
{
	this->v = numVertex;
	adjList = new std::list<int>[numVertex];
}

void Graph::addEdge(int src, int dest)
{
	adjList[src].push_back(dest);
}

void Graph::printGraph()
{
	for(int i=0;i<v;i++)
	{
		std::cout<<std::endl<<"Adjacent vertex for "<<i<<std::endl<<"head ";
		std::list<int>::iterator it;
		it=adjList[i].begin();
		while(it != adjList[i].end())
		{
			std::cout<<"-> "<<*it;
			++it;
		}
	}

	std::cout<<std::endl;

}

int main(int argc, char * argv[])
{

	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.printGraph();

	return 0;
}