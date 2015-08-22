//DATE: 21/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/PT07Z

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <list>
#include <unordered_map>

using namespace std;

vector < list<int> > tree;
vector < int > heights;
vector< bool> visited;
int diameter = 0;

int compute_heights(int i){

	visited[i] = true;

	if(heights[i])
		return heights[i];

	if(tree[i].size() == 0){
		heights[i] =  0;
		return 0;
	}

	list<int>::iterator itr;
	int height = 0, _max1 = -1, _max2 = -1;
	for(itr = tree[i].begin(); itr != tree[i].end(); itr++){
		int height = compute_heights(*itr);
		if(height > _max1){
			_max2 = _max1;
			_max1 = height;
		}
		else if(height > _max2)
			_max2 = height;
	}

	diameter = max(diameter, _max1 + _max2 + 2);
	heights[i] = _max1 + 1;
	return heights[i];
}
int main(){
	int N,node1,node2;
	cin>>N;

	tree.resize(N + 10);
	visited.resize(N+10);
	heights.resize(N+10);

	for(int i = 0; i < N - 1; i++){
		cin>>node1>>node2;
		tree[node1].push_back(node2);
	}
	for(int i = 1; i <= N; i++){
		if(!visited[i])							
			compute_heights(i);
	}
	int _max = 0;
	cout<<diameter<<endl;
}