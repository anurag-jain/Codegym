/*
Insertion Sort
Time Complexity: O(n^2)
Auxilary Space: O(1)
Boundary Cases: worst case when array is sorted in reverse.
Insertion sort is uses when number of elements is small. It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array.
*/

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <ctime>
#include <vector>
#include <iterator>

#define DEFAULT_INPUT_SIZE 10

using namespace std;

template <class T>
void insertSort(vector<T> &vec)
{
	T pivot;
	int j;
	for(long i=1;i<vec.size();i++)
	{
		pivot 	= vec[i];
		j 		= i-1;
		while(j>=0 && vec[j] > pivot)
		{
			vec[j+1] = vec[j];
			j--;
		}
		vec[j+1] = pivot;
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
	double total_time;
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
	insertSort(inputVector);
	clock_t end_time = clock() - start_time;

	printf("The total for insertSort: %ld click or (%f seconds)\n", end_time, ((double)end_time) / CLOCKS_PER_SEC );

	for (int i = 0; i < inputVector.size(); ++i)
	{
		printf("%d\n", inputVector[i]);
	}

	return 0;
}