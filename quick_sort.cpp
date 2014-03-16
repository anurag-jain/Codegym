/*
Time Complexity:
				Worst: O(n^2)
				Best: O(nlog(n))
				Average: O(nlog(n))
Although the worst case time complexity of QuickSort is O(n2) which is more than many other sorting algorithms like Merge Sort and Heap Sort, QuickSort is faster in practice, because its inner loop can be efficiently implemented on most architectures, and in most real-world data. QuickSort can be implemented in different ways by changing the choice of pivot, so that the worst case rarely occurs for a given type of data. However, merge sort is generally considered better when data is huge and stored in external storage.
*/
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <ctime>
#include <vector>
#include <iterator>
#define DEFAULT_INPUT_SIZE 10

template <class T>
void swap(T &A, T &B)
{
	T temp;
	temp=A;
	A=B;
	B=temp;
}

template <class T, class T1>
void quickSort(std::vector<T> &vec, T1 start, T1 end)
{
	if(start < end)
	{
		T1 pivotPoint = partition(vec,start, end);
		quickSort(vec, start, pivotPoint - 1);
		quickSort(vec, pivotPoint + 1, end);
	}
}

template <class T, class T1>
int partition(std::vector<T>&A,T1 start, T1 end)
{
	T1 pivot = start;
	T1 i=pivot+1;
	T1 j=pivot+1;

	while(j<=end)
	{
		if(A[pivot]> A[j])
		{
			swap(A[i],A[j]);
			i++;
			j++;
		}
		else
		{
			j++;
		}
	}

	swap(A[pivot],A[i-1]);
	return i-1;
}



int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		std::cout<<"USAGE: insertion_sort <number of elements>"<<std::endl;
		exit(1);
	}
	char *endPtr;
	long numElement = strtol(argv[1], &endPtr, 0);
	if(numElement == 0)
		numElement=DEFAULT_INPUT_SIZE;

	std::vector<int> inputVector;

	//inputVector.reserve(numElement);

	srand(time(NULL));
	long i = numElement;
	while(i--)
	{
		inputVector.push_back(rand()%32767);
	}

	clock_t start_time = clock();
	quickSort(inputVector, 0l, numElement-1);
	clock_t end_time = clock() - start_time;

	printf("The total for quickSort: %ld click or (%f seconds)\n", end_time, ((double)end_time) / CLOCKS_PER_SEC );

	for (int i = 0; i < inputVector.size(); ++i)
	{
		printf("%d\n", inputVector[i]);
	}

	return 0;
}