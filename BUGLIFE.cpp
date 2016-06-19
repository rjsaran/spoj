//DATE: 16/06/2016
//Author: Ramjeet Saran
//http://www.spoj.com/problems/BUGLIFE/

// ------ SOLUTION ----- //
// check if graph is Biparite or not //

 
# include <bits/stdc++.h>

# define gc getchar_unlocked
# define pc putchar_unlocked
# define li long  int
# define lli long long int

using namespace std;

li fastRead() {

  char sign = '\0', c = gc();
  lli ret = 0;
  
  while((c < '0' ||c > '9') && c != '-') {
		c = gc();
	}
  if(c == '-') {
    sign = '1';
    c = gc();
  }
  while(c >= '0' && c <= '9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  
  if(sign) {
		ret =- ret;
  }
  return ret;
}

void fastWrite(li inp) {
  lli a = (inp < 0) ? -inp : inp;
  char snum[20];
  int i = 0;
  
  do
  {
    snum[i++] = a % 10 + 48;
    a = a / 10;
  } while(a != 0);

  if(inp < 0) {
    snum[i++] = '-';
  }
  i--;

  while(i >= 0) {
   pc(snum[i--]);
  }
  pc('\n');
}

bool check_for_bipartite(vector < list<li> > graph, li N) {
	vector<int> color(N + 1, 0);
	queue<li> Q;
	for(li i = 1; i <= N; i++) {
		if(color[i] == 0) {
			color[i] = 1;
			Q.push(i);	
		}
		while(!Q.empty()) {
			li V = Q.front();
			Q.pop();
			list<li>::iterator itr;
			for(itr = graph[V].begin(); itr != graph[V].end(); itr++) {
				if(color[*itr] == 0) {
					color[*itr] = 0 - color[V];
					Q.push(*itr);
				}
				if(color[*itr] == color[V]) {
					return false;
				}
			}
		}
	}

	return true;
}

int main(){

	li T, N, M;
	cin>>T;
	
	for(li i = 1; i <= T; i++) {
		N = fastRead();
		M = fastRead();
		li node1,node2;
		vector < list<li> > graph;
		graph.clear();
		graph.resize(N + 1);
		for(li j = 0; j < M; j++){
			node1 = fastRead();
			node2 = fastRead();
			graph[node1].push_back(node2);
			graph[node2].push_back(node1);
		}
		printf("Scenario #%ld:\n", i);
		if(check_for_bipartite(graph, N)) {
			printf("No suspicious bugs found!\n");
		} else {
			printf("Suspicious bugs found!\n");
		}
	}
}
