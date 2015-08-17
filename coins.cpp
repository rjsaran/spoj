//DATE: 17/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/COINS/

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <unordered_map>

# define MAX(a,b) a>b ? a : b;
# define ull unsigned long long int

using namespace std;

int r[1000001];

ull byte(ull n){
		unordered_map <ull, ull> coin;
		long int A,B,C;
		if(n < 1000001)
			return r[n];
		if(coin[n])
			return coin[n];
		return coin[n] = MAX(n,byte(n/2) + byte(n/3) + byte(n/4));
} 
int main(){

	ull in;
	r[0] = 0;
	r[1] = 1;
	r[2] = 2;
	r[3] = 3;
	for(int i = 4; i < 1000001; i++)
		r[i] = MAX(i, r[i/2] + r[i/3] + r[i/4])
	while(cin>>in)
		cout<<byte(in)<<endl;
}
