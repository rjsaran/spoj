//DATE: 17/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/EIGHTS/

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>

# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int
# define FOR(i,j,n) for(i = j; i < n; i++)

using namespace std;

int main(){

	ull t, k;
	cin>>t;
	while(t--){
		cin>>k;
		if(k & 1)
			cout<<500 * ((k + 1) / 2 - 1) + 192<<endl;
		else 
			cout<<500 * (k / 2 - 1) + 442<<endl;
	}
}
