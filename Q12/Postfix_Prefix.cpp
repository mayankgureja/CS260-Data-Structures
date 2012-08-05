#include <string>
#include <iostream>
#include <sstream>
#include "../Q2/Stack.h"

using namespace std;

int str2int (const string &str);
string int2str (int n);
string EvalPostfix(string postfix);
string EvalPrefix(string prefix);

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
string EvalPrefix(string prefix){
	Stack<int,string> S;

	int result;
	int x;
	int y;
	for (int i=prefix.length()-1;i>=0; i--){ //Reverse Scan Prefix
		string input = prefix.substr(i,1);
		if (input.compare("+") !=0 && input.compare("-") !=0 && input.compare("*") !=0 && input.compare("/") !=0){ //If the input is not operator
			S.push(input);
		}
		else{
			x = str2int(S.top());
			S.pop();
			y = str2int(S.top());
			S.pop();
			if (input.compare("+") == 0){
				result = x+y;
			}
			else if (input.compare("-") == 0){
				result = x-y;
			}
			else if (input.compare("*") == 0){
				result = x*y;
			}
			else {
				result = x/y;
			}
			S.push(int2str(result));
		}
	}
	return S.top();
}

string EvalPostfix(string postfix){
	Stack<int,string> S;

	int result;
	int x;
	int y;
	for (int i=0;i<postfix.length(); i++){ //Reverse In order
		string input = postfix.substr(i,1);
		if (input.compare("+") !=0 && input.compare("-") !=0 && input.compare("*") !=0 && input.compare("/") !=0){
			S.push(input);
		}
		else{
			x = str2int(S.top());
			S.pop();
			y = str2int(S.top());
			S.pop();
			if (input.compare("+") == 0){
				result = y+x;
			}
			else if (input.compare("-") == 0){
				result = y-x;
			}
			else if (input.compare("*") == 0){
				result = y*x;
			}
			else {
				result = y/x;
			}
			S.push(int2str(result));
		}
	}
	return S.top();
}
int main(){
		cout<< "******Problem 12: Book 3.14 Prefix/Postfix Evaluation**********" <<endl;

	/*     *
	 *   /   \
	 *  +     -
	 * /\	  /\
	 * 1 2   5  4
	 */
	string s;
	cout << "Test case 1:" << endl;
	cout<< "Given Prefix Expression *+12-45, the evaluation result is " <<EvalPrefix("*+12-54")<<". It should be 3" <<endl;
	cout<< "Given Postfix Expression 12+54-*, the evaluation result is " <<EvalPostfix("12+54-*")<<". It should be 3" <<endl;
	cout << "Test case 2:" << endl;
	cout<< "Given Prefix Expression */-82*31+23, the evaluation result is " <<EvalPrefix("*/-82*31+23")<<". It should be 10" <<endl;
	cout<< "Given Postfix Expression 82-31*/23+*, the evaluation result is " <<EvalPostfix("82-31*/23+*")<<". It should be 10" <<endl;

	return 0;
}
