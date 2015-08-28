//DATE: 28/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/QUADAREA/

#include <bits/stdc++.h>

# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int
# define FOR(i,j,n) for(i = j; i < n; i++)

using namespace std;
int main(){
	int t;
	double s, a, b, c, d;
	scanf("%d", &t);
	while(t--){
		scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
		s = (a + b + c + d) / 2.0;
		printf("%.2f\n", sqrt((s - a) * (s - b) * (s - c) * (s - d)));
	}
}
