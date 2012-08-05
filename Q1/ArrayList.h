#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <iostream>
using namespace std;

template <typename E>
class List{
	private:
		int MAXSIZE;
		int last;
		E *elements;
	public:
		List();
		List(int size);
		void MakeNull();
		int First() const;
		int End() const;
		int Locate(E ele) const;
		int Next(int p) const;
		int Previous(int p) const;
		E Retrieve(int p) const;
		void Insert(E x, int p);
		void Delete(int p);
		void PrintList() const;
		
};

template <typename E>
List<E>::List(){
	MAXSIZE = 100;
	last = 0; //last occupied position in array
	elements = new E [MAXSIZE];
}

template <typename E>
List<E>::List(int size){
	MAXSIZE = size;
	last = 0; //last occupied position in array
	elements = new E [MAXSIZE];
}

template <typename E>
void List<E>::MakeNull(){
	last = 0;
}

template <typename E>
int List<E>::First() const
{
	return 1;
}

template <typename E>
int List<E>::End() const
{
	return last+1;
}

template <typename E>
int List<E>::Locate(E x) const // If not found, we just return the list header itself
{
	int i;

	for(i = 1; i<=last; i++)
	{
		if (elements[i] == x )
			return i;
	}
	return last+1; //Not found
}

template <typename E>
int List<E>::Next(int p) const
{
	return p+1;
}

template <typename E>
int List<E>::Previous(int p) const
{
	return p-1;
}

template <typename E>
E List<E>::Retrieve(int p) const
{
	if (p>=1 && p<=last){
		return elements[p];
	}

}

template <typename E>
void List<E>::Insert(E x, int p)
{
	if (last >= MAXSIZE){
		cout << "The List is FULL"<<endl;
	}
	if (p > last+1 ||p <1){
		cout << "Invalid Position"<<endl;
	}
	else{
		for(int i = last; i>=p; i--)
		{
			elements[i+1] = elements[i];
		}

		elements[p] = x;
		last = last + 1;
	}
}

template <typename E>
void List<E>::Delete(int p)
{
	if (p > last ||p <1){
		cout << "Invalid Position"<<endl;
	}
	else{
		last = last - 1;
		for(int i=p; i<=last; i++)
		{
			elements[i] = elements[i+1]; //Shift Elements down one position
		}
	}
}

template <typename E>
void List<E>::PrintList() const
{
	for(int i=1; i<=last; i++)
	{
		cout<<elements[i]<<",";
	}
}
#endif
