//DATE: 12/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/ADDREV/

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	long int t;
	cin>>t;
	while(t--){
		string A, B;
		long long int lenA, lenB, out = 0;
		cin>>A>>B;
		lenA = A.length();
		lenB = B.length();
		long long int i = 0, j = 0;
		long long int c = 0, mool;
		while(i < lenA && j < lenB){
			mool = c + (A[i] - '0') + (B[i] - '0');
			out = out * 10 + mool % 10;
			c = mool > 9 ? 1 : 0 ; 
			i++;
			j++;
			//cout<<out<<" "<<i+1<<endl;
		}
		while(i < lenA)
			{
				mool = c + (A[i] - '0');
				out = out * 10 + mool % 10;
				c = mool > 9 ? 1 : 0 ;
				i++;
			}
		while(j < lenB)
			{
				mool = c + (B[j] - '0');
				out = out * 10 + mool % 10;
				c = mool > 9 ? 1 : 0 ;
				j++;
			}
		if(c == 1)
			out = out * 10 + c ;
		cout<<out<<endl;
	}
}
