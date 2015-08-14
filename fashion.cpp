//DATE: 14/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/FASHION/

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#define MIN(a,b) b<a?b:a;

using namespace std;

int main(){
	int t,N,a;
	int arr1[11] = {0};
	int arr2[11] = {0};
	cin>>t;

	while(t--){
		cin>>N;
		for(int i = 0; i < N; i++){
			cin>>a;
			arr1[a]++;
		}
		for(int i = 0; i < N; i++){
			cin>>a;
			arr2[a]++;
		}
		long int ans = 0; 
		int i=0,j=0;
		while(1)
		{
			while(arr1[i] == 0)
				i++;
			while(arr2[j] == 0)
				j++;
			if (i > 10)
				break;
			int min = MIN(arr1[i],arr2[j]);
			ans += min * i * j;
			arr1[i] -= min;
			arr2[j] -= min;
		}
		cout<<ans<<endl;
	}
}
