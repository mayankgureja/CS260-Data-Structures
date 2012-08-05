#include <iostream>
#include "../Q1/PointerList.h"

List<int> Concat_Pointer(List< List<int> > L){
	List<int> Result;
	List<int> tmp;
	
	Node< List<int> > *p = L.First();
	while (p != L.End()){
		tmp = L.Retrieve(p);
		Node<int> *q = tmp.First();
		while (q != tmp.End()){
			Result.Insert(tmp.Retrieve(q),Result.End());
			q = tmp.Next(q);
		}
		p = L.Next(p);
	}
	return Result;
}


int main(){
	List< List<int> > L;
	List<int> L1;
	List<int> L2;
	List<int> L3;
	List<int> L4;
	List<int> Result;
	cout<< "Initialize List1 to [10,20,30,40]" << endl;
	L1.Insert(40,L1.First());
	L1.Insert(30,L1.First());
	L1.Insert(20,L1.First());
	L1.Insert(10,L1.First());
	
	cout<< "Initialize List2 to [50,60]" << endl;
	L2.Insert(60,L2.First());
	L2.Insert(50,L2.First());
	
	cout<< "Initialize List3 to [70,80]" << endl;
	L3.Insert(80,L3.First());
	L3.Insert(70,L3.First());

	cout<< "Initialize List4 to [90,100,110]" << endl;
	L4.Insert(110,L4.First());
	L4.Insert(100,L4.First());
	L4.Insert(90,L4.First());
	
	cout<< "Insert L1-L4 into L a list of list" << endl;
	L.Insert(L4,L.First());
	L.Insert(L3,L.First());
	L.Insert(L2,L.First());
	L.Insert(L1,L.First());
	
	Result = Concat_Pointer(L);
	cout << "After Concatenation the list becomes:" << endl;
	Result.PrintList();
	cout << endl;
}
