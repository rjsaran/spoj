//DATE: 19/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/GIRBS/

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

	int a,b;
	int G,B;
	cin>>a>>b;
	while(a != -1){
		G = MAX(a,b);
		B = MIN(a,b);
		int sol = G / (B+1) + (G % (B+1) > 0);
        cout<<sol<<endl;
		cin>>a>>b;
	}
}