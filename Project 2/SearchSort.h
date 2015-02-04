/*
SearchSort.h
contains template functions for searching and sorting

Fouad Al-Rijleh, Rachel Rudolph
*/
#pragma once

#include <vector>

using namespace std;

//quickSort
template<typename T> void quickSort(vector<T> vector, int left, int right);
template<typename T> int partition(vector<T> vector, int left, int right);
template<typename T> void swap(T a, T b);