//DATE: 18/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/CANTON/

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
# define FOR(i,j,n) for(int i = j; i < n; i++)

using namespace std;

int main(){

	int t;
	lli n;
	cin>>t;
	while(t--){
		cin>>n;
		int i = 1;
		while(i*(i+1)/2 < n)
			i++;
		int X , Y;
		if(i&1){
			X = i - (i*(i+1)/2 - n);
			Y = i - (n - i*(i-1)/2 - 1);
		}
		else {
			X = i - (n - i*(i-1)/2 - 1);
			Y = i - (i*(i+1)/2 - n);
		}
		cout<<"TERM "<<n<<" IS "<<Y<<"/"<<X<<endl;
	}	
}
