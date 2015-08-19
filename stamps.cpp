//DATE: 19/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/STAMPS/

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

	int t,friends;
	long long int stamps;
	cin>>t;
	for(int i = 1; i <= t; i++){
		cin>>stamps>>friends;
		vector<int> arr(friends);
		for(int j = 0; j < friends; j++)
			cin>>arr[j];
		sort(arr.rbegin(),arr.rend());
		long long int sum = 0;
		int j;
		for(j = 0; j < friends; j++){
			sum += arr[j];
			if(sum >= stamps)
				break;
		}
		cout<<"Scenario #"<<i<<":\n";
		j == friends ? cout<<"impossible\n"<<endl :  cout<<j + 1<<"\n"<<endl;
	}	
}
