#pragma once

#include "main.h"
#include "wordList.h"
#include "SearchSort.h"
#include "grid.h"

#include <iostream>



using namespace std;


//vector<string> findMatches(wordList words, grid grid)
//{
//	vector<string> gridList = getCandidateString(g);
//	vector<string> match;
//
//	//Go through each word in wordList
//	for (int i = 0; i < words.size(); i++)
//	{
//		string dictWord = words.words[i];
//		if (dictWord.length() > 4)
//		{
//			//Compare dictionary word to grid word
//			for (int j = 0; j < gridList.size(); j++)
//			{
//				string gridWord = gridList[j];
//				if (gridWord.compare(dictWord) == 0)
//				{
//					//If same word put in match
//					match.push_back(gridWord);
//					break;
//				}
//			}
//		}
//	}
//
//	return match;
//}
