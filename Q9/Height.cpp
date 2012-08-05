#ifndef __H_INCLUDED__ 
#define __H_INCLUDED__ 
#include <iostream>
#ifdef Child_Siblings
#include "../Q4/Tree_Leftmost_Child_Right_Siblings.h"
#elif List_Children
#include "../Q4/Tree_List_Of_Children.h"
#endif
#endif


int Height(Tree T){
	if (Leftmost_Child(T,T) == 0){
		return 0; //one node
	}
	else{
		node_t child = Leftmost_Child(T,T);
		int max_height = Height(Right_Sibling(child,T)); //Height of leftmost child tree

		while (child != 0){ //Iterate Through all substrees to get the maximum height
			if (max_height < Height(child)){
				max_height = Height(child);
			}
			child = Right_Sibling(child,T);
		}
		
		return max_height+1;
	}
}

int main(){
	init();
	/*      1
 *  /   |  \
 *  2   3   4
 *  |  /\   |
 *  5 6  7  8
 */
	cout<< "***********************Problem 9: Book 3.3 Find Height**************************" <<endl;
	cout<< "TestCase1: ********************************" <<endl;
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
  cout << "The height of the tree is " << Height(T) << endl;
  
	cout<< "TestCase2: ********************************" <<endl;
	cout << "Created Single Node Tree A"<<endl;
	Tree TA = Create0((labeltype) "A");


	cout << "Call Create1((labeltype) \"B\",TA)"<<endl;
	Tree TBA = Create1((labeltype) "B",TA);
	cout << " Call Create1((labeltype) \"C\",TBA)"<<endl;
	Tree TCBA = Create1((labeltype) "C",TBA);
	cout << " Call Create1((labeltype) \"D\",TCBA)"<<endl;
	Tree TDCBA = Create1((labeltype) "D",TCBA);
	cout << " Call Create1((labeltype) \"E\",TDCBA)"<<endl;
	Tree TEDCBA = Create1((labeltype) "E",TDCBA);
  cout << "Final Tree Structure:"	<<endl;
  cout <<" /*  E" <<endl;
  cout <<"  *  |  "<<endl;
  cout <<"  *  D "<<endl;
  cout <<"  *  | "<<endl;
  cout <<"  *  C  "<<endl;
  cout <<"  *  | "<<endl;
  cout <<"  *  B "<<endl;
  cout <<"  *  | "<<endl;
  cout <<"  *  A "<<endl;
	cout << "The height of the tree is " << Height(TEDCBA) << endl;
	return 0;
}




