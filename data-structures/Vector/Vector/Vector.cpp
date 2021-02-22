// Vector.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "myVector.h"
using namespace std;

int main()
{

    setlocale(LC_ALL, "russian");

	myVector<int> *q = new myVector<int>;
	q->push_back(12);
	q->push_back(24);
	q->push_back(34);
	q->push_back(225);
	q->insert(1111, 2);
	q->insert(9999, 0);
	q->insert(2123129, 0);
	q->push_back(10101010);

	
	q->print();

	cout << q->find(1111) << endl;

}

