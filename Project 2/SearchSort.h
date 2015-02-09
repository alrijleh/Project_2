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
		Internal::quickSort(A, 0, A.size() - 1);
	}
	template<typename T> void mergeSort(vector<T> &A)
	{
		Internal::mergeSort(A, 0, A.size()-1);
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
		void mergeSort(vector<T>& A, int low, int high)
		{
			int mid;
			if (low < high)
			{
				mid = (low + high) / 2;
				mergeSort(A, low, mid);
				mergeSort(A, mid + 1, high);
				merge(A, low, mid, high);
			}
		}

		//mergeSort - merge
		template<typename T>
		void merge(vector<T> &A, int low, int mid, int high)
		{
			int i, j, k;
			vector<T> c = A;
			i = low;
			k = low;
			j = mid + 1;

			while (i <= mid && j <= high)
			{
				if (A[i] < A[j])
				{
					A[k] = A[i];
					k++;
					i++;
				}
				else
				{
					A[k] = A[j];
					k++;
					j++;
				}
				break;
			}
			while (i <= mid)
			{
				c[k] = A[i];
				k++;
				i++;
			}
			while (j <= high)
			{
				c[k] = A[j];
				k++;
				j++;
			}
			for (i = low; i < k; i++)
			{
				A[i] = c[i];
				cout << A[i] << endl;
			}
			cout << "=====" << endl;
		}


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