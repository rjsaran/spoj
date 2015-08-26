//DATE: 26/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/EGYPIZZA/

#include <bits/stdc++.h>

# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int
# define FOR(i,j,n) for(i = j; i < n; i++)

using namespace std;


int main(){

	int N;
	char in[4];
	int oneBy4  = 0, oneBy2 = 0, threeBy4 = 0;
	scanf("%d", &N);
	while(N--){
		scanf("%s", in);
		in[0] == '3' ? threeBy4++ : in[2] == '2' ? oneBy2++ : oneBy4++;
	}
	int ans = 0;
	int MIN = min(oneBy4, threeBy4);
	ans += MIN;
	threeBy4 -= MIN;
	oneBy4 -= MIN;
	ans += threeBy4;
	//cout<<ans<<endl;
	float extra = oneBy4 / 2.0;
	float temp = (oneBy2 + floor(extra) ) / 2.0;
	ans += floor(temp);
	if(temp > floor(temp) || extra > floor(extra))
		ans++;
	cout<<ans+1<<endl;
	
}
