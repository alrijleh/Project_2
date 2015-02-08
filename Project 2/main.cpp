#include "main.h"

vector<string> getCandidateString(grid g)
{
	vector<string> gridList;
	string word;

	for (int i = 0; i < g.getRows(); i++)
	{
		for (int j = 0; j < g.getColumns(); j++)
		{
			int j1 = j, i1 = i;
			word = g.getChar(i, j);

			//Case 1: Right
			for (int a = 0; a < g.getColumns(); a++)
			{
				if (a >= 5)
					gridList.push_back(word);

				j1 = j++;
				if (j1 == g.getColumns() - 1)
					j = 0;
				word += g.getChar(i, j);
			}

					//Case 2: Left
					word = g.getChar(i, j);
					for (int a = 0; a < g.getColumns(); a++)
					{
						if (a >= 5)
							gridList.push_back(word);

						j1 = j--;
						if (j1 == 0)
							j = g.getColumns() - 1;
						word += g.getChar(i, j);
						//break;
					}

					//Case 3: Down
					word = g.getChar(i, j);
					for (int a = 0; a < g.getRows(); a++)
					{
						if (a >= 5)
							gridList.push_back(word);

						i1 = i++;
						if (i1 == g.getRows() - 1)
							i = 0;
						word += g.getChar(i, j);
						//break;
					}

					//Case 4: Up
					word = g.getChar(i, j);
					for (int a = 0; a < g.getRows(); a++)
					{
						if (a >= 5)
							gridList.push_back(word);

						i1 = i--;
						if (i1 == 0)
							i = g.getRows() - 1;
						word += g.getChar(i, j);
					}

					//Case 5: Down Right
					word = g.getChar(i, j);
					for (int a = 0; a < g.getColumns(); a++)
					{
						if (a >= 5)
							gridList.push_back(word);

						i1 = i++;
						if (i1 == g.getRows() - 1)
							i = 0;
						j1 = j++;
						if (j1 == g.getColumns() - 1)
							j = 0;
						word += g.getChar(i, j);
						//break;
					}

					//Case 6: Down Left
					word = g.getChar(i, j);
					for (int a = 0; a < g.getColumns(); a++)
					{
						if (a >= 5)
							gridList.push_back(word);

						i1 = i++;
						if (i1 == g.getRows() - 1)
							i = 0;
						j1 = j--;
						if (j1 == 0)
							j = g.getColumns() - 1;
						word += g.getChar(i, j);
					}

					//Case 7: Up Right
					word = g.getChar(i, j);
					for (int a = 0; a < g.getColumns(); a++)
					{
						if (a >= 5)
							gridList.push_back(word);

						i1 = i--;
						if (i1 == 0)
							i = g.getRows() - 1;
						j1 = j++;
						if (j1 == g.getColumns() - 1)
							j = 0;
						word += g.getChar(i, j);
					}

					//Case 8: Up Left
					word = g.getChar(i, j);
					for (int a = 0; a < g.getColumns(); a++)
					{
						if (a >= 5)
							gridList.push_back(word);

						i1 = i--;
						if (i1 == 0)
							i = g.getRows() - 1;
						j1 = j--;
						if (j1 == 0)
							j = g.getColumns() - 1;
						word += g.getChar(i, j);
					}
		}
	}

	return gridList;
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
			for (int j = 0; j < gridList.size(); j++)
			{
				string gridWord = gridList[j];
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
	getCandidateString(gridList);

	system("pause");
}


