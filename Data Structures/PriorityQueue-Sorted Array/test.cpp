/*
 * main.cpp
 *
 *  Created on: Mar 23, 2018
 *      Author: takudzwamhonde
 */
#include <iostream> // cout, endl
#include <stdlib.h> // EXIT_SUCCESS
#include "PriorityQueue.hpp"

using std::cout; using std::endl;

PriorityQueue PQ;

void printPQ(PriorityQueue _PQ){
	if(_PQ.empty())
		cout << "empty priority queue" <<endl;
	PriorityQueue::Pair entry;
	while(_PQ.size()!=0){
		entry = _PQ.min();
		cout << "(" << entry.getKey() << ", " << entry.getValue() << ")" << " ";
		_PQ.removeMin();
	}
	cout << endl;
}

void insert (const int& key,const char& value ) {
	PriorityQueue::Pair p(key,value);
	PQ.insert(p);
}

void test(){
	PQ.removeMin();
	cout << "size: " << PQ.size() << endl;

	printPQ(PQ); cout << endl;

	insert(5,'a');
	printPQ(PQ); cout << endl;

	insert(4,'b');
	printPQ(PQ); cout << endl;

	insert(7,'i');
	printPQ(PQ); cout << endl;

	insert(1,'d');
	printPQ(PQ); cout << endl;

	PQ.removeMin();

	insert(3,'j');
	printPQ(PQ); cout << endl;

	insert(6,'c');
	printPQ(PQ); cout << endl;

	PQ.removeMin();
	printPQ(PQ); cout << endl;

	PQ.removeMin();
	printPQ(PQ); cout << endl;

	insert(8,'g');
	printPQ(PQ); cout << endl;

	PQ.removeMin();
	printPQ(PQ); cout << endl;

	insert(2,'h');
	printPQ(PQ); cout << endl;

	PQ.removeMin();
	printPQ(PQ); cout << endl;

	PQ.removeMin();
	printPQ(PQ); cout << endl;
}

int main()
{
	test();
	return EXIT_SUCCESS;
}