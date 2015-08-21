//DATE: 21/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/HPYNOS/

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <unordered_map>
#include <iomanip>  

# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int
# define FOR(i,j,n) for(i = j; i < n; i++)

using namespace std;

int square[10] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};

lli digit_sum(lli n){
	lli sum = 0;
	while(n){
		sum += square[n%10];
		n = n / 10;
	}
	return sum;
}
int main(){

	unordered_map <lli, bool> hash;
	lli N;
	cin>>N;
	lli count = 0;
	while(N != 1){
		if(hash[N] == 1){
			cout<<"-1"<<endl;
			break;
		}
		hash[N] = 1;
		N = digit_sum(N);
		count++;
	}
	if(N == 1)
		cout<<count<<endl;
}
