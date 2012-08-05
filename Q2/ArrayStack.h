#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#include <string>
#include <iostream>

using namespace std;

template<typename E>
class Stack{
	private:
		int MAXSIZE; //stack capacity
		int topmost;	// current position of the first stack element
		E *elements;
	public:
		Stack();
		~Stack();
		void MAKENULL();
		bool empty() const;
		E top();
		void push(E x);
		void pop();
};


template<typename E>
Stack<E>::Stack(){
		MAXSIZE = 100; //stack capacity
		topmost = MAXSIZE+1;	// current position of the first stack element
		elements = new E [MAXSIZE+1];
};

template <typename E>
Stack<E>::~Stack(){
	delete[] elements;
}


template<typename E>
void Stack<E>::MAKENULL()
{
	topmost = MAXSIZE+1;
};
template<typename E>
bool Stack<E>::empty() const
{
	if( topmost > MAXSIZE ) //check if items on stack
		return true;
	return false;
};
template<typename E>
E Stack<E>::top()
{
	if( !empty() ) //return NULL when nothing on stack
	{
		return elements[topmost];
	}
};
template<typename E>
void Stack<E>::push(E x)	//return 1 on failure (full stack)
{
	if( topmost == 0 ) //return 1 when full
	{
		cout<<"Max size Reached Already";
	}
	topmost = topmost-1 ;
	elements[topmost] = x;
};
template<typename E>
void Stack<E>::pop()
{
	if( empty() ) //return NULL when nothing on stack
	{
		cout<< "Nothing on the Stack" << endl;
	}
	else{
		topmost += 1 ;
	}
};
#endif
