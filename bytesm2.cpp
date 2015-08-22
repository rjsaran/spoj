//DATE: 22/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/BYTESM2/

#include <bits/stdc++.h>

# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int
# define FOR(i,j,n) for(i = j; i < n; i++)

using namespace std;


int main(){

	int t, N, M, temp;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d",&N, &M);
		int mat[N][M];
		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++)
				scanf("%d", &mat[i][j]);
		for(int i = 1; i < N; i++)
			for(int j = 0; j < M; j++){
				if(j == 0 && j == M - 1)
					temp = mat[i - 1][j];
				else if(j == 0)
					temp = max(mat[i - 1][j], mat[i - 1][j + 1]);
				else if(j == M - 1)
					temp = max(mat[i - 1][j], mat[i - 1][j - 1]);
				else 
					temp = max(mat[i - 1][j + 1], temp = max(mat[i - 1][j], mat[i - 1][j - 1]));
				mat[i][j] += temp;
			}
		int ans = 0; 
		for(int i = 0; i < M; i++)
			ans = max(ans, mat[N - 1][i]);
		printf("%d\n", ans);
	}
}
