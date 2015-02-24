/*
Project 2a
main.cpp
Holds global functions getCandidate String and findMatches, calls search to solve crossword.

Fouad Al-Rijleh, Rachel Rudolph
*/

#include "main.h"

vector<string> getCandidateString(const Grid &grid)
{
	vector<string> wordList;
	string word;
	int wrapColumn, wrapRow;
	const int maxRow = grid.getRows(), maxColumn = grid.getColumns();

	for (int baseRow = 0; baseRow < maxRow; baseRow++)
	{
		for (int baseColumn = 0; baseColumn < maxColumn; baseColumn++)
		{

			//Case 1: Right
			wrapColumn = 0;
			word.clear();
			for (int charOffset = 0; charOffset < maxColumn; charOffset++)
			{
				if (baseColumn + charOffset > maxColumn - 1) //If it wraps right
				{
					word += grid.getChar(baseRow, wrapColumn);
					wrapColumn++;
				}
				else //Does not wrap
				{
					word += grid.getChar(baseRow, baseColumn + charOffset);
				}
				if (word.size() >= 5) //Keeps greater than or equal to 5 characters
					wordList.push_back(word); //Puts new word into wordList vector
			}

			//Case 2: Left
			wrapColumn = maxColumn - 1;
			word.clear();
			for (int charOffset = 0; charOffset < maxColumn; charOffset++)
			{
				if (baseColumn - charOffset < 0) //If it wraps
				{
					word += grid.getChar(baseRow, wrapColumn);
					wrapColumn--;
				}
				else //Does not wrap
				{
					word += grid.getChar(baseRow, baseColumn - charOffset);
				}
				if (word.size() >= 5) //Keeps greater than or equal to 5 characters
					wordList.push_back(word); //Puts new word into wordList vector
			}

			//Case 3: Down
			wrapRow = 0;
			word.clear();
			for (int charOffset = 0; charOffset < maxRow; charOffset++)
			{
				if (baseRow + charOffset > maxRow - 1) //If it wraps
				{
					word += grid.getChar(wrapRow, baseColumn);
					wrapRow++;
				}
				else //Does not wrap
				{
					word += grid.getChar(baseRow + charOffset, baseColumn);
				}
				if (word.size() >= 5) //Keeps greater than or equal to 5 characters
					wordList.push_back(word); //Puts new word into wordList vector
			}

			//Case 4: Up
			wrapRow = maxRow - 1;
			word.clear();
			for (int charOffset = 0; charOffset < maxRow; charOffset++)
			{
				if (baseRow - charOffset < 0) //If it wraps
				{
					word += grid.getChar(wrapRow, baseColumn);
					wrapRow--;
				}
				else //Does not wrap
				{
					word += grid.getChar(baseRow - charOffset, baseColumn);
				}
				if (word.size() >= 5) //Keeps greater than or equal to 5 characters
					wordList.push_back(word); //Puts new word into wordList vector
			}


			//Case 5: Down-Right
			wrapRow = 0;
			wrapColumn = 0;
			word.clear();
			for (int charOffset = 0; charOffset < maxRow; charOffset++)
			{
				//if wraps on down-right //crahes here?
				if ((baseColumn + charOffset >= maxColumn) && (baseRow + charOffset >= maxRow))
				{
					word += grid.getChar(wrapRow, wrapColumn);
					wrapColumn++;
					wrapRow++;
				}
				//if wraps down
				else if (baseRow + charOffset >= maxRow)
				{
					word += grid.getChar(wrapRow, baseColumn + charOffset);
					wrapRow++;
				}
				//if wraps right
				else if (baseColumn + charOffset >= maxColumn)
				{
					word += grid.getChar(baseRow + charOffset, wrapColumn);
					wrapColumn++;
				}
				//if does not wrap
				else if (!(baseColumn + charOffset >= maxColumn) && !(baseRow + charOffset >= maxRow))
				{
					word += grid.getChar(baseRow + charOffset, baseColumn + charOffset);
				}
				if (word.size() >= 5) //Keeps greater than or equal to 5 characters
					wordList.push_back(word); //Puts new word into wordList vector
			}

			//Case 6: Down-Left
			wrapRow = 0;
			wrapColumn = maxColumn - 1;
			word.clear();
			for (int charOffset = 0; charOffset < maxRow; charOffset++)
			{
				//if wraps on down-right //crahes here?
				if ((baseColumn - charOffset < 0) && (baseRow + charOffset >= maxRow))
				{
					word += grid.getChar(wrapRow, wrapColumn);
					wrapColumn--;
					wrapRow++;
				}
				//if wraps down
				else if (baseRow + charOffset >= maxRow)
				{
					word += grid.getChar(wrapRow, baseColumn - charOffset);
					wrapRow++;
				}
				//if wraps left
				else if (baseColumn - charOffset < 0)
				{
					word += grid.getChar(baseRow + charOffset, wrapColumn);
					wrapColumn--;
				}
				//if does not wrap
				else if (!(baseColumn + charOffset < 0) && !(baseRow + charOffset >= maxRow))
				{
					word += grid.getChar(baseRow + charOffset, baseColumn - charOffset);
				}
				if (word.size() >= 5) //Keeps greater than or equal to 5 characters
					wordList.push_back(word); //Puts new word into wordList vector
			}


			//Case 7: Up-Right
			wrapRow = maxRow - 1;
			wrapColumn = 0;
			word.clear();
			for (int charOffset = 0; charOffset < maxRow; charOffset++)
			{
				//if wraps on down-right
				if ((baseColumn + charOffset >= maxColumn) && (baseRow - charOffset < 0))
				{
					word += grid.getChar(wrapRow, wrapColumn);
					wrapColumn++;
					wrapRow--;
				}
				//if wraps down
				else if (baseRow - charOffset < 0)
				{
					word += grid.getChar(wrapRow, baseColumn + charOffset);
					wrapRow--;
				}
				//if wraps right
				else if (baseColumn + charOffset >= maxColumn)
				{
					word += grid.getChar(baseRow - charOffset, wrapColumn);
					wrapColumn++;
				}
				//if does not wrap
				else if (!(baseColumn + charOffset >= maxColumn) && !(baseRow - charOffset < 0))
				{
					word += grid.getChar(baseRow - charOffset, baseColumn + charOffset);
				}
				if (word.size() >= 5) //Keeps greater than or equal to 5 characters
					wordList.push_back(word); //Puts new word into wordList vector

			}
			//Case 7: Up-Left
			wrapRow = maxRow - 1;
			wrapColumn = maxColumn - 1;
			word.clear();
			for (int charOffset = 0; charOffset < maxRow; charOffset++)
			{
				//if wraps on up-left
				if ((baseRow - charOffset < 0) && (baseColumn - charOffset < 0))
				{
					word += grid.getChar(wrapRow, wrapColumn);
					wrapColumn--;
					wrapRow--;
				}
				//if wraps up
				else if (baseRow - charOffset < 0)
				{
					word += grid.getChar(wrapRow, baseColumn - charOffset);
					wrapRow--;
				}
				//if wraps left
				else if (baseColumn - charOffset < 0)
				{
					word += grid.getChar(baseRow - charOffset, wrapColumn);
					wrapColumn--;
				}
				//if does not wrap
				else if (!(baseRow - charOffset < 0) && !(baseColumn - charOffset < 0))

				{
					word += grid.getChar(baseRow - charOffset, baseColumn - charOffset);
				}
				if (word.size() >= 5) //Keeps greater than or equal to 5 characters
					wordList.push_back(word); //Puts new word into wordList vector
			}
		}
	}

	return wordList;
}

