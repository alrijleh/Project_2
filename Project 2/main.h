/*
main.h
Holds global functions getCandidate String and findMatches, calls search to solve crossword.

Fouad Al-Rijleh, Rachel Rudolph
*/
#pragma once

#include "main.h"
#include "wordList.h"
#include "SearchSort.h"
#include "grid.h"
#include "Heap.h"
#include "Hashtable.h"

#include <iostream>
#include <time.h>

using namespace std;

enum Sort { INSERTIONSORT, MERGESORT, QUICKSORT, HEAPSORT, HASH}; //enum for which sorting algorithm to use
