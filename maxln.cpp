//DATE: 20/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/MAXLN/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <string>
#include <iomanip>

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
	for(int i =1; i <= t; i++){
		cin>>n;
		lli ans = 4 * n * n;
		cout<<"Case "<<i<<": "<<ans<<".25"<<endl;
	}
}