vector<string> findMatches(const wordList &wordList, const Grid &grid)
{
	vector<string> candidateStrings;
	vector<string> matchList;
	int location, previous = 0;
	clock_t time;

	//find possible words from grid
	cout << "Finding possible words..." << endl;
	candidateStrings = getCandidateString(grid);

	//sort list of possible words
	cout << "Sorting possible word list..." << endl;
	SearchSort::quickSort(candidateStrings);

	//find matches and return index
	cout << "Finding real words..." << endl;
	
	if (wordList.hasHash() == true)
	{
		for (int candidateIndex = 0; candidateIndex < candidateStrings.size(); candidateIndex++)
		{
			if (wordList.hashSearch(candidateStrings[candidateIndex]) )
			{
				matchList.push_back(candidateStrings[candidateIndex]); //If word is present in dictionary, add to list of found words
			}
		}
	}

	else
	{
		for (int candidateIndex = 0; candidateIndex < candidateStrings.size(); candidateIndex++)
		{
			location = wordList.binarySearch(candidateStrings[candidateIndex], previous);
			if (location != -1)
			{
				matchList.push_back(candidateStrings[candidateIndex]); //If word is present in dictionary, add to list of found words
				previous = location; //records the index of the last found word
			}
		}
	}

	return matchList;
}

