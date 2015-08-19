//DATE: 19/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/FENCE1/

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

	int L;
	cin>>L;
	while(L){
		float _2pi = 2 * M_PI;
		float ans = L * L / _2pi;
		ans = floor(ans*100 + 0.5)/100;
		printf("%.2f\n",ans);
		cin>>L;
	}
}
