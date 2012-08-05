#include <iostream>
#include "Tree_listChildren.h"

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
	Tree_listChildren T8 = Tree_listChildren.Create0((labeltype) "8");
	cout << T8.Parent() <<endl;
	}
