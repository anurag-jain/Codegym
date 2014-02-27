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
	long numElement = strtol(argv[1], &endPtr, 0);
	if(numElement == 0)
		numElement=DEFAULT_INPUT_SIZE;

	std::vector<int> inputVector;

	//inputVector.reserve(numElement);

	srand(time(NULL));
	while(numElement--)
	{
		printf("%ld\n", numElement);
		inputVector.push_back(rand()%32767);
	}

	insertSort(inputVector);

	for (int i = 0; i < inputVector.size(); ++i)
	{
		printf("%d\n", inputVector[i]);
	}



	return 0;
}