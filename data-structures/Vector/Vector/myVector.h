#pragma once
#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>

/***
 *	vector Class header
 */

using namespace std;

template <typename Type>
class myVector
{
	

	Type v_size;
	int v_capacity;
	int* v_container;
	
public:
	myVector();
	~myVector();
	myVector(int index);
	
	// Inserts element at the end. O(1)
	void push_back(const Type& element);

	// Inserts element at index. O(1)
	void insert(const Type& element, int index);

	int find(const Type& element);

	void remove(int index);

	// Gets element at specific index. O(1)
	Type& get(int index);

	// Deletes the last element . O(1)
	void pop_back();

	// Returns the size (numbers of elements of the vector). O(1)
	int size() ;

	void size(int new_size);

	// Returns the capacity of the vector. O(1)
	int capacity();

	void capacity(int new_capacity);

	// Print array elements. O(N)
	void print();

	Type& operator[](int index);

	myVector& operator=(myVector* object);
};

#endif