//DATE: 12/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/FCTRL/

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	long int t, N, five, ans;
	cin>>t;
	while(t--){
		ans = 0;
		five = 5;
		cin>>N;
		while(N/five > 0){
			ans += N/five;
			five *= 5;
		}	
	 cout<<ans<<endl;
	}
}
