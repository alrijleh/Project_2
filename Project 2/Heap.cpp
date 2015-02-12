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
	vector = newVector;
}

template<typename T>
vector<T> Heap<T>::getVector() const
{
	vector = newVector;
}

template <typename T>
int Heap<T>::getItem(int i) const
{
	return vector[i + 1]
}

//returns the left child to item i
template <typename T>
int Heap<T>::left(int i) const
{
	return i * 2;
}

//returns the right child to item i
template <typename T>
int Heap<T>::right(int i) const
{
	return i * 2 + 1;
}

//returns the parent to item i
template <typename T>
int Heap<T>::parent(int i) const
{
	return i / 2;
}

template <typename T>
void Heap<T>::initializeMaxHeap()
{

}

template <typename T>
void Heap<T>::maxHeapify(int i)
{

}

template <typename T>
void Heap<T>::buildMaxHeap()
{

}

template <typename T>
void Heap<T>::heapSort()
{

}