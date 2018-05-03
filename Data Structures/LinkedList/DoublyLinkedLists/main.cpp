#include <iostream>
#include <stdlib.h> // EXIT_SUCCESS

using std::endl; using std::cout; using std::cin;

template <typename T>
class DLinkedList{
private:
    class Node{
    private:
        T value;
        Node<T> *next, *prev;
        Node(): T(), next(nullptr), prev(nullptr) {} // constructor
    };
private:
    typedef Node<T>* Nodeptr;
public:
	DLinkedList();					 //constructor
	~DLinkedList();					 //destructor
	void addFront(const T& elem); //insert node to the front
	void addBack(const T& elem);  //insert node to the back
	void removeFront(); 			 //rempve node at the front 
	void removeBack(); 				 //remove node at the back
	bool isEmpty(); 				 //checks if LL is empty.
	//extras
	//bool findMiddle();				 //finds the element at the middle of the DLL
    void print(){
        Node<T>* forwardPtr = head;
        while(true){
            cout << forwardPtr->value << endl;
            if(forwardPtr->next == nullptr)
                break;
            forwardPtr = forwardPtr->next;
        }
    }
private:
    Nodeptr head; Nodeptr tail;
protected:
	void add(Nodeptr v, const Elem& e);
	void remove(Nodeptr v);
};


int main()
{
	int n;
	DLinkedList<int> numbers;
	cout <<"Enter size: "; cin >>n;
	for(int i=0;i<n;i++)
		numbers.insertBack(i);
	//numbers.print();
	//numbers.removeFront();
	cout << endl << "Now removing a number from the front of the DLL." << endl;
	//numbers.print();
	//numbers.removeBack();
	//cout << endl << "Now removing a number from the back of the DLL." << endl;
	//numbers.print();
	return EXIT_SUCCESS;
}



template <typename T>
DLinkedList<T>::DLinkedList(){
	//create sentinels
	head =new Node<T>; 
	tail =new Node<T>;
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
    add(tail, elem)
}
template <typename T>
void DLinkedList<T>::removeFront()
{
    remove(head->next);
}

template <typename T>
void DLinkedList<T>::removeBack(){
    remove(tail->prev)
}

template <typename T>
bool DLinkedList<T>::isEmpty(){
	return head->next == tail;
}

template <typename T>
void DLinkedList<T>::remove(Nodeptr T)
{
    Nodeptr w = v->next;
    Nodeptr u = v->prev;
    w->prev = u;
    u->next = v;
    delete v;
}

template <typename T>
void DLinkedList<T>::add(Nodeptr v, const Elem& e)
{
    Nodeptr u = new Node; u->value = e;
    u->prev = v-prev;
    u->next = v;
    v->prev->next = v->prev = u; // const reference
}

//extras
/*
template <typename T>
bool DLinkedList::findMiddle();				 //finds the element at the middle of the DLL
*/

// sentinels are necessary because of the addBack and addFront algorithms
