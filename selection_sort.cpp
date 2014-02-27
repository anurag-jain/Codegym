/*
Time Complexity: O(n^2)
Auxiliary Space: O(1)
The good thing about selection sort is it never makes O(n) swaps and can be useful when memory write is a costly operation.
*/

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <ctime>
#include <vector>
#include <iterator>
#define DEFAULT_INPUT_SIZE 10

#define DEFAULT_INPUT_SIZE 10

using namespace std;

template <class T>
void selectionSort(vector<T> &vec)
{
	T min;
	for(long i=0; i<vec.size();i++)
	{
		min = i;
		for(long j=i+1;j<vec.size();j++)
		{
			if(vec[j]<vec[min])
				min=j;
		}
		//swap vec[j] and vec[i]
		T tmp  = vec[i];
		vec[i] = vec[min];
		vec[min] = tmp;
	}
}

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		cout<<"USAGE: insertion_sort <number of elements>"<<endl;
		exit(1);
	}
	char *endPtr;
	long numElement = strtol(argv[1], &endPtr, 0);
	if(numElement == 0)
		numElement=DEFAULT_INPUT_SIZE;

	std::vector<int> inputVector;

	//inputVector.reserve(numElement);

	srand(time(NULL));
	while(numElement--)
	{
		inputVector.push_back(rand()%32767);
	}

	clock_t start_time = clock();
	selectionSort(inputVector);
	clock_t end_time = clock() - start_time;

	printf("The total for selectionSort: %ld click or (%f seconds)\n", end_time, ((double)end_time) / CLOCKS_PER_SEC );

	for (int i = 0; i < inputVector.size(); ++i)
	{
		printf("%d\n", inputVector[i]);
	}

	return 0;
}