void search(const int sortMethod, string filename)
{
	clock_t time, baseTime;
	vector<string> candidateWords, foundWords;
	
	baseTime = clock();

	//open grid file and create grid
	cout << "Opening input file..." << endl;
	Grid grid(filename);
	if (grid.getColumns() <= 40) cout << grid;

	//open word list and create dictionary
	cout << "Opening dictionary..." << endl;
	wordList dictionary("wordlist.txt");

	//sort the dictionary
	cout << "Sorting dictionary ";
	time = clock();
	switch (sortMethod)
	{
	case INSERTIONSORT:
		cout << "with insertionSort..." << endl;
		dictionary.insertionSort();
		break;
	case MERGESORT:
		cout << "with mergeSort..." << endl;
		dictionary.mergeSort();
		break;
	case QUICKSORT:
		cout << "with quickSort..." << endl;
		dictionary.quickSort(); 
		break;
	case HEAPSORT:
		cout << "with heapSort..." << endl;
		dictionary.heapSort();
		break;
	case HASH:
		cout << "into a hash table..." << endl;
		dictionary.createHashTable(5000); //5000 slots in table
		break;
	default:
		throw rangeError("sortMethod must be an int between 0 and 4");
		break;
	}
	time = clock() - time;
	cout << "CPU time to sort dictionary: " << time << endl;

	//find matches
	cout << "Finding words..." << endl;
	time = clock();
	foundWords = findMatches(dictionary, grid);
	time = clock() - time;
	cout << "CPU time to find words: " << time << endl;

	//display found words
	cout << foundWords.size() << " words found in grid:" << endl << endl;
	cout << foundWords << endl << endl;

	time = clock() - baseTime;
	cout << "Total CPU time to complete entire operation: " << time << endl << endl << endl;

	cout << "The CPU run time of  our heap sort was approximately 1400 while the run time of our hashtable was 4075 to sort the given wordlist. The general performance of heapSort has a runtime of O(nlongn) because it calls buildMaxHeap which is a function with runtime O(nlogn), a for loop with O(n) runtime, two lines with constant O(1) runtime and maxHeapify with a runtime of O(logn). Heap sort creates a local heap that has words added to it which is then sorted and copied to a vector. On the other hand, hashTable are direct address tables where each element has a key. In the worst case scenario, being all elements hash to the same location, the runtime is O(n) in addition to the amount of time it takes to complete the hash function.";
}

void main()
{
	try
	{
		string filename;
		//get user input
		cout << "Enter grid file name: ";
		cin >> filename;

		int sortMethod;
		cout << "Enter a digit:" << endl
			<< "[0] for insertionSort" << endl
			<< "[1] for mergeSort" << endl
			<< "[2] for quickSort" << endl
			<< "[3] for heapSort" << endl
			<< "[4] for hash table" << endl;
		cin >> sortMethod;

		search(sortMethod, filename);
	}
	catch (fileOpenError &ex)
	{
		cout << "fileOpenError: " << ex.what() << endl;
	}
	catch (rangeError &ex)
	{
		cout << "rangeError: " << ex.what() << endl;
	}

	system("pause");
}
