//DATE: 20/06/2016
//Author: Ramjeet Saran
//http://www.spoj.com/problems/FAVDICE/

// DP, Fibonacci using matrix multiplication

#include <bits/stdc++.h>

# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int
# define FOR(i,j,n) for(i = j; i < n; i++)

using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--) {
        float N, BASE;
        cin>>N;
        BASE = N;
        float ans = 1;
        while(N-- > 1){
            ans += float((BASE * 1 / N));
        }
        printf("%.2f\n", ans);
    }
    return 0;
}