//DATE: 17/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/TRICOUNT/

#include <iostream>
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

	ull t,n;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<(n * (n + 2) * ((2 * n) + 1)) / 8<<endl;
	}
}
