/*
wordList.h

Fouad Al-Rijleh, Rachel Rudolph
*/
#pragma once
#include "SearchSort.h"
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
	vector<string> getWords();

	void insertionSort();
	void quickSort();
	void mergeSort();
	int binarySearch(string item) const;
	int linearSearch(string item) const;

	friend ostream &operator<<(ostream &ostream, const wordList &wordList);
};
