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
	T p = vector[left];
	int i = left;
	int r = right + 1;

	do
	{

		do
		{
			i++;
		} while (vector[i] < p && vector[i] < r);

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

//insertionSort template function
template<typename T> void insertionSort(vector<T> vector)
{
	int i, j;
	for (i = 1; i < vector.size(); i++)
	{
		j = i;
		while (j > 0 && vector[j - 1] > vector[j])
		{
			swap(vector[j], vector[j - 1]);
			j--;
		}
	}
}

//mergeSort template function
template<typename T> void mergeSort(vector<T> vector, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		mergeSort(vector, p, q);
		mergeSort(vector, q + 1, r);
		merge(vector, p, q, r);
	}
}

//merge
template <typename T> void merge(vector <T> vector, int p, int q, int r)
{
	int n1 = q - p + 1; //number of elements in 1st array
	int n2 = r - q;     //number of elements in 2nd array
	for (int i = 1; i < n1; i++)
	{
		L[i] 
	}
}