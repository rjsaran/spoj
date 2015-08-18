//DATE: 17/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/ABSYS/

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

	ull t;
	string input;
	cin>>t;
	getline(cin, input);
	int plus, equal, machula;
	while(t--){
		getline(cin, input);
		getline(cin, input);
		plus = input.find("+");
		equal = input.find("=");
		machula = input.find("machula");
		int len = input.length();
		if(machula < plus)
			cout<<to_string(stoi(input.substr(equal + 1, len)) - stoi(input.substr(plus + 1, equal - 1)))<<input.substr(plus - 1, len)<<endl;
		else if(machula < equal)
			cout<<input.substr(0, plus + 2)<<to_string(stoi(input.substr(equal + 1, len)) - stoi(input.substr(0, plus - 1)))<<input.substr(equal - 1, len-1)<<endl;
		else 
			cout<<input.substr(0, equal + 2)<<to_string(stoi(input.substr(0, plus - 1)) + stoi(input.substr(plus + 1, equal - 1)))<<endl;
	}
}
