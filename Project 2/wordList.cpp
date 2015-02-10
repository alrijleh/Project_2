/*
wordList.cpp
Stores function to read words from file and store words into a vector. 
Also, stores functions that call sorting algorithms and overloaded print function.

Fouad Al-Rijleh, Rachel Rudolph
*/

#include "wordList.h"

//Default constructor
wordList::wordList()
{
}

//Default deconstructor
wordList::~wordList()
{
}

//Constructor that reads file of strings and stores words into vector 
wordList::wordList(string fileName)
{
	string word;
	
	ifstream fin;
	fin.open(fileName.c_str());

	//Check if file exists
	if (!fin)
	{
		throw fileOpenError(fileName);
	}
	
	//Setting dictionary words vector
	while ( !fin.eof() )
	{
		fin >> word;
		if (word.length() >= 5) words.push_back(word); //Ignore words that are too short
	}
	fin.close();
}

//Sets words
void wordList::setWords(vector<string> newWords)
{
	words = newWords;
}

//Gets words
vector<string> wordList::getWords() const
{
	return words;
}

//Calls insertionSort from SearchSort.h
void wordList::insertionSort()
{
	SearchSort::insertionSort(words);
}

//Calls quickSort from SearchSort.h
void wordList::quickSort()
{
	SearchSort::quickSort(words);
}

//Calls mergeSort from SearchSort.h
void wordList::mergeSort()
{
	SearchSort::mergeSort(words);
}

//Calls binarySearch from SearchSort.h
int wordList::binarySearch(const string &item) const
{
	return SearchSort::binarySearch(words, item);
}

//Calls binarySearch from SearchSort.h
int wordList::binarySearch(const string &item, int low) const
{
	return SearchSort::binarySearch(words, item, low);
}

//Calls linearSearch from SearchSort.h
int wordList::linearSearch(const string &item) const
{
	return SearchSort::linearSearch(words, item);
}

//Calls isSorted from SearchSort.h
bool wordList::isSorted() const
{
	return SearchSort::isSorted(words);
}

//Overloaded function to print wordList
ostream &operator<<(ostream &ostream, const wordList &wordList)
{
	return ostream;
}
