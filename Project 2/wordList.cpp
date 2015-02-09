#include "wordList.h"

wordList::wordList()
{
}

wordList::~wordList()
{
}

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
		if (word.length() >= 5) words.push_back(word); //ingore words that are too short
	}
	fin.close();
}

void wordList::setWords(vector<string> newWords)
{
	words = newWords;
}

vector<string> wordList::getWords() const
{
	return words;
}

void wordList::insertionSort()
{
	SearchSort::insertionSort(words);
}

void wordList::quickSort()
{
	SearchSort::quickSort(words);
}

void wordList::mergeSort()
{
	SearchSort::mergeSort(words);
}

int wordList::binarySearch(const string &item) const
{
	return SearchSort::binarySearch(words, item);
}

int wordList::binarySearch(const string &item, int low) const
{
	return SearchSort::binarySearch(words, item, low);
}

int wordList::linearSearch(const string &item) const
{
	return SearchSort::linearSearch(words, item);
}

bool wordList::isSorted() const
{
	return SearchSort::isSorted(words);
}

ostream &operator<<(ostream &ostream, const wordList &wordList)
{
	return ostream;
}
