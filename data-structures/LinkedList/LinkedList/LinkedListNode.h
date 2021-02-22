#pragma once
#ifndef LinkedListNODE_H
#define LinkedListNODE_H

#include <iostream>
#include <cstddef>

using namespace std;
template <class T>
class LinkedListNode
{
public:
	T self;
	LinkedListNode* next;
	LinkedListNode();
	LinkedListNode(T val, LinkedListNode* next);

};

template <class T>
LinkedListNode<T>::LinkedListNode()
{
	self = nullptr;
	next = nullptr;
}

template <class T>
LinkedListNode<T>::LinkedListNode(T val, LinkedListNode* next)
{
	this->self = val;
	this->next = next;
}
/*
template <class T>
LinkedListNode<T>& LinkedListNode<T>::operator=(LinkedListNode* right)
{
	this->self = right->self;
	this->next = right->next;
	return *this;
}
*/
#endif
