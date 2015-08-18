//DATE: 17/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/WILLITST/

#include <iostream>
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

	long long int n;
	cin>>n;
		if((n&(n-1)) == 0)
			cout<<"TAK"<<endl;
		else cout<<"NIE"<<endl;
}
