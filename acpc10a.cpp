//DATE: 14/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/ACPC10A/

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	int A, B, C;
	cin>>A>>B>>C;
	while(A || B || C){
		if ((B - A) == (C - B))
			cout<<"AP "<<(2 * C - B)<<endl;
		else 
			cout<<"GP "<<(C * C / B)<<endl;

		cin>>A>>B>>C;
	}

}