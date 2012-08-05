#include "../Q1/ArrayList.h"
#include <iostream>
#include <ctime>
int main()
{
	int size;
	cout << "Please Enter Size of the List:";
	cin >> size;
	List<int> aList(size);
	int p;
	int q;
	int r;
	//clock timing variables
	clock_t startTime;
	clock_t endTime;

	//array used for populating list

	double totalTime;
                               
	//
	//	TEST ARRAY -> IMPLEMENTATION
	//
	//Insertion time -front
	startTime = clock(); //get current time
	p = aList.First();
	for(int i = 1; i<=size; i++)
	{
		aList.Insert(i, p);
	}
	endTime = clock(); //get aList.End time
	totalTime = (endTime-startTime)/(double)(CLOCKS_PER_SEC);
	cout<<"Array Implemented List Times:\n";
	cout<<"Front Insertion: "<<totalTime<<"\n";
	//Deletion - front
	startTime = clock(); //get current time
	p = aList.First();
	while( p != aList.End() )
	{
		aList.Delete(p);
	}
	endTime = clock(); //get aList.End time
	totalTime = (endTime-startTime)/(double)(CLOCKS_PER_SEC);
	cout<<"Front Deletion: "<<totalTime<<"\n";
	//Insertion time- back
	startTime = clock(); //get current time
	for(int i = 1; i<=size; i++)
	{
		p = aList.End();
		aList.Insert(i,p);
	}
	endTime = clock(); //get aList.End time
	totalTime = (endTime-startTime)/(double)(CLOCKS_PER_SEC);
	cout<<"Back Insertion: "<<totalTime<<"\n";
	//Traversal
	startTime = clock(); //get current time
	p = aList.First();
	q = aList.End();
	while( p != q )
	{
		p = aList.Next(p);
	}
	endTime = clock(); //get aList.End time
	totalTime = (endTime-startTime)/(double)(CLOCKS_PER_SEC);
	cout<<"Front Traversal: "<<totalTime<<"\n";
	//Deletion - back
	startTime = clock(); //get current time
	p = aList.First();
	q = aList.Previous(aList.End());
	r = aList.End();
	while( p != r)	//get to beginning of list
	{
		aList.Delete(q);
		r = aList.End();
		q = aList.Previous(r);
	}
	q = aList.Previous(aList.End()); //delete last element

	endTime = clock(); //get aList.End time
	totalTime = (endTime-startTime)/(double)(CLOCKS_PER_SEC);
	cout<<"Back Deletion: "<<totalTime<<"\n";

	return 0;
}
