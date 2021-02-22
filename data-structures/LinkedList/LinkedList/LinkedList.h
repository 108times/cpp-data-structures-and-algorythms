#pragma once
#ifndef LinkedList_H
#define LinkedList_H

#include "LinkedListNode.h"
#include <iostream>
#include <random>
using namespace std;

template <class T>
class LinkedList
{
	LinkedListNode<T>* head;
	LinkedListNode<T>* tail;
public:
	LinkedList();
	LinkedList(int size);
	void push_back(T val);
	void pop();
	void fill_with_random_integers(int amount);
	int get_random_int(int range);
	void print();
	LinkedListNode<T>* get(int index);
	void sort();
	LinkedListNode<T>* swap(LinkedListNode<T>* el1, LinkedListNode<T>* el2);
	int get_count();
	T operator[](int index);

};

template <class T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
	tail = nullptr;
}

template <class T>
LinkedList<T>::LinkedList(int size)
{
	fill_with_random_integers(size);
}

template <class T>
void LinkedList<T>::push_back(T val)
{
	LinkedListNode<T>* newListItem = new LinkedListNode<T>(val, nullptr);
	tail->next = newListItem;
	tail = newListItem;
}

template <class T>
void LinkedList<T>::pop()
{
	LinkedListNode<T>* n = head;
	
	while (n != nullptr)
	{
		
		if (n->next->next == nullptr)
		{
			tail = n;
			tail->next = nullptr;
			break;
		} 
		
		n = n->next;
	}

}

template <class T>
void LinkedList<T>::fill_with_random_integers(int amount)
{
	head = new LinkedListNode<T>(get_random_int(100), nullptr);
	tail = new LinkedListNode<T>(get_random_int(100), nullptr);
	
	LinkedListNode<T>* postition_holder = head;
	
	for ( int i = 0; i < amount-1; i++)
	{
		LinkedListNode<T>* item = new LinkedListNode<T>(get_random_int(100), nullptr);
		postition_holder->next = item;
		postition_holder = item;
	}

	postition_holder->next = tail;
	
}

template <class T>
int LinkedList<T>::get_random_int(int range)
{
	return (rand() % range);
}

template <class T>
void LinkedList<T>::print()
{
	LinkedListNode<T>* n = head;
	int i = 1;

	cout << "head -> " << head->self <<" , next -> "<< head->next <<endl;
	cout << "tail ->" << tail->self << " , next -> " << tail->next << endl <<endl;
	while(n != nullptr)
	{
		if (n->next == nullptr)
		{
			cout << "#" << i << " self -> " << n->self << " , next -> NULL" << endl;
			n = nullptr;
		} else
		{
			cout << "#" << i << " self -> " << n->self << " , next -> " << n->next->self << endl;
			n = n->next;
			i++;
		}
		
	}
	cout << endl;
}

template <class T>
LinkedListNode<T>* LinkedList<T>::get(int index)
{
	LinkedListNode<T>* n = head;
	int position = 0;
	while (n->next != nullptr)
	{
		if (index == position)
		{
			return n;
		}
		n = n->next;

		position++;
	}
}

template <class T>
void LinkedList<T>::sort()
{
	
	
	bool swapped = true;
	
		while(swapped)
		{
			swapped = false;
			
			LinkedListNode<T>* n = head;
			
			while (n!=nullptr && n->next != nullptr )
			{
				
				if ( n->self > n->next->self )
				{
					this->swap(  n, n->next);
					swapped = true;
				}
				
				n = n->next;

				
			}

		}
		
}

template <class T>
LinkedListNode<T>* LinkedList<T>::swap(LinkedListNode<T>* el1, LinkedListNode<T>* el2)
{
	T tmp = el1->self;
	el1->self = el2->self;
	el2->self = tmp;
	return el2;
}

template <class T>
int LinkedList<T>::get_count()
{
	LinkedListNode<T>* n = head;
	int count = 1;
	while( n->next != nullptr)
	{

		n = n->next;
		count++;
	}
	return count;
}

template <class T>
T LinkedList<T>::operator[](int index)
{
	int size = get_count();

	if (index > size )
	{
		cout << "¬веденный индекс находитс€ за пределами списка!" << endl;
	} else
	{
		LinkedListNode<T>* res = get(index);
		return res->self;
	}

}

/*
template <class T>
ostream& LinkedList<T>::operator<<(ostream& os, LinkedListNode<T>* node)
{
	os << node.self << endl;
	return os;
}
*/

#endif
