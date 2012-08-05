#include <iostream>
#include <ctime>
#include <list>
using namespace std;

int main(){
	//
	//	TEST LIBRARY IMPLEMENTATION
	//
	int size;
	cout << "Please Enter Size of the List:";
	cin >> size;
	list<int> L;	
	list<int>::iterator p;
	list<int>::iterator q;
	
	//clock timing variables
	clock_t startTime;
	clock_t endTime;

	//array used for populating list

	double totalTime;
//Insertion time -front
	startTime = clock(); //get current time
	p = L.begin();
	for( int i = 0; i<size; i++)
	{
		L.insert(p,i);
	}
	endTime = clock(); //get dList.end time
	totalTime = (endTime-startTime)/(double)(CLOCKS_PER_SEC);
	cout<<"\n\nSTL Library (list) Implemented List Times:\n";
	cout<<"Front Insertion: "<<totalTime<<"\n";
	
//Deletion - front
	startTime = clock(); //get current time
	p = L.begin();
	while( p != L.end() )
	{
		L.erase(p);
		p = L.begin();
	}
	endTime = clock(); //get dList.end time
	totalTime = (endTime-startTime)/(double)(CLOCKS_PER_SEC);
	cout<<"Front Deletion: "<<totalTime<<"\n";
//Insertion time- back
	startTime = clock(); //get current time
	for( int i = 0; i<size; i++)
	{
		p = L.end();
		L.insert(p,i);
	}
	endTime = clock(); //get dList.end time
	totalTime = (endTime-startTime)/(double)(CLOCKS_PER_SEC);
	cout<<"Back Insertion: "<<totalTime<<"\n";
//Traversal - front
	startTime = clock(); //get current time
	p = L.begin();
	q = L.end();

	for (p=L.begin(); p != q; p++){}

	endTime = clock(); //get dList.end time
	totalTime = (endTime-startTime)/(double)(CLOCKS_PER_SEC);
	cout<<"Front Traversal: "<<totalTime<<"\n";
//Deletion - back
	startTime = clock(); //get current time
	p = L.begin();
	q = L.end();
	q--;
	while( p != q)	//get to beginning of list
	{
		L.erase(q);
		q = L.end();
		q--;
	}
	endTime = clock(); //get dList.end time
	totalTime = (endTime-startTime)/(double)(CLOCKS_PER_SEC);
	cout<<"Back Deletion: "<<totalTime<<"\n";

	return 0;
}

