#include "wordList.h"


wordList::wordList()
{
}


wordList::~wordList()
{
}

wordList::wordList(string fileName)
{
	string x;
	
	ifstream fin;
	fin.open(fileName.c_str());

	//Check if file exists
	if (!fin)
	{
		cout << "Could not read dictionary file." << endl;
	}
	
	//Setting dictionary words vector
	while (!fin.eof())
	{
		fin >> x;
		words.push_back(x);
	}
	fin.close();
}

void insertionSort()
{}

void quickSort()
{}

void mergeSort()
{}

void binarySort()
{}

ostream &operator<<(ostream &ostream, const wordList &wordList)
{
	return ostream;
}
