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

class Grid
{
private:
	int rows;
	int columns;
	matrix<char> matrix;

public:
	Grid();
	Grid(string fileName);
	~Grid();

	int getRows() const;
	int getColumns() const;

	char getChar(int i, int j) const;

	friend ostream &operator<<(ostream &ostream, const Grid grid);
};
