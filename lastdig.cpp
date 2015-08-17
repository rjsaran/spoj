//DATE: 17/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/LASTDIG/

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>

int cycle[10] = {1,1,4,4,2,1,1,4,4,2};

using namespace std;

int main(){
	int t, a;
	long long int b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(b == 0)
			cout<<"1"<<endl;
		else 
		{
			int temp = b % cycle[a%10];
			if(temp == 0)
				temp = cycle[a%10];
			int power = 1;
			for(int i = 0; i < temp; i++)
				power *= a % 10;
			cout<<power % 10<<endl;
		}
	}
}
