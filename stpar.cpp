//DATE: 19/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/STPAR/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <string>

# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int
# define FOR(i,j,n) for(i = j; i < n; i++)

using namespace std;

int main(){

	int n;
	cin>>n;
	while(n){
		vector<int> vec(n);
		stack<int> stk;
		for(int i = 0; i < n; i++)
			cin>>vec[i];
		int turn = 1;
		int i = 0;
		while(i < n){
			if(turn == vec[i]){
				i++;
				turn++;
			}
			else if(!stk.empty() && turn == stk.top()){
				stk.pop();
				turn++;
			}
			else {
				stk.push(vec[i]);
				i++;
			}
		}
		while(!stk.empty() && turn == stk.top()){
			stk.pop();
			turn++;
		}
		turn == n+1 ? cout<<"yes"<<endl : cout<<"no"<<endl;
		cin>>n;
	}
}

//test cases :
// 5 
// 4 1 5 3 2
// 5
// 3 1 2 5 4
// 5 
// 5 3 2 1 4
// 10 
// 1 2 10 5 4 3 7 6 8 9
// 10
// 1 2 10 5 4 3 9 8 7 6
// 5 
// 3 5 2 4 1
// 5
// 1 2 3 4 5
// 4
// 4 2 3 1 
