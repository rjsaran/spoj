//DATE: 21/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/EASYPROB/

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

int calculate(int n){

	if(n == 0){
		cout<<"0";
	}
	else if(n == 1)
		cout<<"";
	else if(n == 2)
		cout<<"2";
	else{
		while(n){
			int _log2 = log2(n);
			int power = 1<<_log2;
			n = n - power;
			cout<<"2(";
			calculate(_log2);
			cout<<")+";
		}
		cout<<'\b';
	}
}
int main(){

	int n = 16385;
	calculate(n);
	cout<<"\b\n";
}

// 137=2(2(2)+2+2(0))+2(2+2(0))+2(0)
// 1315=2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)
// 73=2(2(2)+2)+2(2+2(0))+2(0)
// 136=2(2(2)+2+2(0))+2(2+2(0))
// 255=2(2(2)+2+2(0))+2(2(2)+2)+2(2(2)+2(0))+2(2(2))+2(2+2(0))+2(2)+2+2(0)
// 1384=2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2)+2(2(2)+2(0))+2(2+2(0))
//16385=2(2(2+2(0))+2(2)+2)+2(0)
