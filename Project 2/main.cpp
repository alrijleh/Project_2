#include "main.h"

vector<string> getCandidateString(grid grid)
{
	vector<string> wordList;
	string word;
	int wrapColumn;
	int wrapRow;

	for (int baseRow = 0; baseRow < grid.getRows(); baseRow++)
	{
		for (int baseColumn = 0; baseColumn < grid.getColumns(); baseColumn++)
		{

			//Case 1: Right
			wrapColumn = 0;
			word.clear();
			for (int charOffset = 0; charOffset < grid.getColumns(); charOffset++)
			{
				if (baseColumn + charOffset > grid.getColumns() - 1) //If it wraps right
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
			wrapColumn = grid.getColumns() - 1;
			word.clear();
			for (int charOffset = 0; charOffset < grid.getColumns(); charOffset++)
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
			for (int charOffset = 0; charOffset < grid.getRows(); charOffset++)
			{
				if (baseRow + charOffset > grid.getRows() - 1) //If it wraps
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
			wrapRow = grid.getRows() - 1;
			word.clear();
			for (int charOffset = 0; charOffset < grid.getRows(); charOffset++)
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
			for (int charOffset = 0; charOffset < grid.getRows(); charOffset++)
			{
				//if wraps on down-right //crahes here?
				if ((baseColumn + charOffset >= grid.getColumns()) && (baseRow + charOffset >= grid.getRows()))
				{
					word += grid.getChar(wrapRow, wrapColumn);
					wrapColumn++;
					wrapRow++;
				}
				//if wraps down
				else if (baseRow + charOffset >= grid.getRows())
				{
					word += grid.getChar(wrapRow, baseColumn + charOffset);
					wrapRow++;
				}
				//if wraps right
				else if (baseColumn + charOffset >= grid.getColumns())
				{
					word += grid.getChar(baseRow + charOffset, wrapColumn);
					wrapColumn++;
				}
				//if does not wrap
				else if (!(baseColumn + charOffset >= grid.getColumns()) && !(baseRow + charOffset >= grid.getRows()))
				{
					word += grid.getChar(baseRow + charOffset, baseColumn + charOffset);
				}
				if (word.size() >= 5) //Keeps greater than or equal to 5 characters
					wordList.push_back(word); //Puts new word into wordList vector
			}

			//Case 6: Down-Left
			wrapRow = 0;
			wrapColumn = grid.getColumns() - 1;
			word.clear();
			for (int charOffset = 0; charOffset < grid.getRows(); charOffset++)
			{
				//if wraps on down-right //crahes here?
				if ((baseColumn - charOffset < 0) && (baseRow + charOffset >= grid.getRows()))
				{
					word += grid.getChar(wrapRow, wrapColumn);
					wrapColumn--;
					wrapRow++;
				}
				//if wraps down
				else if (baseRow + charOffset >= grid.getRows())
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
				else if (!(baseColumn + charOffset < 0) && !(baseRow + charOffset >= grid.getRows()))
				{
					word += grid.getChar(baseRow + charOffset, baseColumn - charOffset);
				}
				if (word.size() >= 5) //Keeps greater than or equal to 5 characters
					wordList.push_back(word); //Puts new word into wordList vector
			}


			//Case 7: Up-Right
			wrapRow = grid.getRows() - 1;
			wrapColumn = 0;
			word.clear();
			for (int charOffset = 0; charOffset < grid.getRows(); charOffset++)
			{
				//if wraps on down-right
				if ((baseColumn + charOffset >= grid.getColumns()) && (baseRow - charOffset < 0))
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
				else if (baseColumn + charOffset >= grid.getColumns())
				{
					word += grid.getChar(baseRow - charOffset, wrapColumn);
					wrapColumn++;
				}
				//if does not wrap
				else if (!(baseColumn + charOffset >= grid.getColumns()) && !(baseRow - charOffset < 0))
				{
					word += grid.getChar(baseRow - charOffset, baseColumn + charOffset);
				}
				if (word.size() >= 5) //Keeps greater than or equal to 5 characters
					wordList.push_back(word); //Puts new word into wordList vector

			}
			//Case 7: Up-Left
			wrapRow = grid.getRows() - 1;
			wrapColumn = grid.getColumns() - 1;
			word.clear();
			for (int charOffset = 0; charOffset < grid.getRows(); charOffset++)
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

vector<string> findMatches(wordList wordList, grid grid)
{
	vector<string> candidateStrings;
	vector<string> matchList;
	int location;

	//By this point wordList has been sorted
	candidateStrings= getCandidateString(grid);
	//SearchSort::quickSort(candidateStrings)     QUICKSORT DOES NOT WORK YET

	//find matches and return index
	for (int candidateIndex = 0; candidateIndex < candidateStrings.size(); candidateIndex++)
	{
		location = SearchSort::binarySearch(wordList.getWords(), candidateStrings[candidateIndex]);
		if (location != -1) matchList.push_back(candidateStrings[candidateIndex]); //If word is present in dictionary, add to list of found words
	}

	return matchList;
}

void main()
{

	wordList words = wordList("wordlist.txt");
	grid gridList("input15");

	findMatches(words, gridList); //calls getCandidateString()

	system("pause");
}


