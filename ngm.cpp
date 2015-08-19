//DATE: 19/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/NGM/

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

	ull n;	
	cin>>n;
	if(n%10 != 0)
		cout<<"1\n"<<n%10<<endl;
	else cout<<"2"<<endl;
}