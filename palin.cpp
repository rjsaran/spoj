//DATE: 22/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/PALIN/

#include <bits/stdc++.h>

# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int
# define FOR(i,j,n) for(i = j; i < n; i++)

using namespace std;

void nextpalindrome(string in, lli len){

	lli mid = len / 2;
	bool need_increment = false;
	lli i, j;
	i = mid - 1;
	j = len % 2 ? mid + 1 : mid;
	while(i >= 0 && in[i] == in[j]){
		i--;
		j++;
	}
	if(i < 0 || in[i] < in[j])
		need_increment = true;

	while(i >= 0)
		in[j++] = in[i--]; 

	if(need_increment){
		int carry = 1, mool;
		i = mid - 1;
		if(len % 2){
			mool = in[mid] - '0' + carry;
			carry = mool > 9 ? 1 : 0;
			in[mid] = mool > 9 ? '0' : mool + '0';
			j = mid + 1;
		}
		else j = mid;

		while(i >=0 ){
			mool = in[i] - '0' + carry;
			carry = mool > 9 ? 1 : 0;
			in[i] = mool > 9 ? '0' : mool + '0';
			in[j++] = in[i--];
		}
	}
	cout<<in<<endl;
}

int all999(string in, lli len){
	for(int i = 0; i < len; i++)
		if(in[i] != 57)
			return 0;
	return 1;
}
int main(){

	lli t,len;
	string in;
	scanf("%llu",&t);
	while(t--){
		cin>>in;
		len = in .length();
		if(all999(in, len)){
			cout<<"1";
			for(int i = 0; i < len - 1; i++)
				cout<<"0";
			cout<<"1"<<endl;
		}
		else
			nextpalindrome(in, len);
	}
}
