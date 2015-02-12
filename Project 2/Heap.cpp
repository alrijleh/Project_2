#include "Heap.h"

template <typename T>
Heap<T>::Heap()
{
}

template <typename T>
Heap<T>::~Heap()
{
}

template <typename T>
void Heap<T>::setVector(vector<T> newVector)
{

}


template <typename T>
vector<T> Heap<T>::getVector() const
{

}

template <typename T>
int Heap<T>::getItem(int i) const
{

}

template <typename T>
int Heap<T>::left(int i) const
{

}

template <typename T>
int Heap<T>::right(int i) const
{

}

template <typename T>
int Heap<T>::parent(int i) const
{

}

template <typename T>
void Heap<T>::initializeMaxHeap()
{

}

template <typename T>
void Heap<T>::maxHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int largest; 
	if (l <= vector.size() && vector[l] > vector[i])
	{
		largest = l;
	}
	else largest = i;
	if (r <= vector.size() && vector[r] > vector[largest])
	{
		largest = r;
	}
	if (largest != i)
	{
		swap(vector[i], vector[largest]);
		maxHeapify(vector, largest);
	}
}

template <typename T>
void Heap<T>::buildMaxHeap()
{
	int heapSize = vector.size();
	for (int index = heapSize / 2; i >= 1; i--)
	{
		maxHeapify(vector[i]);
	}
}

template <typename T>
void Heap<T>::heapSort()
{
	buildMaxHeap(vector);
	int lastIndex = vector.size() - 1;
	for (int index = vector.size(); i >= 2; i--)
	{
		swap(vector[lastIndex], vector[index]);
		vector.resize(vector.size() - 1);
		maxHeapify(vector, lastIndex);
	}
}