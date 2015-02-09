/*
wordList.h

Fouad Al-Rijleh, Rachel Rudolph
*/
#pragma once
#include "SearchSort.h"
#include "d_except.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class wordList
{
private:
	vector<string> words;

public:

	wordList();
	wordList(string fileName);
	~wordList();

	void setWords(vector<string> newWords);
	vector<string> getWords() const;

	void insertionSort();
	void quickSort();
	void mergeSort();
	int binarySearch(const string &item) const;
	int binarySearch(const string &item, int low) const;
	int linearSearch(const string &item) const;

	bool isSorted() const;

	friend ostream &operator<<(ostream &ostream, const wordList &wordList);
};
