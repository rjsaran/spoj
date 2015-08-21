//DATE: 21/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/NY10A

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <unordered_map>

# define MAX(a,b) a>b ? a : b;
# define ull unsigned long long int

using namespace std;

int main(){

	int t,j;
	map <char, int> TH;
	TH['H'] = 1;
	TH['T'] = 0;
	string in;
	cin>>t;
	while(t--){
		map <int, int> arr;
		cin>>j;
		cin>>in;
		int out = 0;
		out = ((((out + TH[in[0]]) * 2) + TH[in[1]]) * 2) + TH[in[2]];
		arr[out]++;
		for(int i = 3; i < 40; i++){
			out = out * 2 + TH[in[i]];
			out %= 8;
			arr[out]++;
		}
		cout<<j<<" ";
		for(int i = 0; i < 8; i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
}