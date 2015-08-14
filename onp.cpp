//DATE: 14/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/ONP/

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;
int isoperator(char c){
	if(c == '+' || c == '-' ||c == '*' ||c == '/' ||c == '^')
		return 1;
	return 0;
}
int main()
{
	int t;
	string input;
	stack<char> stk;
	cin>>t;
	while(t--){
		cin>>input;
		int len = input.length();
		for(int i = 0; i < len; i++){
			if(input[i] == ')'){
				cout<<stk.top();
				stk.pop();
			}
			else if(islower(input[i]))
				cout<<input[i];
			else if(isoperator(input[i]))
				stk.push(input[i]);
		}
		cout<<endl;
	}
}
