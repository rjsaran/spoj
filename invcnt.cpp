//DATE: 19/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/INVCNT/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <string>

# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int
# define FOR(i,j,n) for(i = j; i < n; i++)

using namespace std;
lli INV = 0;
void merge(lli *arr, lli l, lli m, lli h){

	lli temp[h - l + 1];
	lli i = l;
	lli j = m + 1;
	lli k = 0;
	while(i <= m && j <= h)
	{
		if(arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else {
			temp[k++] = arr[j++];
			INV += (m - i + 1);
		}
	}
	while(i <= m)
		temp[k++] = arr[i++];
	while(j <= h)
		temp[k++] = arr[j++];

	for(lli i = 0; i < k; i++)
		arr[l + i] = temp[i];
}

void merge_sort(lli * arr, lli l, lli h){
	if(l < h){
		lli mid = l + (h - l) / 2;
		merge_sort(arr, l, mid);
		merge_sort(arr, mid+1, h);
		merge(arr, l, mid, h);
	}
}
int main(){

	lli T,N;
	cin>>T;
	string line;
	while(T--){
		getline(cin,line);
		INV = 0;
		cin>>N;
		lli arr[N];
		for(lli i = 0; i < N; i++)
			cin>>arr[i];
		merge_sort(arr, 0, N-1);
		cout<<INV<<endl;
	}
}