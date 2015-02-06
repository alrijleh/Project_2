/*
SearchSort.h
Contains template functions for searching and sorting vectors

Fouad Al-Rijleh, Rachel Rudolph
*/
#pragma once

#include <vector>
#include <iostream>

using namespace std;

//vector functions
template<typename T> bool isSorted(vector<T> &A)
{
	for (int index = 0; index < A.size()-1 ; index++)
	{
		if (A[index] > A[index + 1]) return false;
	}
	return true;
}

//search functions
template<typename T> int linearSearch(const vector<T> &A, const T item)
{
	for (int index = 0; index < A.size(); index++)
	{
		if (A[index] == item) return index;
	}
	return -1;
}
template<typename T> int binarySearch(const vector<T> &A, const T item)
{
	int low = 0;
	int high = A.size();

	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (A[mid] == item) return mid;
		else if (A[mid] < item) low = mid + 1;
		else if (A[mid] > item) high = mid - 1;
	}
	return -1;
}

//sorting functions
template<typename T> void quickSort(vector<T> &A)
{
	SearchSort::quickSort(A, 0, A.size() );
}
template<typename T> void mergeSort(vector<T> &A)
{
	SearchSort::mergeSort(A, 0, A.size());
}
template<typename T> void insertionSort(vector<T> &A)
{
	for (int i = 1; i < A.size(); i++)
	{
		T key = A[i];
		int j = i;
		while (i > 0 && A[j-1] > key)
		{
			A[i] = A[i - 1];
			i--;
		}
		A[i] = key;
	}
}

//search and sorting fuctions - not for use outside of this file
namespace SearchSort
{
	//quickSort - implementation
	template<typename T>
	void quickSort(vector<T> &A, int low, int high)
	{
		int pivot;
		if (low < high)
		{
			pivot = SearchSort::partition(A, low, high);
			SearchSort::quickSort(A, low, pivot - 1);
			SearchSort::quickSort(A, pivot + 1, high);
		}
	
	}

	//quickSort - partition
	template<typename T>
	int partition(vector<T>& A, int low, int high)
	{
		int i = low - 1;

		for (int j = low; j < high; j++)
		{
			if (A[j] <= A[low])
			{
				i++;
				swap(A[i], A[j]);
			}

		}
		swap(A[i], A[low]);
		return i + 1;
	}

	//mergeSort - implementation
	template<typename T>
	void mergeSort(vector<T> &A, int low, int high)
	{
		if (low < high)
		{
			int mid = (low + high) / 2;
			mergeSort(A, low, mid);
			mergeSort(A, mid+1, high);
			merge(A, low, mid, high);
		}
	}

	//mergeSort - merge
	template<typename T>
	void merge(vector<T> &A, int low, int mid, int high)
	{

	}
}

//Operator overloads
template <typename T> ostream &operator<<(ostream &ostream, const vector<T> &vector)
{
	int last = vector.size() - 1;
	for (int index = 0; index < last; index++)
	{
		cout << vector[index] << ", ";
	}
	cout << vector[last];
	return ostream;
}