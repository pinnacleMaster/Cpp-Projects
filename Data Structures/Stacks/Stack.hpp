#ifndef STACK_HPP
#define	STACK_HPP

#include "SLL.hpp" // singly linked list
#include "exceptions.hpp"
// a Linked stack

template<typename T>
class LinkedStack{
public:
	Stack();
	int size() const;
	bool empty() const;
	const T& top() const throw(StackEmpty);
	void push(const T& d);
	void pop() throw(StackEmpty);
private:
	int n;
	SLL<T> data;

};

template<typename T>
Stack<T>::Stack(): n(0) {}

template<typename T>
int Stack<T>::size() const { return n;}

template<typename T>
bool Stack<T>::empty() const{ return n==0; }

template<typename T>
const T& Stack<T>::top() { 
	if (empty()) 
		throw StackEmpty("Top of empty stack");
	return S.front();		
}

template<typename T>
void Stack<T>::push(cons T& d){
	data.addFront(e);
	n++;
}

template<typename T>
void Stack<T>::pop() const throw(StackEmpty){
	if(empty())
		throw StackEmpty("Pop of empty stack");
	data.removeFront();
	n--;
}

#endif /* STACK_HPP */