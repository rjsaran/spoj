//DATE: 13/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/FCTRL2/

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;
void fctrl(int n){
	int arr[200] = {0}, len = 0;
	arr[0] = 1;
	len++;
	for(int i = 1; i <= n ; i++){
		int carry = 0;
		for(int j = 0; j < len; j++){
			int temp = arr[j] * i + carry;
			arr[j] = temp % 10;
			carry = temp / 10;
		}
		while(carry > 0){
			arr[len++] = carry % 10;
			carry /= 10;	
		}
	}
	for(int i = len-1; i >= 0 ; i--)
		cout<<arr[i];
}
int main()
{
	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		fctrl(n);
		cout<<endl;
	}
}
