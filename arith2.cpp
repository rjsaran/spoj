//DATE: 21/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/ARITH2/

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>

# define MAX(a,b) a>b ? a : b;
# define ull unsigned long long int

using namespace std;

int main(){

	int t;
	string line;
	cin>>t;
	while(t--){
		getline(cin,line);
		ull n,ans;
		cin>>ans;
		char op;
		while(1)
		{
			cin>>op;
			if(op == '=')
				break;

			cin>>n; 

			if(op == '+')
				ans += n;
			if(op == '-')
				ans -= n;
			if(op == '*')
				ans *= n;
			if(op == '/')
				ans /= n;
			if(op == '%')
				ans %= n;
		}
		cout<<ans<<endl;
	}
}
