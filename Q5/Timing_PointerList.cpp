#include "../Q1/PointerList.h"
#include <iostream>
#include <ctime>
#include <list>
int main(){
//	
//		TEST POINTER -> IMPLEMENTATION
//	
	int size;
	cout << "Please Enter Size of the List:";
	cin >> size;
	
	List<int> pList;
	Node<int> *p;
	Node<int>* q;
	Node<int>* r;
	//clock timing variables
	clock_t startTime;
	clock_t endTime;

	//array used for populating list

	double totalTime;
                        
//Insertion time -front
	startTime = clock(); //get current time
	for( int i = 0; i<size; i++)
	{
		p = pList.First();
		pList.Insert(i,p);
	}
	endTime = clock(); //get pList.End time
	totalTime = (endTime-startTime)/(double)(CLOCKS_PER_SEC);
	cout<<"Pointer Implemented List Times:\n";
	cout<<"Front Insertion: "<<totalTime<<"\n";
//Deletion - front
	startTime = clock(); //get current time
	p = pList.First();
	while( p != pList.End() )
	{
		pList.Delete(p);
	}
	endTime = clock(); //get pList.End time
	totalTime = (endTime-startTime)/(double)(CLOCKS_PER_SEC);
	cout<<"Front Deletion: "<<totalTime<<"\n";
//Insertion time- back
	startTime = clock(); //get current time
	for( int i = 0; i<50000; i++)
	{
		p = pList.End();
		pList.Insert(i,p);
	}
	endTime = clock(); //get pList.End time
	totalTime = (endTime-startTime)/(double)(CLOCKS_PER_SEC);
	cout<<"Back Insertion: "<<totalTime<<"\n";
//Traversal - front
	startTime = clock(); //get current time
	p = pList.First();
	q = pList.End();
	while( p != q )
	{
		p = pList.Next(p);
	}
	endTime = clock(); //get pList.End time
	totalTime = (endTime-startTime)/(double)(CLOCKS_PER_SEC);
	cout<<"Front Traversal: "<<totalTime<<"\n";
//Deletion - back
	startTime = clock(); //get current time
	p = pList.First();
	q = pList.Previous(pList.End());
	while( p != q)	//get to beginning of list
	{
		pList.Delete(q);
		q = pList.Previous(pList.End());
	}
	endTime = clock(); //get pList.End time
	totalTime = (endTime-startTime)/(double)(CLOCKS_PER_SEC);
	cout<<"Back Deletion: "<<totalTime<<"\n";
	
	return 0;
}

