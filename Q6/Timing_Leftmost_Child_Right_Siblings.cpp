#include "../Q4/Tree_Leftmost_Child_Right_Siblings.h"
#include <iostream>
#include <ctime>

void preorder(Tree T){
	if (cellspace[T].leftmost_child == 0){
		cout << cellspace[T].label<<",";
	}
	else{
		node_t leftmost_child = cellspace[T].leftmost_child;
		cout << cellspace[T].label<<",";
		preorder(leftmost_child);
		node_t right_sibling = cellspace[leftmost_child].right_sibling;
		while (right_sibling !=0){
			preorder(right_sibling);
			right_sibling = cellspace[right_sibling].right_sibling;
		}
	}
}

int main()
{
	int size;
	cout << "Please Enter Number of Times to traverse the Tree:";
	cin >> size;
	//clock timing variables
	clock_t startTime;
	clock_t endTime;
	double totalTime;
	//	traversals of full trees of degree three and height 3.
	init();
	/*         1
 *    /     |      \
 *   2      3      4
 *  /|\    /|\    / | \
 * 5 67   8 9 10 11 12 13
 */
	cout<< "***********************Problem 6: Tree Traversal Timing**************************" <<endl;

	Tree T13 = Create0((labeltype) "13");	
	Tree T12 = Create0((labeltype) "12");
	Tree T11 = Create0((labeltype) "11");
	Tree T10 = Create0((labeltype) "10");
	Tree T9 = Create0((labeltype) "9");
	Tree T8 = Create0((labeltype) "8");
	Tree T7 = Create0((labeltype) "7");
	Tree T6 = Create0((labeltype) "6");
	Tree T5 = Create0((labeltype) "5");


	Tree T2567 = Create3((labeltype) "2",T5,T6,T7);
	Tree T38910 = Create3((labeltype) "3",T8,T9,T10);
	Tree T4111213 = Create3((labeltype) "4",T11,T12,T13);
	Tree T = Create3((labeltype) "1",T2567,T38910,T4111213);
	
  cout << "Final Tree Structure:"	<<endl;
	cout <<	"/*         1" <<endl;
	cout <<" *    /     |      \\"<<endl;
	cout <<" *   2      3      4" << endl;
	cout <<" *  /|\\    /|\\    / | \\"<<endl;
	cout <<" * 5 67   8 9 10 11 12 13"<<endl;
	startTime = clock(); //get current time
	for (int i=0; i<size;i++){
		preorder(T);
		cout<< endl;
	}
	endTime = clock(); //get aList.End time
	totalTime = (endTime-startTime)/(double)(CLOCKS_PER_SEC);
	cout<<"Tree Traversal (PreOrder): "<<totalTime/size<<"\n";
	return 0;
}
