#include <iostream>
#include <sstream>
#include "../Q1/ArrayList.h"
#include "../Q4/Tree_Leftmost_Child_Right_Siblings.h"
using namespace std;

int str2int (const string &str) {
	stringstream ss(str);
	int n;
	ss >> n;
	return n;
}

string int2str (int n) {
	stringstream ss;
	ss << n;
	return ss.str();
}
void preorder(Tree T){
	if (cellspace[T].leftmost_child == 0){
		cout << cellspace[T].label;
	}
	else{
		node_t leftmost_child = cellspace[T].leftmost_child;
		cout << cellspace[T].label;
		preorder(leftmost_child);
		node_t right_sibling = cellspace[leftmost_child].right_sibling;
		while (right_sibling !=0){
			preorder(right_sibling);
			right_sibling = cellspace[right_sibling].right_sibling;
		}
	}
}

class Node{
	public:
		Node();
		Node(int id, int l);
		int identifier;
		int isLeaf; //Indicate if a node is a leaf or not
};

Node::Node(int id, int l){
	identifier = id;
	isLeaf = l;
};
Node::Node(){
	identifier = 0;
	isLeaf = -1;
};

List<Node> *Pre2Post(const List<Node> &pre);
List<Node> *Post2Pre(const List<Node> &post);

List<Node> *Post2Pre(const List<Node> &post){
	List<Node> *pre;
	List<Node> tmp; //Copy of the original listing
	Tree T;
	
	int p = post.First();
	while(p != post.End()){
		tmp.Insert(post.Retrieve(p),tmp.End());
		p = post.Next(p);
	}
	
	while (tmp.First()+1 != tmp.End() ){ // Only one element left
		int q = tmp.First();
		while (tmp.Retrieve(q).isLeaf == 1){ //Look for first Interior Node
			q = tmp.Next(q);
		}
		int Leaf2 = tmp.Previous(q); // Right Child of the Interior Node
		int Leaf1 = tmp.Previous(Leaf2);// Left Child of the Interior Node

		Tree T2 = Create0(int2str(tmp.Retrieve(Leaf2).identifier));
		Tree T1 = Create0(int2str(tmp.Retrieve(Leaf1).identifier));
		T = Create2(int2str(tmp.Retrieve(q).identifier),T1,T2); // This is the subtree whose root is the Interior Node

		tmp.Delete(Leaf1);
		tmp.Delete(Leaf2);
		Node x = tmp.Retrieve(q);
		x.isLeaf = 1;
		cout << tmp.First() <<" and End is  " << tmp.End() << endl;
	}
	preorder(T);
	return pre;
	//Here is the first interior node

}

List<Node> *Pre2Post(const List<Node> &pre){

}


int main(){
	init();
	//For the example, we will use the tree as shown
	/*    1
 *   /    \
 *   2    4
 *  | \   /\ 
 * 5  6  7  8
 */
  //Preorde Listing is 12536748
  //Postorder Listing is 5627841
	List<Node> pre;
	List<Node> post;
	post.Insert(Node(5,1),post.End());
	post.Insert(Node(6,1),post.End());
	post.Insert(Node(2,0),post.End());
	post.Insert(Node(7,1),post.End());
	post.Insert(Node(8,1),post.End());
	post.Insert(Node(4,0),post.End());
	post.Insert(Node(1,0),post.End());
  List<Node> *x= Post2Pre(post);
//  cout << post[1].identifier << endl;
//	pre2 = Post2Pre(post)
//	in = Pre2In(pre);
	return 0;
}
