#pragma once

#include <iostream>
#include <vector>

using namespace std;
template<typename T>
class Heap
{
private:
	vector<T> vector;

public:
	Heap();
	Heap(vector<T> vector);
	~Heap();
	
	void setVector(vector<T> newVector)
	{
		vector = newVector;
	}
	vector<T> getVector() const
	{
		vector = newVector;
	}
	int getItem(int i) const
	{
		return vector[i + 1]
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
	void buildMaxHeap()
	{
		int heapSize = vector.size();
		for (int index = heapSize / 2; i >= 1; i--)
		{
			maxHeapify(vector[i]);
		}
	}

	void heapSort()
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
};

