//DATE: 17/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/HANGOVER/

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <iomanip>  

# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int
# define FOR(i,j,n) for(i = j; i < n; i++)

using namespace std;

int main(){

	double arr[300];
	arr[0] = 0;
	arr[1] = 0.5;
	std::setprecision(2);
	for(int i=2;i<278;i++)
		arr[i] = arr[i - 1] + 1.0/(i+1);
	double in;
	cin>>in;
	while(in){
		int i = 0;
		while(arr[i++] < in);
		cout<<i-1<<" card(s)"<<endl;
		cin>>in;
	}
}
