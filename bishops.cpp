//DATE: 20/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/BISHOPS/

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

	string N;
	while(getline(cin,N)){

		int lenN = N.length();
		int borrow = 1;
		int i = 0;
		if(lenN == 1 && (N[0] == 48 || N[0] == 49))
				cout<<N[0]<<endl;
		else {
			while(i < lenN){
				int mool = (N[lenN - i -1] - '0') - borrow;
				borrow = mool < 0 ? 1: 0;
				N[lenN - i -1] = mool < 0 ? mool + 10 + '0' : mool + '0';
				i++;
			}
			int carry = 0;
			int lenO = 0;
			string out;
			for(i = lenN; i >= 0; i--){
				int mool = (N[i] - '0') + (N[i] - '0') + carry;
				carry = mool > 9 ? 1 : 0;
				out[lenO++] = (mool % 10) +'0';
			}
			if(carry)
				out[lenO++] = '1';

			for(int i = lenO - 1; i > 0; i--)
				cout<<out[i];
			cout<<endl;
		}
		//cin>>N;
	}
}