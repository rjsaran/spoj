//DATE: 25/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/BITMAP/

#include <bits/stdc++.h>
#include <queue>

# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int
# define FOR(i,j,n) for(i = j; i < n; i++)
#define INF 1000

using namespace std;
int dirx[4] = {-1, 0, 0, 1};
int diry[4] = {0, -1, 1, 0};
int arr[185][185];

int bfs(int n, int m){
	queue< pair <int, int > > que;
	pair<int, int> temp;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(arr[i][j] == 0){
				que.push(pair<int , int>(i, j));
			}
	while(!que.empty()){
		temp = que.front();
		que.pop();
		int xd, yd;
		int x = temp.first;
		int y = temp.second;
		for(int i = 0; i < 4; i++){
			xd = x + dirx[i];
			yd = y + diry[i];
			if(xd >= 0 && yd >=0 && xd < n && yd < m && arr[x][y] + 1 < arr[xd][yd]){
				arr[xd][yd] = arr[x][y] + 1;
				que.push(pair<int , int>(xd, yd));
			}
		}
	}
}

int main(){

	int t, n ,m;
	string line;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n , &m);
		for(int  i = 0; i < n ; i++){
			cin>>line;
			for(int j = 0; j < m; j++)
				if(line[j] == '0')
					arr[i][j] = INF;
				else arr[i][j] = 0;
		}
		bfs(n, m);
		for(int  i = 0; i < n ; i++){
			for(int j = 0; j < m; j++){
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
	}
}
