#ifndef __H_INCLUDED__ 
#define __H_INCLUDED__ 
#include <iostream>
#ifdef Child_Siblings
#include "Tree_Leftmost_Child_Right_Siblings.h"
#elif List_Children
#include "Tree_List_Of_Children.h"
#endif
#endif

int main(){
	init();
/*      1
 *  /   |  \
 *  2   3   4
 *  |  /\   |
 *  5 6  7  8
 */
	// Get all the leaves
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

  cout << "Final Tree Structure:"	<<endl;
  cout <<" /*      1" <<endl;
  cout <<"  *  /   |  \\"<<endl;
  cout <<"  *  2   3   4"<<endl;
  cout <<"  *  |  /\\   |"<<endl;
  cout <<"  *  5 6  7  8 "<<endl;

	cout << "Test #Root. Call Label(Root(T),T). The root is " <<Label(Root(T),T) << ". The root should be 1"<<endl;
	node_t B = Leftmost_Child(T,T);
	cout << "Test #Leftmost_Child. The leftmost child of 1 is " << Label(B,T) << ". It should be 2"<<endl;
	node_t C = Right_Sibling(B,T);
	cout << "Test #Right_Sibling. The Right sibling of  2 is " << Label(C,T) << ". It should be 3"<<endl;
	node_t D = Right_Sibling(C,T);
	cout << "The Right sibling of 3 is " << Label(D,T) << ". It should be 4"<<endl;

	node_t E = Leftmost_Child(B,T);
	cout << "The leftmost child of 2 is "<< Label(E,T) << ". It should be 5"<<endl;
	node_t F = Leftmost_Child(C,T);
	cout << "The Leftmost Child of 3 is "<< Label(F,T) << ". It should be 6"<<endl;
	node_t G = Right_Sibling(F,T);
	cout << "The Right sibling of 6 is " << Label(G,T) << ". It should be 7"<<endl;
	node_t H = Leftmost_Child(D,T);
	cout << "The Leftmost Child of 4 is " << Label(H,T) << ". It should be 8"<<endl;

	cout << "Test #MAKENULL. CALL MAKENULL(T367)" << endl;
	MAKENULL(T367);
	cout << "The Tree should become this :" << endl;
	
	cout << "Final Tree Structure:"	<<endl;
  cout <<" /*    1" <<endl;
  cout <<"  *  /   \\"<<endl;
  cout <<"  *  2    4"<<endl;
  cout <<"  *  |    |"<<endl;
  cout <<"  *  5    8 "<<endl;
	
	node_t left_child = Leftmost_Child(Root(T),T);
	cout << "Call Leftmost_Child(Root(T),T) returns " << Label(left_child,T) << ". It should return 2" << endl;
	cout << "Call Right_Sibling(left_child,T) returns " << Label(Right_Sibling(left_child,T),T);
	cout << ". It should return 4" << endl;

	return 0;
}

