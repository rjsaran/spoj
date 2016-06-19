//DATE: 19/06/2016
//Author: Ramjeet Saran
//http://www.spoj.com/problems/SILVER/


#include <bits/stdc++.h>

# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int
# define FOR(i,j,n) for(i = j; i < n; i++)

using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	while(N) {
		int res = (int) floor(log2(N));
		printf("%d\n", res);
		scanf("%d", &N);
	}
}
