//DATE: 23/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/AGGRCOW/

#include <bits/stdc++.h>

# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int
# define FOR(i,j,n) for(i = j; i < n; i++)

using namespace std;

lli pascal(int n, int m){

    if(m > n-m) m = n-m;
    lli ans = 1; 
    for(int i = 0; i < m; i++) 
        ans = ans * (n - i) / (i + 1);
    
    return ans;
}

int main(){

    int T, n, k;
    
    scanf("%d", &T);
    
    while(T--){
        scanf("%d%d", &n, &k);
        printf("%lld\n", pascal(n-1,k-1));
    }
    
    return 0;
}
