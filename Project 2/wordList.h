/*
wordList.h
Stores function to read words from file and store words into a vector.
Also, stores functions that call sorting algorithms and overloaded print function.

Fouad Al-Rijleh, Rachel Rudolph
*/
#pragma once
#include "SearchSort.h"
#include "d_except.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Hashtable.h"
#include "Heap.h"

using namespace std;

class wordList
{
private:
	vector<string> words;
	Hashtable<string> hashtable;
	Heap<string> heap;

public:

	wordList();
	wordList(string fileName);
	~wordList();

	void setWords(vector<string> newWords);
	vector<string> getWords() const;

	void insertionSort();
	void quickSort();
	void mergeSort();
	void heapSort();
	int binarySearch(const string &item) const;
	int binarySearch(const string &item, int low) const;
	int linearSearch(const string &item) const;

	void createHashTable();
	bool hasHash() const;
	bool hashSearch(const string &item) const;

	bool isSorted() const;

	friend ostream &operator<<(ostream &ostream, const wordList &wordList);
};
