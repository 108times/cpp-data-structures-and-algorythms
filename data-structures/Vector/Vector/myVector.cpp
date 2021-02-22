#include "myVector.h"

/***
 *	vector Class implementation
 */
template <typename Type>
myVector<Type>::myVector()
{
	v_container = nullptr;
	capacity(0);
	size(0);
}

template <typename Type>
myVector<Type>::~myVector()
{
	if (v_container != nullptr)
	{
		delete[] v_container;
	}
}

template <typename Type>
myVector<Type>::myVector(int index)
{
	v_capacity = index;
	v_size = 0;;
	v_container = new int[v_capacity];
}

template <typename Type>
void myVector<Type>::push_back(const Type& element)
{
	// if empty -> create new[6]
	if (v_capacity == 0 && v_size == 0)
	{
		capacity(6);
		v_container = new Type(v_capacity);
	}
	// if size is equal or bigger than capacity
	// multiplies capacity by 2 and copies values from old
	// v_container, then adds new value at the end
	else if (v_size >= v_capacity)
	{

		v_capacity*=2;
		int* new_arr = new int[v_size];
		for (int i = 0; i < v_size; i++)
		{
			new_arr[i] = v_container[i];
		}
	
	delete[] v_container;
	v_container = new_arr;
	}
	v_container[v_size++] = element; //adds element & increment pointer
}

template <typename Type>
void myVector<Type>::insert(const Type& element, int index)
{
	if ((v_size > 0) && ( index <= v_capacity) )
	{
		if (v_size >= v_capacity)
		{
			v_capacity *= 2;
		}

	int* new_arr = new int[v_size];
	int continue_from = 0;
	for (int i=0; i< v_size; i++)
	{
		if (i==index)
		{
			new_arr[i] = element;
			continue_from = i + 1;
			break;
			
		}

	new_arr[i] = v_container[i];
	
	}
	
	if (continue_from != 0)
	{
		for (int j = continue_from; j < v_size; j++)
		{
			new_arr[j] = v_container[j - 1];
		}
	}

	delete[] v_container;
	v_container = new_arr;
		
	}
}

template <typename Type>
int myVector<Type>::find(const Type& element)
{
	for(int i=0; i< v_size; i++)
	{
		if (v_container[i] == element)
		{
			return i;
		}
	}
	return -1;
}

template <typename Type>
void myVector<Type>::remove(int index)
{
	for (int i = index;i<v_size;i++)
	{
		v_container[i] = v_container[i + 1];
	}
	--v_size;
}

template <typename Type>
Type& myVector<Type>::get(int index)
{
		return v_container[index];
}
template <typename Type>
void myVector<Type>::pop_back()
{
	--v_size;

}

template <typename Type>
int myVector<Type>::size()
{
	return v_size;
}

template <typename Type>
void myVector<Type>::size(int new_size)
{
	v_size = new_size;
}

template <typename Type>
int myVector<Type>::capacity()
{
	return v_capacity;
}

template <typename Type>
void myVector<Type>::capacity(int new_capacity)
{
	v_capacity = new_capacity;
}

template <typename Type>
void myVector<Type>::print()
{
	cout << "Printing..." << endl;
	for (int i=0; i< v_size; i++)
	{
		cout << i << " -> " << v_container[i] << endl;
	}
	cout << "Finished printing!" << endl<<endl;
}

template <typename Type>
Type& myVector<Type>::operator[](int index)
{
	return v_container[index];
}

template <typename Type>
myVector<Type>& myVector<Type>::operator=(myVector* object)
{
	v_container = new myVector(object->v_capacity);
	capacity(object->v_capacity);
	size(object->v_size);
	for (int i=0; i<v_size; i++)
	{
		v_container[i] = object->v_container[i];
	}
	return *this;
}



