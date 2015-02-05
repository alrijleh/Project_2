/*
wordList.h

Fouad Al-Rijleh, Rachel Rudolph
*/
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "d_matrix.h"
#include "d_except.h"

using namespace std;

class grid
{
private:
	int rows;
	int columns;
	matrix<char> matrix;

public:
	grid();
	~grid();

	grid(string fileName);
	int getRows();
	int getColumns();

	char getChar(int i, int j);
};
