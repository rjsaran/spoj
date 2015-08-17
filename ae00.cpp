//DATE: 17/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/AE00/

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int main(){
	int N;
	cin>>N;
	int ans = 0;
	for(int i = 1; i <= sqrt(N); i++)
		ans += (N/i) - (i - 1);
	cout<<ans<<endl;
}
