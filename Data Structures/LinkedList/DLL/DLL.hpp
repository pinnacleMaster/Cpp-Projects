#ifndef DLL_HPP
#define DLL_HPP
#include <iostream>
#include <iostream>

using std::endl; using std::cout; using std::cin;

template <typename T>
class DLinkedList{
private:
    struct Node{
        T value;
        Node *next, *prev;
       // Node(): T(), next(nullptr), prev(nullptr) {} // constructor
    };
private:
    typedef Node* Nodeptr;
public:
	DLinkedList();					 //constructor
	~DLinkedList();					 //destructor
	const T& front() const;
	const T& back() const;
	void addFront(const T& elem); //insert node to the front
	void addBack(const T& elem);  //insert node to the back
	void removeFront(); 			 //rempve node at the front
	void removeBack(); 				 //remove node at the back
	bool isEmpty(); 				 //checks if LL is empty.
	//extras
	//bool findMiddle();				 //finds the element at the middle of the DLL
    void print(){
        Nodeptr fCursor = head->next;
        	cout << back() << endl;

    }
private:
    Nodeptr head; Nodeptr tail;
protected:
	void add(Nodeptr v, const T& e);
	void remove(Nodeptr v);
};


template <typename T>
DLinkedList<T>::DLinkedList(){
	//create sentinels
	head =new Node;
	tail =new Node;
	//make them point to each other
	head->next = tail;
	tail->prev = head;

}

template <typename T>
DLinkedList<T>::~DLinkedList(){
	while(!isEmpty())
		removeFront(); // remove all but sentinels
		//remove sentinels
		delete head;
		delete tail;
}

template <typename T>
void DLinkedList<T>::addFront(const T& elem){
    add(head->next, elem);
}

template <typename T>
void DLinkedList<T>::addBack(const T& elem){
    add(tail, elem);
}
template <typename T>
void DLinkedList<T>::removeFront()
{
    remove(head->next);
}

template <typename T>
void DLinkedList<T>::removeBack(){
    remove(tail->prev);
}

template <typename T>
bool DLinkedList<T>::isEmpty(){
	return head->next == tail;
}

template <typename T>
void DLinkedList<T>::remove(Nodeptr v)
{
    Nodeptr w = v->next;
    Nodeptr u = v->prev;
    w->prev = u;
    u->next = v;
    delete v;
}

template <typename T>
void DLinkedList<T>::add(Nodeptr v, const T& e)
{
    Nodeptr u = new Node;
    u->value = e;
    u->prev = v->prev;
    u->next = v;
    v->prev->next = v->prev = u; // const reference
	cout << "adding: " << u->value << endl;
}

template <typename T>
const T& DLinkedList<T>::front() const // get front element
{ return head->next->value; }

template <typename T>
const T& DLinkedList<T>::back() const // get back element
{ return tail->prev->value; }

#endif /* DLL_HPP */

//extras
/*
template <typename T>
bool DLinkedList::findMiddle();				 //finds the element at the middle of the DLL
*/

// sentinels are necessary because of the addBack and addFront algorithms
