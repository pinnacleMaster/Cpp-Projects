#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP
#include <iostream> // debugging
using namespace std;// debugging

const int MAX_SIZE = 100; // max size of array

class PriorityQueue {
	public:
		class Pair {

		public:
			Pair() {}
			Pair(const int& _key, const char& _value) : key(_key), value(_value) {}
			char getValue() const { return value; }
			int getKey() const { return key; }

		private:
			int key; char value;
		};
	public:
		PriorityQueue();
		// PrioriyQueue(const Pair& p);

		void insert(const Pair& p); // inserts p at the right position in PQ
		void removeMin(); // removes the element at the front of the queue
		Pair min() const; // returns the element at the front of the queue
		int size() const; // returns the size of the queue
		bool empty() const; // returns true if size = 0; otherwise false

	private:
		Pair data[MAX_SIZE];
		int  endPos; // keeps track of where the PQ starts and ends, resp.
};

// class implementation

PriorityQueue::PriorityQueue() { endPos = -1; }

void PriorityQueue::insert(const Pair& p)
{
	if (endPos == MAX_SIZE-1) // a full PQ, exception should be thrown here
		return;
	// an empty PQ 
	endPos++;

	if(endPos == 0) data[0] = p;
	else // non empty PQ
	{
		int k = p.getKey();
		for(int i=0;i<endPos+1;i++){
			if(k <= data[i].getKey())
			{
				// found pos to be i
				// push other elements to the right by 1
				for(int j=endPos; j>i;j--)
					data[j] = data[j-1];
				// now place entry in pos
				data[i] = p;
				return;
			}
		}
	}
	// the entry key is larger than all keys in PQ, so
	data[endPos] = p;
}

void PriorityQueue::removeMin() 
{
	// adjust array to accomodate the next possible insertion
	if(endPos+1 == 0)
		return; // throw exception here - trying to remove min from empty PQ

	for(int i=1;i<endPos+1;i++)
	{
		data[i-1] = data[i];
	}
	endPos--; //shift pos down by 1
}

PriorityQueue::Pair PriorityQueue::min() const { return data[0]; }

int PriorityQueue::size() const { return endPos+1; }

bool PriorityQueue::empty () const { return endPos+1 == 0; }

#endif
