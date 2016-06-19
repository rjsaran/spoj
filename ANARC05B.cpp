//DATE: 18/06/2016
//Author: Ramjeet Saran
//http://www.spoj.com/problems/ANARC05B/


// A MERGE SORT APPLICATION

#include <bits/stdc++.h>

# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int
# define FOR(i,j,n) for(i = j; i < n; i++)

using namespace std;

int main(){
	int N1, N2, i, j;
	scanf("%d", &N1);
	while(N1 != 0) {
		int arr1[N1];
		for(i = 0; i < N1; i++) {
			scanf("%d", &arr1[i]);
		}
		scanf("%d", &N2);
		int arr2[N2];
		for(j = 0; j < N2; j++) {
			scanf("%d", &arr2[j]);
		}
		i = 0;
		j = 0;
		int sum1 = 0, sum2 = 0;
		lli final_sum = 0;
		while(i < N1 && j < N2) {
			if(arr1[i] < arr2[j]) {
				sum1 += arr1[i++];
			} else if(arr1[i] > arr2[j]) {
				sum2 += arr2[j++];
			} else {
				final_sum += max(sum1, sum2) + arr1[i];
				sum1 = 0;
				sum2 = 0;
				i++;
				j++;
			}	
		}
		while(i < N1) {
			sum1 += arr1[i++];
		}
		while(j < N2) {
			sum2 += arr2[j++];
		}
		final_sum += max(sum1, sum2);
		printf("%lld\n", final_sum);
		scanf("%d", &N1);
	}
}
