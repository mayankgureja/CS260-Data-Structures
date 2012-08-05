#include <iostream>
#include <vector>
#include "../Q2/Stack.h"
using namespace std;

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

vector<Node> *Pre2Post(const vector<Node> &pre);
Node *Post2Pre(Node *post);
Node *Pre2In(Node *pre);

vector<Node> *Pre2Post(const vector<Node> &pre){
	int length = pre[6].identifier;
	cout << length << endl;
	vector<Node> *post;
	Stack<int, Node> S;
	
	int countLeaves = 0;
//	while (int i=0; i<length; i++){ //For each node check
//		if (pre[i]==1 && countLeaves !=2){ //Case 1: The node is a leaf but there are fewer than two leaves before
//			postPtr.[i]=pre[i];
// 			coutLeaves += 1;
//		}
//		else if (pre[i]==1 && countLeaves == 2){//Case 2: The node is a leaf and there are two leaves occur before
//			Node tmp = S.top();
//			S.pop();
//			postPtr[i] = S.top();
// 			coutLeaves = 0;
//		}
//		else if (countLeaves != 2 && pre[i+1].l==0){ //Case 3: The node is an internal node and fewer than 2 leaves occur before
//			S.push(pre[i]);
// 			coutLeaves += 1;
//		}
//	}
}


int main(){
	//For the example, we will use the tree as shown
	/*      1
 *  /   |  \
 *  2   3   4
 *  |  /\   |
 *  5 6  7  8
 */
  //Preorde Listing is 12536748
	vector<Node> pre;
	vector<Node> *post; 
//	vector<Node> in;
	pre.push_back(Node(1,0));
	pre.push_back(Node(2,0));
	pre.push_back(Node(5,1));
	pre.push_back(Node(3,0));
	pre.push_back(Node(6,1));
	pre.push_back(Node(7,1));
	pre.push_back(Node(4,0));
	pre.push_back(Node(8,1));
	
  post = Pre2Post(pre);
//  cout << post[1].identifier << endl;
//	pre2 = Post2Pre(post)
//	in = Pre2In(pre);
	return 0;
}
