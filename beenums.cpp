//DATE: 20/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/BEENUMS/

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

	ull N,ans,_sqrt;
	cin>>N;
	while(N != -1){
		ull mool = 9 + (12 * (N - 1));
		_sqrt = sqrt(mool);
		ans = (_sqrt - 3 )% 6;
		(_sqrt * _sqrt == mool) ? ans % 6 ? cout<<"N"<<endl : cout<<"Y"<<endl : cout<<"N"<<endl;
		cin>>N;
	}
}