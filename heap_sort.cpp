/* Time complexity:
	maxHeapify is O(Logn).
	buildHeap() is O(n)
	overall time complexity of Heap Sort is O(nLogn).
*/

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <ctime>
#include <vector>
#include <iterator>
#define DEFAULT_INPUT_SIZE 10


template <class T>
void maxHeapify(std::vector<T> &vec, long i, long end)
{
	long max=i;
	long left = 2*i+1;
	long right= 2*i+2;

	if(left< end && vec[left] > vec[max])
		max = left;
	if(right < end && vec[right] > vec[max])
		max=right;

	if(max != i)
	{
		swap(vec[max],vec[i]);
		maxHeapify(vec, max, end);
	}

}

template <class T>
void buildHeap(std::vector<T> &vec)
{
	long inputLen = (long)vec.size();
	for(long i=(inputLen - (long)2)/2;i>=0;--i)
		maxHeapify(vec,i, inputLen);
}

template <class T>
void heapSort(std::vector<T> &vec , long start,  long end)
{
	buildHeap(vec);
	for(long i=end;i>0l;--i)
	{
		swap(vec[0],vec[end]);
		end= end-1;
		maxHeapify(vec,0l,end);

	}
}

template <class T>
void swap(T& A, T& B)
{
	T temp;
	temp=A;
	A=B;
	B=temp;
}


int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		std::cout<<"USAGE: heap_sort <number of elements>"<<std::endl;
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
	heapSort(inputVector, 0l, numElement-1);
	clock_t end_time = clock() - start_time;

	printf("The total for heapSort: %ld click or (%f seconds)\n", end_time, ((double)end_time) / CLOCKS_PER_SEC );

	for (int i = 0; i < inputVector.size(); ++i)
	{
		printf("%d\n", inputVector[i]);
	}

	return 0;
}