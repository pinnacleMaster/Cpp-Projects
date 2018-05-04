/*
 * CLL.hpp
 *
 *  Created on: May 3, 2018
 *      Author: takudzwamhonde
 */

#ifndef CLL_HPP_
#define CLL_HPP_


template<typename T>
class CLL{ // a circularly linked list
public:
	struct CNode{
		T elem;
		CNode* next;
		CNode(): elem(), next(nullptr) {}
	};
private:
	typedef CNode* CNodePtr;
public:
	CLL(); 					// constructor
	~CLL(); 					// destructor
	bool empty();			// checks if cll is empty
	const T& front() const;  // returns element in front of cursor
	const T& back() const;	// returns element at rear of cursor
	void advance();			// advance the cursor to the element in front
	void add(const T& e); 	// add element at the front of the cursor
	void remove();			// removes element at the front of the cursor
private:
	CNodePtr cursor;
};

template <typename T>
CLL<T>:: CLL(): cursor(nullptr) {}

template <typename T>
CLL<T>:: ~CLL() { while(!empty()) remove();}

template <typename T>
bool CLL<T>:: empty() { return cursor==nullptr; }

template <typename T>
const T& CLL<T>::front() const { return cursor->next->elem; }

template <typename T>
const T& CLL<T>::back() const { return cursor->elem; }

template <typename T>
void CLL<T>::advance() { cursor = cursor->next; }

template <typename T>
void CLL<T>:: add(const T& e){
	CNodePtr v = new CNode;
	v->elem = e;
	if(empty())
	{
		v->next = v;
		cursor = v;
	}
	else
	{
		v->next = cursor->next;
		cursor->next = v;
	}
}

template <typename T>
void CLL<T>:: remove(){

	CNodePtr oldCursor = cursor->next;
	if(oldCursor == cursor)
		cursor = nullptr;
	else
		cursor->next = oldCursor->next;
	delete oldCursor;
}

#endif /* CLL_HPP_ */
