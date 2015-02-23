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
	Hashtable(vector<T> baseVector);
	Hashtable(vector<T> baseVector, int numSlots);
	~Hashtable(){}

	void setTable(vector<vector<T>> newtable);
	vector<vector<T>> getTable() const;

	int getSlotCount() const;
	vector<int> getSlotSizes() const;

	void addItem(T item);
	void deleteItem(T item);
	bool inList(T item) const;
	int hash(T item) const;
};

////////////////////////////////////////////////////////////////////////////////
template<typename T>
Hashtable::Hashtable(vector<T> baseVector)
{
	Hashtable(baseVector, baseVector.size());
}

template<typename T>
Hashtable::Hashtable(vector<T> baseVector, int numSlots)
{
	vector<vector<T>> table(numSlots);
	for (int index = 0; index < baseVector.size(); index++)
	{
		addItem(baseVector[index]);
	}
}

template<typename T>
void Hashtable::setTable(vector<vector<T>> newtable)
{
	table = newTable;
}

template <typename T>
vector<vector<T>> Hashtable::getTable() const
{
	return table;
}

template <typename T>
int Hashtable::getSlotCount() const
{
	return table.size();
}

template <typename T>
vector<int> getSlotSizes() const
{
	vector<int> Hashtable::sizeVector(table.size())
		for (int index = 0; index < table.size(); index++)
		{
			sizeVector[index] = table[index].size();
		}
	return sizeVector;
}

template <typename T>
void Hashtable::addItem(T item)
{
	int slot;
	slot = hash(item);
	table[slot].push_back(item);
}

template <typename T>
void Hashtable::deleteItem(T item)
{
	int slot, location;
	slot = hash(item);
	location = SearchSort::linearSearch(table[slot], item);
	if (location == -1) throw referenceError("item not found in hash table");
	else table[slot].erase(table[slot].begin() + location);
}

template <typename T>
bool Hashtable::inList(T item) const
{
	int slot, location;
	slot = hash(item);
	location = SearchSort::linearSearch(table[slot], item);
	if (location == -1) return false;
	else return true;
}

template <typename T>
int Hashtable::hash(T item) const
{
	std::hash<T> hash_struct;
	return hash_struct(item) % table.size();
}