#include <string>
#include <iostream>

using namespace std;



typedef int node_t;
typedef int Tree;
typedef string labeltype;
const int MAXNODES = 100;

struct cell{
	labeltype label;
	node_t leftmost_child;
	node_t right_sibling;
	node_t parent;
};



void init();
node_t Parent(node_t n,Tree T);
node_t Leftmost_Child(node_t n, Tree T);
node_t Right_Sibling(node_t n, Tree T);
labeltype Label(node_t n,Tree T);
Tree Create0(labeltype v);
Tree Create1(labeltype v,Tree T1);
Tree Create2(labeltype v,Tree T1,Tree T2);
Tree Create3(labeltype v,Tree T1,Tree T2,Tree T3);
node_t Root(Tree T);
void MAKENULL(Tree T);

int avail; // Pointer to available cellspace
cell cellspace[MAXNODES+1];
void init(){
	//initialize cellspace to be all available
	avail =1;
	for (int i=1;i<=MAXNODES;i++){
		cellspace[i].right_sibling = i+1;
		cellspace[i].leftmost_child = 0;
	}
}
node_t Parent(node_t n,Tree T){
	return cellspace[n].parent;
}

node_t Leftmost_Child(node_t n, Tree T){
	return cellspace[n].leftmost_child;
}

node_t Right_Sibling(node_t n, Tree T){
	return cellspace[n].right_sibling;
}

labeltype Label(node_t n,Tree T){
	return cellspace[n].label;
}

Tree Create0(labeltype v){
	int temp = avail;
	avail = cellspace[avail].right_sibling;
	cellspace[temp].label = v;
	cellspace[temp].right_sibling = 0;
	return temp;
}

Tree Create1(labeltype v,Tree T1){
	int temp = avail;
	avail = cellspace[avail].right_sibling;
	cellspace[temp].leftmost_child = T1;
	cellspace[temp].label = v;
	cellspace[temp].right_sibling = 0; // Root has no right siblings
	cellspace[T1].parent = temp;
	return temp;
}

Tree Create2(labeltype v,Tree T1,Tree T2){
	int temp = avail;
	avail = cellspace[avail].right_sibling;
	cellspace[temp].leftmost_child = T1;
	cellspace[temp].label = v;
	cellspace[temp].right_sibling = 0;
	cellspace[T1].right_sibling = T2;
	cellspace[T1].parent = temp;
	cellspace[T2].parent = temp;
	return temp;
}

Tree Create3(labeltype v,Tree T1,Tree T2,Tree T3){
	int temp = avail;
	avail = cellspace[avail].right_sibling;
	cellspace[temp].leftmost_child = T1;
	cellspace[temp].label = v;
	cellspace[temp].right_sibling = 0;
	cellspace[T1].right_sibling = T2;
	cellspace[T2].right_sibling = T3;
	cellspace[T1].parent = temp;
	cellspace[T2].parent = temp;
	cellspace[T3].parent = temp;
	return temp;
}

node_t Root(Tree T){
	return T;
}

void MAKENULL(Tree T){ //MAKENULL will recycle the spaces occupied by the Tree and restpre all the relative relationships
	if (cellspace[T].leftmost_child == 0) {// It is the leaf
		int temp = cellspace[cellspace[T].parent].leftmost_child;
		if (temp == T){ //CASE1: Current Tree is the leftmost child of some tree, change the parent's leftmost child to the right sibling of current node
			cellspace[cellspace[T].parent].leftmost_child = cellspace[T].right_sibling;
		}
		else{ //CASE2 : Current Tree is the rightsibling of some node, change reference
			while (cellspace[temp].right_sibling != T){
				temp = cellspace[temp].right_sibling;
			}
			cellspace[temp].right_sibling = cellspace[T].right_sibling; //Change the reference of the node who references the node about to be deleted
		}
		cellspace[T].label = "";
		cellspace[T].right_sibling = 0;
		cellspace[T].leftmost_child = 0;
		temp = avail;
		while (cellspace[temp].right_sibling !=0 ){
			temp = cellspace[temp].right_sibling;
		}
		cellspace[temp].right_sibling = T;
	}

	else{
		int temp = cellspace[T].leftmost_child;
		while(cellspace[temp].right_sibling != 0){
			int next = cellspace[temp].right_sibling;
			MAKENULL(temp);
			temp = next;
		}
		MAKENULL(temp);
		MAKENULL(T);
	}
}

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

