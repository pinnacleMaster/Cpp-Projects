/*
 * CLL.hpp
 *
 *  Created on: May 3, 2018
 *      Author: takudzwamhonde
 */

#ifndef CLL_HPP_
#define CLL_HPP_

template<typename T>
class CLL{
public:
	struct CNode{
		T elem;
		CNode* next;
		CNode(): elem(), next(nullptr) {}
	};
private:
	typedef CNode* CNodePtr;
public:
	CLL(); // constructor
	~CLL(); // destructr
	bool empty();
	const T& front() const;
	const T& back() const;
	void advance();
	void add(const T& e);
	void remove();
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
