#pragma 

#include "SearchSort.h"
#include "d_except.h"
#include <iostream>
#include <vector>

using namespace std;
template<typename T>
class Hashtable
{
private:
	vector<vector<T>> table;

public:
	Hashtable(){}
	Hashtable(vector<T> baseVector)
	{
		Hashtable(baseVector, baseVector.size());
	}
	Hashtable(vector<T> baseVector, int numSlots)
	{
		vector<vector<T>> table(numSlots);
		for (int index = 0; index < baseVector.size(); index++)
		{
			addItem(baseVector[index]);
		}
	}

	~Hashtable(){}

	void setTable(vector<vector<T>> newtable)
	{
		table = newTable;
	}

	vector<vector<T>> getTable() const
	{
		return table;
	}

	int getSlotCount() const
	{
		return table.size();
	}

	vector<int> getSlotSizes() const
	{
		vector<int> sizeVector(table.size())
			for (int index = 0; index < table.size(); index++)
			{
				sizeVector[index] = table[index].size();
			}
		return sizeVector;
	}

	void addItem(T item)
	{
		int slot;
		slot = hash(item);
		table[slot].push_back(item);
	}

	void deleteItem(T item)
	{
		int slot, location;
		slot = hash(item);
		location = SearchSort::linearSearch(table[slot], item);
		if (location == -1) throw referenceError("item not found in hash table");
		else table[slot].erase(table[slot].begin() + location);
	}

	bool inList(T item) const
	{
		int slot, location;
		slot = hash(item);
		location = SearchSort::linearSearch(table[slot], item);
		if (location == -1) return false;
		else return true;
	}

	int hash(T item) const
	{
		std::hash<T> hash_struct;
		return hash_struct(item) % table.size();
	}
};