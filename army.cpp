//DATE: 19/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/ARMY/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <string>

# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int
# define FOR(i,j,n) for(i = j; i < n; i++)

using namespace std;

int main(){

	int t;
	cin>>t;
	lli NG, NM;
	vector<int> vecng,vecnm;
	string line;
	while(t--){
		getline(cin,line);
		cin>>NG>>NM;
		vecng.resize(NG);
		vecnm.resize(NM);
		for(int i = 0; i < NG; i++)
			cin>>vecng[i];
		for(int i = 0; i < NM; i++)
			cin>>vecnm[i];
		sort(vecng.rbegin(),vecng.rend());
		sort(vecnm.rbegin(),vecnm.rend());
		int i = 0, j = 0;
		int nglen = vecng.size();
		int nmlen = vecnm.size();
		while(i < nglen && j < nmlen){
			if(vecng[i] >= vecnm[j])
				j++;
			else i++;
		}
		if(j == nmlen)
			cout<<"Godzilla"<<endl;
		else if(i == nglen)
			cout<<"MechaGodzilla"<<endl;
	}	
}