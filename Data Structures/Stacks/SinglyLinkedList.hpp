#ifndef SLL_HPP
#define S::_HPP

#include <iostream>

template<typename T>
class SLL { //a singly linked list
private:
	struct Node{
		T elem;
		Node* next; // forward link
		Node(): next(nullptr), elem() {} // constructor
	};
private:
	typedef Node* Nodeptr;
public:
	SLL();
	~SLL();
	bool empty() const;
	T front() const;
	void addFront(const T& data);
	void removeFront();
private:
	Nodeptr head;
};

template<typename T>
int size(const SLL<T>& L);

int main(){
	SLL<int> L;
	//std::cout << "Size of L: " << size(L) << std::endl;
	L.addFront(6);
	//std::cout << "Size of L: " << size(L) << std::endl;
	L.addFront(6);
	L.addFront(5);
	L.addFront(3);
	return 0;
}

template<typename T>
SLL<T>::SLL(): head(nullptr) { }
template<typename T>
SLL<T>::~SLL() {
	Nodeptr prevHead;
	while(prevHead!=nullptr)
		removeFront();
}
template<typename T>
bool SLL<T>::empty() const{
	return head == nullptr;
}
template<typename T>
T SLL<T>::front() const
{
	return head->elem;
}
template<typename T>
void SLL<T>::addFront(const T& data){
	Nodeptr v = new Node;
	v->next = head; v->elem = data;
	head = v;
}
template<typename T>
void SLL<T>::removeFront()
{
	Nodeptr prevHead = head;
	head = prevHead->next;
	delete prevHead;
}

template<typename T>
int size(SLL<T>& L){
	int count = 0; while(!L.empty()){
		L.removeFront();
		count++;
	}
	return count;
}
#endif
