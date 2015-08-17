//DATE: 17/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/CANDY3/

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int main(){
	long long int t, N;
	cin>>t;
	while(t--){
		long long int ans = 0;
		long long int a;
		cin>>N;
		
		for(int i = 0; i < N; i++){
			cin>>a;
			ans = (ans + a % N) % N;
		}
		if(ans == 0)
			cout<<"YES"<<endl;
		else	cout<<"NO"<<endl;
	}
}
