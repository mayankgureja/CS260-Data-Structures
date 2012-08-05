#include <iostream>
#include <string>
#ifdef PointerStack
#include "PointerStack.h"
#elif ArrayStack
#include "ArrayStack.h"
#endif

using namespace std;

int main()
{
	cout<<"Testing...\n";
	Stack<string> s;
	
	cout<<"Push 45"<<endl;
	s.push("45");
	cout<<"Test #Top: "<<s.top()<<". It Should be 45"<<endl;
	cout<<"Push 75"<<endl;
	s.push("75");
	cout<<"Push 378"<<endl;
	s.push("378");
	cout<<"Test #Empty "<< s.empty()<<". It Should be 0 	(boolean false)"<< endl; //check empty
	s.pop();
	cout<<"Test #Pop. After Pop, s.top() returns "<< s.top() <<". It should return 75"<<endl;
	s.pop();
	cout<<"Test #Pop. After Pop, s.top() returns "<< s.top() <<". It should return 45"<<endl;
	s.pop();
	cout <<"Test #Empty. Last Pop, s.empty() returns "<< s.empty() <<". It should return 1 (boolean true)"<<endl;
	cout<<"Push 10"<<endl;
	s.push("10");
	cout<<"Push 20"<<endl;
	s.push("20");
	cout <<"Current top "<< s.top() <<". It should be 20"<<endl;
	s.MAKENULL();
	cout<<"Test #MAKENULL. After s.MAKENULL(), s.empty() returns " << s.empty() << ". It should return 1"<< endl; //check empty
	return 0;
}


