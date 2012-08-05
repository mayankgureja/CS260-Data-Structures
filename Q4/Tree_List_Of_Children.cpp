#include <string>
using namespace std;

const int MAXNODES = 100;

typedef int node_t;
typedef int Tree;
typedef string labeltype;

struct cell{
	node_t node;
	int next;
};


struct nodes{
	labeltype label;
	int header;
	node_t parent;
};

void init();
node_t Parent(node_t n,Tree T);
node_t Leftmost_Child(node_t n, Tree T);
node_t Right_Sibling(node_t n, Tree T);
labeltype Label(node_t n,Tree T);
Tree Create0(labeltype l);
Tree Create1(labeltype l,Tree T1);
Tree Create2(labeltype l,Tree T1,Tree T2);
Tree Create3(labeltype l,Tree T1,Tree T2,Tree T3);
node_t Root(Tree T);
void MAKENULL(Tree& T);


int avail; // pointing to spaces available
nodes nodespace[MAXNODES+1];
cell cellspace[MAXNODES+1];

void init(){
	//initialize cellspace to all available
	avail =1;
	for (int i=1;i<=MAXNODES;i++){
		cellspace[i].next = i+1;
	}
}

node_t Parent(node_t n,Tree T){ //Return the Parent of node n of Tree T
	return nodespace[n].parent;
}

node_t Leftmost_Child(node_t n, Tree T){
	int header = nodespace[n].header;
	if (header==0)//n is a leaf
		return 0;
	else
		return cellspace[header].node;
};


node_t Right_Sibling(node_t n, Tree T){
	node_t parent = Parent(n,T);
	int child_pos = nodespace[parent].header;
	if (cellspace[child_pos].next == 0)//n is the only child
		return 0; // no right sibling
	else{
		while (cellspace[child_pos].node != n){
			child_pos = cellspace[child_pos].next;
		}
		return cellspace[cellspace[child_pos].next].node;
	}
};

labeltype Label(node_t n,Tree T){
	return nodespace[n].label;
};


Tree Create0(labeltype l){
	int i=1;
	while(nodespace[i].label != ""){ //Find available nodespaces
		i +=1;
	}
	nodespace[i].label = l;
	nodespace[i].header = 0; //It's the only node, so no children list;
	nodespace[i].parent = 0; //It's the root, no parent
	Tree new_T = i; // New_Tree is just a cursor pointing to the position of the root in nodespace
	return new_T;
};

Tree Create1(labeltype l,Tree T1){
	int i=1;
	while(nodespace[i].label != ""){ //Find available nodespaces
		i +=1;
	}
	nodespace[i].label = l;
	int temp = avail;
	avail = cellspace[avail].next; //New space for the root;
	cellspace[temp].node = T1; //T1 will be the children of new node
	cellspace[temp].next = 0; //T1 has no siblings.
	nodespace[i].header =temp;
	nodespace[i].parent =0;
	nodespace[T1].parent = i;
	Tree new_T = i;
	return new_T;
}

Tree Create2(labeltype l,Tree T1,Tree T2){
	int i=1;
	while(nodespace[i].label != ""){ //Find available nodespaces
		i +=1;
	}
	nodespace[i].label = l;
	int temp = avail;
	avail = cellspace[avail].next; //New space for the T1 child of the root;
	cellspace[temp].node = T1; //T1 will be the children of new node
	cellspace[temp].next = avail; // The next available space will be reserved for T2
	int temp2 = avail;
	avail = cellspace[avail].next; //New space for the T2 child of the root;
	cellspace[temp2].node = T2; //T1 has T2 as its sibling.
	cellspace[temp2].next = 0; //T2 has no siblings afterwards.
	nodespace[i].header = temp;
	nodespace[i].parent = 0;
	nodespace[T1].parent = i;
	nodespace[T2].parent = i;
	Tree new_T = i;
	return new_T;
}
Tree Create3(labeltype l,Tree T1,Tree T2,Tree T3){
	int i=1;
	while(nodespace[i].label != ""){ //Find available nodespaces
		i +=1;
	}
	nodespace[i].label = l;
	int temp = avail;
	avail = cellspace[avail].next; //New space for the T1 child of the root;
	cellspace[temp].node = T1; //T1 will be the children of new node
	cellspace[temp].next = avail; // The next available space will be reserved for T2
	int temp2 = avail;
	avail = cellspace[avail].next; //New space for the T2 child of the root;
	cellspace[temp2].node = T2; //T1 has T2 as its sibling.
	cellspace[temp2].next = avail; //The next available space will be reserved for T3
	int temp3 = avail;
	avail = cellspace[avail].next; //New space for the T2 child of the root;
	cellspace[temp3].node = T3; //T2 has T3 as its sibling.
	cellspace[temp3].next = 0; //T3 has no siblings afterwards.
	nodespace[i].header =temp;
	nodespace[i].parent = 0;
	nodespace[T1].parent = i;
	nodespace[T2].parent = i;
	nodespace[T3].parent = i;
	Tree new_T = i;
	return new_T;
}
node_t Root(Tree T){
	return T;
}
/*  This function traverses tree in post order to 
	  to delete each and every node of the tree */
void MAKENULL(Tree& T){
	
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
