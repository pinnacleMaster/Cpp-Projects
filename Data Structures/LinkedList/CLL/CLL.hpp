#ifndef CLL_HPP
#define CLL_HPP

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
	const T& front();
	const T& back();
	void advance();
	void add(const T& e);
	void remove();
private:
	CNodePtr cursor;
};

template <typename T>
CLL<T>:: CLL(): cursor(nullptr) {}

template <typename T>
CLL<T>:: ~CLL(): { while(!empty()) remove();}

template <typename T>
bool CLL<T>:: empty() { return cursor==nullptr; }

template <typename T>
const T& CLL<T>:: front() { return cursor->next->elem; }

template <typename T>
const T& CLL<T>:: back() { return cursor->elem; }

template <typename T>
void CLL<T> advance() { cursor = cursor->next; }

template <typename T> 
void CLL<T>:: add(const T& e){
	CNodePtr v = new CNode;
	v->elem = e;
	if(empty)
		cursor->next = v; // want to see how this turns out
	else
		cursor->next->next = v; // want to see how this turns out
}

template <typename T> 
void CLL<T>:: remove(){

	CNodePtr oldCursor = cursor->next;
	if(oldCursor == cursor)
		cursor = nullptr;
	else 
		cursor->next = old->next;
	delete old;
}

#endif /* CLL_HPP */