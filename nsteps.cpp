//DATE: 14/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/NSTEPS/

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int t;
	int x, y;
	cin>>t;
	while(t--){
		cin>>x>>y;
		if(x == y || x == y+2)
			(x & 1) ? cout<< (x + y - 1): cout<<(x + y); 
		else cout<<"No Number";
		cout<<endl;
	}
}
