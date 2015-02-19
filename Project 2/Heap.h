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
	Heap();
	Heap(vector<T> newVector);
	~Heap();
	
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

	void initializeMaxHeap();
	void maxHeapify(int i)
	{
		int l = left(i);
		int r = right(i);
		int largest;
		if (l <= heapVector.size() && heapVector[l] > heapVector[i])
		{
			largest = l;
		}
		else largest = i;
		if (r <= heapVector.size() && heapVector[r] > heapVector[largest])
		{
			largest = r;
		}
		if (largest != i)
		{
			swap(heapVector[i], heapVector[largest]);
			maxHeapify(heapVector, largest);
		}
	}
	void buildMaxHeap()
	{
		int heapSize = heapVector.size();
		for (int index = heapSize / 2; i >= 1; i--)
		{
			maxHeapify(heapVector[i]);
		}
	}

	void heapSort()
	{
		buildMaxHeap(heapVector);
		int lastIndex = heapVector.size() - 1;
		for (int index = heapVector.size(); i >= 2; i--)
		{
			swap(heapVector[lastIndex], heapVector[index]);
			heapVector.resize(heapVector.size() - 1);
			maxHeapify(heapVector, lastIndex);
		}
	}
};

