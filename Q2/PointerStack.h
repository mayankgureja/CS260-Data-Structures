#ifndef PointerSTACK_H
#define PointerSTACK_H
#include <string>
#include <iostream>

using namespace std;

template<typename E>
class Node{
	public:
		Node();
		E element;
		Node* next;
};

template<typename E>
Node<E>::Node(){
}

template<typename E>
class Stack{
	private:
		Node<E> *topmost;	// current position of the first stack element
	public:
		Stack();
		void MAKENULL();
		bool empty() const;
		E top();
		void push(E x);
		void pop();
};


template<typename E>
Stack<E>::Stack(){
	topmost = new Node<E>();
};

template<typename E>
void Stack<E>::MAKENULL()
{
	while (!empty()){
		pop();
	}
};
template<typename E>
bool Stack<E>::empty() const
{
	if( topmost->next == NULL ) //check if items on stack
		return true;
	return false;
};

template<typename E>
E Stack<E>::top()
{
	if( !empty() ) //return NULL when nothing on stack
	{
		return topmost->element;
	}
};

template<typename E>
void Stack<E>::push(E x)	//return 1 on failure (full stack)
{
	Node<E> *new_node = new Node<E>();
	new_node->element = x;
	new_node->next = topmost;
	topmost = new_node;
};

template<typename E>
void Stack<E>::pop()
{
	if( empty() ) //return NULL when nothing on stack
	{
		cout<< "Nothing on the Stack" << endl;
	}
	else{
		Node<E> *tmp = topmost->next;
		delete(topmost);
		topmost = tmp;
	}
};
#endif
