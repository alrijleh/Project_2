#pragma 

#include <iostream>
#include <vector>

using namespace std;
template<typename T>
class Hashtable
{
private: 
	vector<vector<T>> vector; 

public:
	Hashtable();
	Hashtable(vector<vector<T>> vector);
	~Hashtable();

	void setVector(vector<vector<T>> newVector)
	{
		vector = newVector;
	}

	vector<vector<T>> getVector() const
	{
		vector = newVector;
	}

	int addItem(int i) const
	{
		
	}

	int deleteItem(int i) const
	{
		
	}

	int inList(int i) const
	{

	}

	void hash()
	{

	}
};


