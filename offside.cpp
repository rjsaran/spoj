//DATE: 20/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/OFFSIDE/

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

	int A, B;
	cin>>A>>B;
	while(A){
		int temp;

		int min_attacker = 10001, min_defender = 10001, sec_min_defender = 100002;
		for(int i = 0; i < A; i++)
		{
			cin>>temp;
			if(temp < min_attacker)
				min_attacker = temp;
		}
		for(int i = 0; i < B; i++)
		{
			cin>>temp;
			if(temp < min_defender){
				int swap = min_defender;
				min_defender = temp;
				sec_min_defender = swap;
			}
			else if(temp < sec_min_defender)
				sec_min_defender = temp;
		}
		//cout<<min_attacker<<" "<<min_defender<<" "<<sec_min_defender<<endl;
		if(min_attacker < sec_min_defender)
			cout<<"Y"<<endl;
		else cout<<"N"<<endl;
		cin>>A>>B;
	}
}