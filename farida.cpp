//DATE: 29/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/FARIDA

#include <bits/stdc++.h>


# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int
# define FOR(i,j,n) for(i = j; i < n; i++)


using namespace std;

int main(){
	int t, n;
	scanf("%d", &t);
	for(int j = 1; j <= t; j++){
		scanf("%d", &n);
		if(n == 0)
			printf("Case %d: 0\n", j);
		else {
			lli arr[n];
			lli A,B;
			for(int i = 0; i < n; i++)
				scanf("%lld", &arr[i]);
			B = 0;
			A = arr[0];
			lli temp;
			for(int i = 2; i <= n; i++){
				temp = A;
				A = max(arr[i - 1] + B, A);	
				B = temp;		
			}
			printf("Case %d: %lld\n", j, A);
		}
	}
}