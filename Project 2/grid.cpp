/*
grid.h
Stores function that reads letters and grid size from file.

Fouad Al-Rijleh, Rachel Rudolph
*/

#include "grid.h"


Grid::Grid(){}

Grid::~Grid(){}

Grid::Grid(string fileName)
{
	//Read the Grid file
	ifstream fin;
	fin.open(fileName.c_str());

	if (!fin)
	{
		throw fileOpenError(fileName);
	}

	// Read in the first two numbers of file and use for Grid size
	fin >> rows >> columns;
	matrix.resize(rows, columns);

	while (!fin.eof())
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				fin >> matrix[i][j];
			}
		}
	}
	fin.close();
}

int Grid::getRows() const
{
	return rows;
}

int Grid::getColumns() const
{
	return columns;
}

//Get the character in the matrix
char Grid::getChar(int i, int j) const
{
	char c = matrix[i][j];
	return c;
}

//Operator overloads
ostream &operator<<(ostream &ostream, Grid grid)
{
	for (int i = 0; i < grid.rows; i++)
	{
		for (int j = 0; j < grid.columns; j++)
		{
			cout << grid.matrix[i][j] << " ";
		}
		cout << endl;
	}
	return ostream;
}
