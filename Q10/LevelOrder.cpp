#ifndef __H_INCLUDED__ 
#define __H_INCLUDED__ 
#include <iostream>
#include "../Q3/Queue.h"
#ifdef Child_Siblings
#include "../Q4/Tree_Leftmost_Child_Right_Siblings.h"
#elif List_Children
#include "../Q4/Tree_List_Of_Children.h"
#endif
#endif

void LevelOrders(Tree T){
	Queue<node_t> Q;
	node_t tmp = Root(T);
	while (Label(tmp,T) != ""){
		cout << Label(tmp,T);
		node_t child = Leftmost_Child(tmp,T);
		while (Right_Sibling(child,T) != 0){
			Q.Enqueue(child);
			child = Right_Sibling(child,T);
		}
		Q.Enqueue(child);
		tmp = Q.Front();
		Q.Dequeue();
	}

}

int main(){
	init();
	cout << "Test #Create0. Created Single Node Tree 8"<<endl;
	Tree T8 = Create0((labeltype) "8");
	cout << "Test #Create0. Created Single Node Tree 7"<<endl;
	Tree T7 = Create0((labeltype) "7");
	cout << "Test #Create0. Created Single Node Tree 6"<<endl;
	Tree T6 = Create0((labeltype) "6");
	cout << "Test #Create0. Created Single Node Tree 5"<<endl;
	Tree T5 = Create0((labeltype) "5");

	cout << "Test #Create1. Call Create1((labeltype) \"2\",T5)"<<endl;
	Tree T25 = Create1((labeltype) "2",T5);
	cout << "Test #Create1. Call Create2((labeltype) \"3\",T6,T7)"<<endl;
	Tree T367 = Create2((labeltype) "3",T6,T7);
	cout << "Test #Create1. Call Create1((labeltype) \"4\",T8)"<<endl;
	Tree T48 = Create1((labeltype) "4",T8);
	cout << "Test #Create. Call Create3((labeltype) \"1\",T25,T367,T48)"<<endl;
	Tree T = Create3((labeltype) "1",T25,T367,T48);
//  cout << "Final Tree Structure:"	<<endl;
//  cout <<" /*      1" <<endl;
//  cout <<"  *  /   |  \\"<<endl;
//  cout <<"  *  2   3   4"<<endl;
//  cout <<"  *  |  /\\   |"<<endl;
//  cout <<"  *  5 6  7  8 "<<endl;
	
	LevelOrders(T);
	cout << endl;
}
