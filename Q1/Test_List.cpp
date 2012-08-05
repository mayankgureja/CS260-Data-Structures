#include <iostream>
#include <string>
#ifdef PointerList
#include "PointerList.h"
#elif ArrayList
#include "ArrayList.h"
#endif

int main()
{
	
	List<int> L;

	cout<<"Insert 45 at First position"<<endl;
	L.Insert(45,L.First());
	cout<<"Test #retrieve. After Insertion of 45, L.retrieve(L.First()) returns "<<L.Retrieve(L.First())<<". It Should be 45"<<endl;
	cout<<"Insert 75 at First position"<<endl;
	L.Insert(75,L.First());
	cout<<"Test #retrieve. After Insertion of 75, retrieve(First(L),L) returns "<<L.Retrieve(L.First())<<". It Should be 75"<<endl;
	cout<<"Insert 375 at First position"<<endl;
	L.Insert(375,L.First());
	cout<<"Test #retrieve. After Insertion of 375, retrieve(First(L),L) returns "<<L.Retrieve(L.First())<<". It Should be 375"<<endl;
	L.PrintList();
	cout <<". It should be 375,75,45"<<endl;
	cout<<"Test #next. retrieve(next(First(L),L),L) returns "<< L.Retrieve(L.Next(L.First()))<<". It Should be 75"<<endl;
	cout<<"Test #previous. retrieve(previous(next(First(L),L),L),L) returns "<< L.Retrieve(L.Previous(L.Next(L.First())))<<". It Should be 375"<<endl;
	L.Delete(L.First());
	cout<<"Test #delete. After L.Delete(L.First()),L.Retrieve(L.First()) returns "<< L.Retrieve(L.First())<<". It Should be 75"<< endl;
	cout<<"Current List is ";
	L.PrintList();
	cout << "It should be 75,45" << endl;
	cout << "Test #locate. L.Retrieve(L.Locate(45)) returns " << L.Retrieve(L.Locate(45)) << ". It should be 45" << endl;
	cout << "Test #MakeNULL." << endl;
	L.MakeNull();
	cout << "After the call to MakeNUll, the list should be empty. We insert an element 10 to the empty list." << endl;
	L.Insert(10,L.First());
	cout << "L.Retrieve(L.First()) returns " << L.Retrieve(L.First()) << ". It should return 10" << endl;
	
	return 0;
}
