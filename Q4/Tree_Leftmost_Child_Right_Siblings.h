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


