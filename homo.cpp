//DATE: 24/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/HOMO/

#include <bits/stdc++.h>

# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int
# define FOR(i,j,n) for(i = j; i < n; i++)

using namespace std;


int main(){

	char cmd[7];
	int N;
	lli v;
	int homo = 0, hetro = 0;
	map<lli, lli> Hash;
	scanf("%d", &N);
	while(N--){

		scanf("%s%lld", cmd, &v);
		if(cmd[0] == 'i'){
			if(Hash[v] == 0)
				hetro++;
			else if(Hash[v] == 1)
				homo++;
			Hash[v]++;
		}
		else {
			if(Hash[v] > 0){
				if(Hash[v] == 1)
					hetro--;
				else if(Hash[v] == 2)
					homo--;
				Hash[v]--;
			}
		}
		if(homo >= 1 && hetro >= 2)
			printf("both\n");
		else if(homo >= 1)
			printf("homo\n");
		else if(hetro >= 2)
			printf("hetero\n");
		else 
			printf("neither\n");
	}
}
