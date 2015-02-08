#include "main.h"
using namespace std;

void main()
{
	vector<int> myVec(15);
	for (int i = 0; i < myVec.size(); i++)
	{
		myVec[i] = rand() % 50;
	}
	cout << myVec << endl;
	quickSort(myVec);
	cout << myVec << endl;
	system("pause");
}