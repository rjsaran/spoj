//DATE: 14/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/CANDY/

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	int N;
	cin>>N;
	while(N != -1){
		int arr[N];
		int sum = 0;
		for(int i = 0; i < N; i++)
		{
			cin>>arr[i];
			sum += arr[i];
		}
		int dis = sum / N;
		if(dis * N == sum)
		{
			int ans = 0;
			for (int i = 0; i < N; i++)
				if(dis > arr[i])
					ans += dis -arr[i];
			cout<<ans<<endl;
		}
		else
			cout<<"-1"<<endl;
		cin>>N;
	}
}
