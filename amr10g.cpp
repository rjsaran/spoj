//DATE: 29/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/AMR10G

#include <bits/stdc++.h>


# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int
# define FOR(i,j,n) for(i = j; i < n; i++)


using namespace std;

int main(){
	int t, n, k;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		ull arr[n];
		for(int i = 0; i < n; i++)
			scanf("%lld", &arr[i]);
		sort(arr, arr + n);
		ull ans = 1000000001;
		for(int i = 0; i <= n - k; i++)
			ans = MIN(ans, arr[i + k - 1] - arr[i]);
		printf("%lld\n", ans);
	}
}