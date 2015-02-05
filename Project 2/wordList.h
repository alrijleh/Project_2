/*
wordList.h

Fouad Al-Rijleh, Rachel Rudolph
*/
#pragma once
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
	~wordList();

	void readWords(string fileName);

	void insertionSort();
	void quickSort();
	void mergeSort();
	void binarySort();

	friend ostream &operator<<(ostream &ostream, const wordList &wordList);
};
