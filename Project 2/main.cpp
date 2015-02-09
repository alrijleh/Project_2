#include "main.h"

vector<string> getCandidateString(grid grid)
{
	vector<string> wordList;
	string word;
	int wrapColumn;
	int wrapRow;

	for (int baseRow = 0; baseRow < 4; baseRow++)
	{
		for (int baseColumn = 0; baseColumn < 4; baseColumn++)
		{

			////Case 1: Right
			//wrapColumn = 0;
			//word.clear();
			//for (int charOffset = 0; charOffset < grid.getColumns(); charOffset++) 
			//{
			//	if (baseColumn + charOffset > grid.getColumns() - 1) //If it wraps right
			//	{
			//		word += grid.getChar(baseRow, wrapColumn);
			//		wrapColumn++;
			//	}
			//	else //Does not wrap
			//	{
			//		word += grid.getChar(baseRow, baseColumn + charOffset);
			//	}
			//	if (charOffset >= 4) //Keeps greater than or equal to 5 characters
			//		wordList.push_back(word); //Puts new word into wordList vector
			//}

			////Case 2: Left
			//wrapColumn = grid.getColumns() - 1;
			//word.clear();
			//for (int charOffset = 0; charOffset < grid.getColumns(); charOffset++)
			//{
			//	if (baseColumn - charOffset < 0) //If it wraps
			//	{
			//		word += grid.getChar(baseRow, wrapColumn);
			//		wrapColumn--;
			//	}
			//	else //Does not wrap
			//	{
			//		word += grid.getChar(baseRow, baseColumn - charOffset);
			//	}
			//	if (charOffset >= 4) //Keeps greater than or equal to 5 characters
			//		wordList.push_back(word); //Puts new word into wordList vector
			//}

			////Case 3: Down
			//wrapRow = 0;
			//word.clear();
			//for (int charOffset = 0; charOffset < grid.getRows(); charOffset++) 
			//{
			//	if (baseRow + charOffset > grid.getRows() - 1) //If it wraps
			//	{
			//		word += grid.getChar(wrapRow, baseColumn);
			//		wrapRow++;
			//	}
			//	else //Does not wrap
			//	{
			//		word += grid.getChar(baseRow + charOffset, baseColumn);
			//	}
			//	if (charOffset >= 4) //Keeps greater than or equal to 5 characters
			//		wordList.push_back(word); //Puts new word into wordList vector
			//}
			
			////Case 4: Up
			//wrapRow = grid.getRows() - 1;
			//word.clear();
			//for (int charOffset = 0; charOffset < grid.getRows(); charOffset++)
			//{
			//	if (baseRow - charOffset < 0) //If it wraps
			//	{
			//		word += grid.getChar(wrapRow, baseColumn);
			//		wrapRow--;
			//	}
			//	else //Does not wrap
			//	{
			//		word += grid.getChar(baseRow - charOffset, baseColumn);
			//	}
			//	if (charOffset >= 14) //Keeps greater than or equal to 5 characters
			//		wordList.push_back(word); //Puts new word into wordList vector
			//}


			//Case 4: Down-Right
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
				else if (!(baseColumn + charOffset >= grid.getColumns() ) && !(baseRow + charOffset >= grid.getRows() ))
				{
					word += grid.getChar(baseRow + charOffset, baseColumn + charOffset);
				}
				if (charOffset >= 14) //Keeps greater than or equal to 5 characters
					wordList.push_back(word); //Puts new word into wordList vector
			}


			////Case 2: Left
			//word = grid.getChar(row, column);
			//for (int charOffset = 0; charOffset < grid.getColumns(); a++)
			//{
			//	if (a >= 5)
			//		wordList.push_back(word);

			//	baseColumn = column--;
			//	if (baseColumn == 0)
			//		column = grid.getColumns() - 1;
			//	word += grid.getChar(row, column);
			//	//break;
			//}

			////Case 3: Down
			//word = grid.getChar(row, column);
			//for (int a = 0; a < grid.getRows(); a++)
			//{
			//	if (a >= 5)
			//		wordList.push_back(word);

			//	baseRow = row++;
			//	if (baseRow == grid.getRows() - 1)
			//		row = 0;
			//	word += grid.getChar(row, column);
			//	//break;
			//}

			////Case 4: Up
			//word = grid.getChar(row, column);
			//for (int a = 0; a < grid.getRows(); a++)
			//{
			//	if (a >= 5)
			//		wordList.push_back(word);

			//	baseRow = row--;
			//	if (baseRow == 0)
			//		row = grid.getRows() - 1;
			//	word += grid.getChar(row, column);
			//}

			////Case 5: Down Right
			//word = grid.getChar(row, column);
			//for (int a = 0; a < grid.getColumns(); a++)
			//{
			//	if (a >= 5)
			//		wordList.push_back(word);

			//	baseRow = row++;
			//	if (baseRow == grid.getRows() - 1)
			//		row = 0;
			//	baseColumn = column++;
			//	if (baseColumn == grid.getColumns() - 1)
			//		column = 0;
			//	word += grid.getChar(row, column);
			//	//break;
			//}

			////Case 6: Down Left
			//word = grid.getChar(row, column);
			//for (int a = 0; a < grid.getColumns(); a++)
			//{
			//	if (a >= 5)
			//		wordList.push_back(word);

			//	baseRow = row++;
			//	if (baseRow == grid.getRows() - 1)
			//		row = 0;
			//	baseColumn = column--;
			//	if (baseColumn == 0)
			//		column = grid.getColumns() - 1;
			//	word += grid.getChar(row, column);
			//}

			////Case 7: Up Right
			//word = grid.getChar(row, column);
			//for (int a = 0; a < grid.getColumns(); a++)
			//{
			//	if (a >= 5)
			//		wordList.push_back(word);

			//	baseRow = row--;
			//	if (baseRow == 0)
			//		row = grid.getRows() - 1;
			//	baseColumn = column++;
			//	if (baseColumn == grid.getColumns() - 1)
			//		column = 0;
			//	word += grid.getChar(row, column);
			//}

			////Case 8: Up Left
			//word = grid.getChar(row, column);
			//for (int a = 0; a < grid.getColumns(); a++)
			//{
			//	if (a >= 5)
			//		wordList.push_back(word);

			//	baseRow = row--;
			//	if (baseRow == 0)
			//		row = grid.getRows() - 1;
			//	baseColumn = column--;
			//	if (baseColumn == 0)
			//		column = grid.getColumns() - 1;
			//	word += grid.getChar(row, column);
			//}
		}
	}

	return wordList;
}

vector<string> findMatches(wordList wordList, grid grid)
{
	vector<string> gridList = getCandidateString(grid);
	vector<string> match;

	//Go through each word in wordList
	for (int i = 0; i < wordList.getWords().size(); i++)
	{
		string dictWord = wordList.getWords()[i];
		if (dictWord.length() > 4)
		{
			//Compare dictionary word to grid word
			for (int column = 0; column < gridList.size(); column++)
			{
				string gridWord = gridList[column];
				if (gridWord.compare(dictWord) == 0)
				{
					//If same word put in match
					match.push_back(gridWord);
					break;
				}
			}
		}
	}

	return match;
}

void main()
{
	wordList words = wordList("wordlist.txt");

	grid gridList("input15");
	//getCandidateString(gridList);
	//findMatches(words, gridList);

	cout << getCandidateString(gridList);

	system("pause");
}


