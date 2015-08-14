//DATE: 14/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/SAMER08F/

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;
int arr[101];
void preprocess(){
	arr[0] = 1;
	arr[1] = 1;
	for(int i = 2; i < 101 ; i++)
		arr[i] = (i * i) + arr[i - 1];
}

int main()
{
	int  N;
	preprocess();
	cin>>N;
	while(N){
		cout<<arr[N]<<endl;
		cin>>N;
	}
}
