#ifndef POINTERLIST_H
#define POINTERLIST_H
#include <iostream>
using namespace std;
template <typename E>
class Node{
	public:
		Node();
		E element;
		Node* next;
};

template <typename E>
Node<E>::Node(){
	element = E (NULL);
	next = NULL;
}

template <typename E>
class List{
	private:
		Node<E> *header;
	public:
		List();
		
		void MakeNull();
		Node<E> *First();
		Node<E> *End();
		Node<E> *Locate(E ele);
		Node<E> *Next(Node<E> *p);
		Node<E> *Previous(Node<E> *p);
		E Retrieve(Node<E> *p);
		void Insert(E x, Node<E> *p);
		void Delete(Node<E> *p);
		void PrintList();
};

template <typename E>
List<E>::List(){
	header = new Node<E>();
}

template <typename E>
void List<E>::MakeNull(){
	Node<E> *p = header;
	Node<E> *tmp = new Node<E>();
	while (p->next != NULL)
	{
		tmp = p->next;
		delete(p);
		p = tmp;
	}
}

template <typename E>
Node<E> *List<E>::First()
{
	return header;
}

template <typename E>
Node<E> *List<E>::End()
{
	Node<E> *p = header;

	while( p->next != NULL )
	{
		p = p->next;
	}
	return p;
}

template <typename E>
Node<E> *List<E>::Locate(E x) // If not found, we just return the list header itself
{
	Node<E> *p = header;
	while( p->next != NULL )
	{
		if ( p->next->element == x )
			return p;
		else
			p = p->next;
	}
	return p;
}

template <typename E>
Node<E> *List<E>::Next(Node<E> *p)
{
	return p->next;
}

template <typename E>
Node<E> *List<E>::Previous(Node<E> *p)
{
	Node<E> *q = header;

	while( q->next != p )
	{
		q = q->next;
	}
	return q;
}

template <typename E>
E List<E>::Retrieve(Node<E> *p)
{
	return p->next->element;
}

template <typename E>
void List<E>::Insert(E x, Node<E> *p)
{
	Node<E> *tmp = new Node<E>(); //create a new Node<E>
	tmp->next = p->next;
	tmp->element = x;
	p->next = tmp;
}

template <typename E>
void List<E>::Delete(Node<E> *p)
{
	Node<E> *node_next = p->next;
	p->next = p->next->next;
	delete(node_next);
}

template <typename E>
void List<E>::PrintList()
{
	Node<E> *p = header;
	while (p->next != NULL)
	{
		cout << p->next->element << ",";
		p = p->next;
	}
}
#endif
