//DATE: 19/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/PT07Y/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <string>
#include <list>

# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int
# define FOR(i,j,n) for(i = j; i < n; i++)

using namespace std;

map<int, bool> visited;
vector < list<int> > graph;

void dfs(int v){
	visited[v] = true;
	//cout<<v<<" ";

	list<int>::iterator itr;
	for(itr = graph[v].begin(); itr != graph[v].end(); itr++){
		if(!visited[*itr])
			dfs(*itr);
	}
}
bool check_for_connected(int N){
	for(int i = 1;i <= N; i++)
		if(!visited[i])
			return false;
	return true;
}
// void printgraph(int N){
// 	for(int i = 1 ; i <= N; i++){	
// 		list<int>::iterator itr;
// 		for(itr = graph[i].begin(); itr != graph[i].end(); itr++)
// 			cout<<i<<" : "<<*itr<<endl;
// 	}
//}
int main(){

	int N,M;
	cin>>N>>M;

	int node1,node2;
	graph.resize(N + 1);
	// graph[1].push_back(5);
	// graph[2].push_back(3);
	// graph[2].push_back(4);
	 for(int i = 0; i < M; i++){
		cin>>node1>>node2;
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}
	if(N-1 != M)
		cout<<"NO"<<endl;
	else {
		//printgraph(N);
		dfs(node1);
		check_for_connected(N) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
	}	
}
