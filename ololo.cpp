//DATE: 20/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/OLOLO/

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int main(){
	int N;
	scanf("%d",&N);
	long long int A, ans = 0;
	while(N--){
		scanf("%ld",&A);
		ans = ans ^ A;
	}
	printf("%ld\n",ans);

}
