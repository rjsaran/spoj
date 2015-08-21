//DATE: 20/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/LASTDIG2/

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>

int cycle[10] = {1,1,4,4,2,1,1,4,4,2};

using namespace std;

int main(){
	string a;
	long long int b;
	int t;
	cin>>t;
	while(t--){
		cin>>a>>b;
		int lenA = a.length();
		if(b == 0)
			cout<<"1"<<endl;
		else 
		{
			int x = a[lenA - 1] - '0';
			int temp = b % cycle[x];
			if(temp == 0)
				temp = cycle[x];
			int power = 1;
			for(int i = 0; i < temp; i++)
				power *= x;
			cout<<power % 10<<endl;
		}
	}
}
