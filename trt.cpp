//DATE: 31/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/TRT/

#include <bits/stdc++.h>

# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int
# define FOR(i,j,n) for(i = j; i < n; i++)

using namespace std;

int main(){
	int N,age;
	scanf("%d", &N);
	int arr[N];
	lli DP[N][N];
	for(int i =  0; i < N; i++)
		scanf("%d", &arr[i]);
	for(int i = 0; i < N; i++)
		DP[i][i] = N * arr[i];
	for(int i = N - 2; i >= 0; i--)
		for(int j = i + 1; j < N; j++){
			age = N - j + i;
			DP[i][j] = max(arr[j] * age + DP[i][j - 1], arr[i] * age +  DP[i + 1][j]);
		}
		printf("%lld\n", DP[0][N - 1]);
}
