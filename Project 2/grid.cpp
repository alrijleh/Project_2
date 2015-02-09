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
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	fin.close();
}

int Grid::getRows()
{
	return rows;
}

int Grid::getColumns()
{
	return columns;
}

//Get the character in the matrix
char Grid::getChar(int i, int j)
{
	char c = matrix[i][j];
	return c;
}

