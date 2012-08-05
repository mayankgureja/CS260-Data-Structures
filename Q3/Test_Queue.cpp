#include <iostream>
#include <string>
#include "Queue.h"

using namespace std;

int main()
{
	cout<<"Testing...\n";
	Queue<string> Q;
	
	cout<<"Enqueue 45"<<endl;
	Q.Enqueue("45");	
	cout<<"Test #Front: "<<Q.Front()<<". It Should be 45"<<endl;
	cout<<"Enqueue 75"<<endl;
	Q.Enqueue("75");
	cout<<"Enqueue 378"<<endl;
	Q.Enqueue("378");
	cout<<"Test #Empty "<< Q.Empty()<<". It Should be 0 	(boolean false)"<< endl; //check empty
	Q.Dequeue();
	cout<<"Test #Dequeue. After Dequeue, Q.Front() returns "<< Q.Front() <<". It should return 75"<<endl;
	Q.Dequeue();
	cout<<"Test #Dequeue. After Dequeue, Q.Front() returns "<< Q.Front() <<". It should return 378 "<<endl;
	Q.Dequeue();
	cout <<"Test #Empty. Last Dequeue, Q.empty() returns "<< Q.Empty() <<". It should return 1 (boolean true)"<<endl;
	cout<<"Enqueue 10"<<endl;
	Q.Enqueue("10");
	cout<<"Enqueue 20"<<endl;
	Q.Enqueue("20");
	cout <<"Current Front "<< Q.Front() <<". It should be 10"<<endl;
	Q.MakeNull();
	cout<<"Test #MAKENULL. After Q.MAKENULL(), Q.Empty() returns " << Q.Empty() << ". It should return 1"<< endl; //check empty
	return 0;
}


