#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "QueueExceptions.hpp"
#include "CLL.hpp"
template<typename T>
class Queue{
public:
  Queue();                                     // constructor
  int size() const;                            // returns size of queue
  bool empty() const;                          // returns true if empty; otherwise false
  const T& front() const throw(QueueEmpty);    // returns the element at the front of the queue
  void enqueue(const T& e);                    // adds an element to the back of the queue
  void dequeue()  throw(QueueEmpty);           // removes element at the front of the queue
private:
  CLL<T> data;
  int n;
};

template<typename T>
Queue<T>::Queue() : data(), n(0) {}

template<typename T>
int Queue<T>::size() const { return n; }

template<typename T>
bool Queue<T>::empty() const { return n == 0; }

template<typename T>
const T& Queue<T>::front() const throw(QueueEmpty)
{
  if(empty())
    throw QueueEmpty("No element at the front of the queue. Cannot retrieve.");
  return data.front();
}


template<typename T>
void Queue<T>::enqueue(const T& e)
{
  data.add(e); data.advance(); n++;
}


template<typename T>
void Queue<T>::dequeue() throw(QueueEmpty)
{
  if(empty())
    throw QueueEmpty("No element at the front of the queue. Cannot remove.");
  data.remove(); n--;
}

#endif /* QUEUE_HPP */
