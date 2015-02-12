#pragma once

#include <iostream>
#include <vector>

template<typename T>
class Heap
{
private:
	vector<T> vector;

public:
	Heap();
	Heap(vector<T> vector);
	~Heap();

	void setVector(vector<T> newVector);
	vector<T> getVector() const;

	int getItem(int i) const;

	int left(int i) const;
	int right(int i) const;
	int parent(int i) const;

	void initializeMaxHeap();
	void maxHeapify(int i);
	void buildMaxHeap();

	void heapSort();
};

