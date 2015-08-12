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
	int t;
	double A,B;
	cin>>t;
	while(t--){
		cin>>A>>B;
		int steps = 0;
		while(log2(A) != (int)log2(A)){	
			A = ((int)A)/2;
			steps++;
		}
		if(A<B) steps += log2(B) - log2(A);
		else steps += log2(A) - log2(B);

		cout<<steps<<endl;
	}
}
