//DATE: 20/06.2016
//Author: Ramjeet Saran
//http://www.spoj.com/problems/ACPC10D/

// DYNAMIC PROGRAMMING

#include <bits/stdc++.h>

# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int
# define FOR(i,j,n) for(i = j; i < n; i++)

using namespace std;


int main() {
	int N, counter = 1;
	scanf("%d", &N);
	while(N) {
		lli a, b, c, i = 2;
		lli left, mid, right;
		scanf("%lld%lld%lld", &a, &b, &c);
		c += b;
		scanf("%lld%lld%lld", &left, &mid, &right);
		left += b;
		lli newMid = min(left, min(b, c)) + mid;
		right += min(newMid, min(b, c));
		mid = newMid;
		while(i < N) {
		    scanf("%lld%lld%lld", &a, &b, &c);
			lli newLeft = min(left, mid) + a;
			lli newMid = min(left, min(mid, min(right, newLeft))) + b;
			lli newRight = min(mid, min(newMid, right)) + c;
			left = newLeft;
			mid = newMid;
			right = newRight;
			i++;
		}
		cout<<counter<<". "<<mid<<endl;
		scanf("%d", &N);
		counter++;	
	}
}
