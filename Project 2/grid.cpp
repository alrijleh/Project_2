#include "grid.h"


grid::grid()
{
}


grid::~grid()
{
}


grid::grid(string fileName)
{
	//Read the grid file
	ifstream fin;
	fin.open(fileName.c_str());
	if (!fin)
		cout << "Could not read grid file." << endl;

	// Read in the first to numbers of file and use for grid size
	fin >> rows >> columns;
	matrix.resize(rows, columns);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			fin >> matrix[i][j];
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	fin.close();
}

int grid::getRows()
{
	return rows;
}

int grid::getColumns()
{
	return columns;
}
