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


