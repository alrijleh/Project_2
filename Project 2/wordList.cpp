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
		cout << "Could not read dictionary file." << endl;
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

vector<string> wordList::getWords()
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

int wordList::binarySearch(string item) const
{
	return SearchSort::binarySearch(words, item);
}

int wordList::linearSearch(string item) const
{
	return SearchSort::linearSearch(words, item);
}

ostream &operator<<(ostream &ostream, const wordList &wordList)
{
	return ostream;
}
