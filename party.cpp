//DATE: 29/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/PARTY

#include <bits/stdc++.h>


# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int
# define FOR(i,j,n) for(i = j; i < n; i++)


using namespace std;

int main(){
	int BUG, N;
	string line;
	while(1){
		scanf("%d%d", &BUG, &N);
		if(!BUG)
			break;
		int paisa[N], fun[N];
		int DP[N + 1][BUG + 1];
		for(int i = 0; i < N; i++)
			scanf("%d%d", &paisa[i], &fun[i]);
		for(int i = 0; i <= N; i++){
			for(int j = 0; j <= BUG; j++){
				if(j == 0 || i == 0)
					DP[i][j] = 0;
				else if(j < paisa[i - 1])
					DP[i][j] = DP[i - 1][j];
				else DP[i][j] = MAX(DP[i - 1][j], fun[i - 1] + DP[i - 1][j - paisa[i - 1]]);
			}
		}
		int best = DP[N][BUG];
		int i;
		for(i = BUG; i; i--) 
			if(DP[N][i] < best)
			 break; 
		printf("%d %d\n", i + 1, DP[N][BUG]);
		getline(cin,line);
	}
}