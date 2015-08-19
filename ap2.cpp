//DATE: 19/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/AP2/

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

	int t;
	ull A, B, S, N, D, a;
	cin>>t;
	while(t--){
		cin>>A>>B>>S;
		N = (S * 2) / (A + B);
		D = (B - A) / (N - 5);
		a = A - (2 * D);
		cout<<N<<endl;
		for(int i = 0; i < N; i++){
			cout<<a + i * D<<" ";
		}
		cout<<endl;
	}	
}