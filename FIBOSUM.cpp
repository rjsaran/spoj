//DATE: 19/06/2016
//Author: Ramjeet Saran
//http://www.spoj.com/problems/FIBOSUM/

// DP, Fibonacci using matrix multiplication

#include <bits/stdc++.h>

# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int
# define FOR(i,j,n) for(i = j; i < n; i++)
# define MOD 1000000007

using namespace std;

void multiply(lli matrix1[2][2], lli matrix2[2][2]) {
	lli x = (((matrix1[0][0] * matrix2[0][0]) % MOD) + ((matrix1[0][1] * matrix2[1][0]) % MOD)) % MOD;
	lli y = (((matrix1[0][0] * matrix2[0][1]) % MOD) + ((matrix1[0][1] * matrix2[1][1]) % MOD)) % MOD;
	lli z = (((matrix1[1][0] * matrix2[0][0]) % MOD) + ((matrix1[1][1] * matrix2[1][0]) % MOD)) % MOD;
	lli p = (((matrix1[1][0] * matrix2[0][1]) % MOD) + ((matrix1[1][1] * matrix2[1][1]) % MOD)) % MOD;
	
	matrix1[0][0] = x;
	matrix1[0][1] = y;
	matrix1[1][0] = z;
	matrix1[1][1] = p;
}

void fib(lli matrix[2][2], lli N) {
	if(N == 0 || N ==1) return;
	lli x[2][2] = {{1, 1}, {1, 0}};
	
	fib(matrix, N / 2);
	multiply(matrix, matrix);
	if(N & 1) {
		multiply(matrix, x);
	}
}
lli calculate(lli N) {
	if(N == 0) return 0;
	
	lli matrix[2][2] = {1, 1, 1, 0};
	fib(matrix, N - 1);
	return matrix[0][0];
}

int main() {
	lli T, N, M;
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld%lld", &N, &M);
        lli result = calculate(M + 2) - calculate(N + 1);
		if(result < 0) {
			result += MOD;
		}
		cout<<result<<endl;
	}
}
