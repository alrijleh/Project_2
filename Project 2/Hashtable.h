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
	Hashtable();
	Hashtable(vector<vector<T>> newtable);
	~Hashtable();

	void setTable(vector<vector<T>> newtable)
	{
		table = newTable;
	}

	vector<vector<T>> getTable() const
	{
		table = newtable;
	}

	void addItem(T item) const
	{
		int slot;
		slot = hash(item);
		table[slot].push_back(item)
	}

	void deleteItem(T item) const
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

	int hash(T item)
	{
		std::hash<T> hash_struct;
		return hash_struct(item) % table.size();
	}
};


