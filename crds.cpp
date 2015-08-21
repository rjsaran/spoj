//DATE: 20/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/CRDS/

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
	lli n;
	cin>>t;
	while(t--){
		cin>>n;
		lli ans = (3 * (( (n * (n - 1) ) / 2 ) % 1000007)) % 1000007;
		ans = ans + ( 2 * n ) % 1000007 ;
		cout<<ans%1000007<<endl;
	}
}