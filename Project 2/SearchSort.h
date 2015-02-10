/*
SearchSort.h
Contains template functions for searching and sorting vectors

Fouad Al-Rijleh, Rachel Rudolph
*/

#pragma once

#include <vector>
#include <iostream>

using namespace std;

namespace SearchSort
{
	//vector functions
	template<typename T> bool isSorted(const vector<T> &A)
	{
		for (int index = 0; index < A.size() - 1; index++)
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
		return binarySearch(A, item, 0);
	}
	template<typename T> int binarySearch(const vector<T> &A, const T item, int low)
	{
		int high = A.size() - 1;

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
		Internal::quickSort(A, 0, A.size() - 1);
	}
	template<typename T> void mergeSort(vector<T> &A)
	{
		vector<T> temp(A.size() - 1);
		Internal::mergeSort(A, temp, 0, A.size() - 1);
	}
	template<typename T> void insertionSort(vector<T> &A)
	{
		for (int i = 1; i < A.size(); i++)
		{
			T key = A[i];
			int j = i;
			while (i > 0 && A[j - 1] > key)
			{
				A[i] = A[i - 1];
				i--;
			}
			A[i] = key;
		}
	}

	//search and sorting fuctions - not for use outside of this file
	namespace Internal
	{
		//quickSort - implementation
		template<typename T>
		void quickSort(vector<T> &A, int low, int high)
		{
			int pivot;
			if (low < high)
			{
				pivot = Internal::partition(A, low, high);
				Internal::quickSort(A, low, pivot - 1);
				Internal::quickSort(A, pivot + 1, high);
			}

		}

		//quickSort - partition
		template<typename T>
		int partition(vector<T>& A, int low, int high)
		{
			//choose leftmost item as pivot
			int pivot = low;

			while (low < high)
			{
				while (A[low] <= A[pivot] && low < high)
					low++;
				while (A[high] > A[pivot])
					high--;
				if (low < high) swap(A[low], A[high]); //swap numbers to other side of pivot
			}

			swap(A[pivot], A[high]); //put pivot into correct location
			return  high; //return pivot location
		}

		//mergeSort - implementation
		template<typename T>
		void mergeSort(vector<T>& A, vector<T> &temp, int low, int high)
		{
			int mid;
			if (low < high)
			{
				mid = (low + high) / 2;
				mergeSort(A, temp, low, mid);
				mergeSort(A, temp, mid + 1, high);
				merge(A, temp, low, mid, high);
			}
		}

		//mergeSort - merge
		template<typename T>
		void merge(vector<T> &A, vector<T> &temp, int low, int mid, int high)
		{
			int i, j, k;
			//vector<T> L(mid - low + 1), R(high - mid);
			/*vector<T> temp(high+1);*/
			temp.resize(high + 1);
			i = low;
			k = low;
			j = mid + 1;
			while (i <= mid && j <= high)
			{
				if (A[i] < A[j])
				{
					//L[k] = A[i];          
					temp[k] = A[i];
					k++;
					i++;
				}
				else
				{
					//R[k] = A[j];
					temp[k] = A[j];
					k++;
					j++;
				}
			}
			while (i <= mid){
				//L[k] = A[i];
				temp[k] = A[i];
				k++;
				i++;
			}
			while (j <= high){
				//R[k] = A[j];
				temp[k] = A[j];
				k++;
				j++;
			}

			for (k = low; k <= high; k++)
			{
				A[k] = temp[k];
				
			}
		}
	}
}
//Operator overloads
template <typename T> ostream &operator<<(ostream &ostream, const vector<T> &vector)
{
	int last = vector.size() - 1;
	for (int index = 0; index < last; index++)
	{
		ostream << vector[index] << ", ";
	}
	ostream << vector[last];
	return ostream;
}