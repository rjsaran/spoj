//DATE: 23/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/AGGRCOW/

#include <bits/stdc++.h>

# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int
# define FOR(i,j,n) for(i = j; i < n; i++)

using namespace std;

int arr[100001];
int N, C;

int check(int X){
	int last = arr[0];
	int cows = 1;
	for(int i = 1; i < N; i++){
		if(arr[i]-last >= X){
			cows++;
			if(cows == C)
				return 1;
			last = arr[i];
		}
	}
	return 0;
}

int bsearch(){
	int start = 0;
	int end = arr[N - 1];
	int mid;
	while(start < end){
		mid = start + (end - start) / 2;
		if(check(mid) == 1)
			start = mid + 1;
		else end = mid;
	}
	return start - 1;
}
int main(){

	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &N, &C);
		for(int i = 0; i < N; i++)
			scanf("%d", &arr[i]);
		sort(arr, arr+N);
		printf("%d\n", bsearch());
	}
	
}
