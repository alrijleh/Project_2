/*
SearchSort.cpp
contains template functions for searching and sorting

Fouad Al-Rijleh, Rachel Rudolph
*/
#include "SearchSort.h"

//quickSort template function
template<typename T> void quickSort(vector<T> vector, int left, int right)
{
	if (left < right)
	{
		s = partition(vector, left, right);
		quickSort(vector, left, s-1);
		quickSort(vector, s+1, right);
	}
}

//swap function
template<typename T> void swap(T a, T b)
{
	T temp = b;
	b = a;
	a = temp;
}

//partition function for quicksort
template<typename T> int partition(vector<T> vector, int left, int right)
{
	
	int i = left;
	int r = right + 1;
	T p = vector[left];
	do
	{

		do
		{
			i++;
		} while (vector[i] < p && vector[i] < right);

		do
		{
			j--;
		} while (vector[i] > p);

		swap(vector[i], vector[j]);
	} while (i < j);

	swap(vector[i], vector[j]);
	swap(vector[left], vector[j]);
	
	return j;
}