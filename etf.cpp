//DATE: 28/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/ETF/

#include <bits/stdc++.h>
#include <queue>

# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int
# define FOR(i,j,n) for(i = j; i < n; i++)
# define MAX 1000000

using namespace std;
int prime[MAX + 1];

void calculate_sieve(){
	int j;
	int limit = sqrt(MAX);
	prime[0] = 1;
	prime[1] = 1;
	for(int i = 2; i <= MAX; i++){
		if(prime[i] == 0){
			prime[i] = i;
			for(j = 2; j * i <= MAX; j++)
				prime[j * i] = i;
		}
	}
}

lli etf(int n){
	lli ans = n;
	map<lli, bool> Hash;
	int p;
	while(n > 1){
		p = prime[n];
		if(!Hash[p]){
			ans -= ans / p;
			Hash[p] = true;
		}
		n = n / p;
	}
	return ans;
}
int main(){

	int t, n;
	calculate_sieve();
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		//printf("%d\n",prime[828232]);
		printf("%lld\n", etf(n));
	}	
}
