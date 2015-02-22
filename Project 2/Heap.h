#pragma once

#include <iostream>
#include <vector>

using namespace std;
template<typename T>
class Heap
{
private:
	vector<T> heapVector;

public:
	Heap()
	{

	}
	
	Heap(vector<T> newVector)
	{
		setVector(newVector);
	}

	~Heap()
	{

	}
	
	void setVector(vector<T> newVector)
	{
		heapVector = newVector;
	}
	vector<T> getVector() const
	{
		return heapVector;
	}
	int getItem(int i) const
	{
		return heapVector[i + 1]
	}

	int left(int i) const
	{
		return i * 2;
	}
	int right(int i) const
	{
		return i * 2 + 1;
	}
	int parent(int i) const
	{
		return i / 2;
	}

	void initializeMaxHeap()
	{

	}

	void maxHeapify(int heapSize, int i)
	{
		int l = left(i);
		int r = right(i);
		int largest;
		if (l < heapSize && heapVector[l] > heapVector[i])
		{
			largest = l;
		}
		else largest = i;
		if (r < heapSize && heapVector[r] > heapVector[largest])
		{
			largest = r;
		}
		if (largest != i)
		{
			swap(heapVector[i], heapVector[largest]);
			maxHeapify(heapSize, largest);
		}
	}
	void buildMaxHeap()
	{
		int heapSize = heapVector.size();
		for (int index = heapSize / 2; index >= 0; index--)
		{
			maxHeapify(heapSize, index);
		}
	}

	void heapSort()
	{
		buildMaxHeap();
		int heapSize = heapVector.size();
		for (int lastIndex = heapVector.size() - 1; lastIndex >=1; lastIndex--)
		{
			swap(heapVector[0], heapVector[lastIndex]);
			heapSize--;
			maxHeapify(heapSize, 0);
		}
	}

	friend ostream &operator<<(ostream &ostream, const Heap<int> &heap);
};

//Overloaded function to print heap
ostream &operator<<(ostream &ostream, const Heap<int> &heap)
{
	for (int i = 0; i < heap.getVector().size(); i++)
	{
		cout << heap.getVector()[i] << "  ";
	}
	return ostream;
}

