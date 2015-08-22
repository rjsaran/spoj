//DATE: 22/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/EDIST/

#include <bits/stdc++.h>

# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int
# define FOR(i,j,n) for(i = j; i < n; i++)

using namespace std;


int main(){

	int t, len1, len2;
	string s1,s2;
	static int mat[2010][2010];
	scanf("%d", &t);
	while(t--){
		cin>>s1>>s2;
		len1 = s1.length();
		len2 = s2.length();
		for(int i = 0; i <= len1; i++)
			mat[i][0] = i;
		for(int i = 0; i <= len2; i++)
			mat[0][i] = i;
		for(int i = 1; i <= len1; i++)
			for(int j = 1; j <= len2; j++)
				mat[i][j] = min(mat[i - 1][j - 1] + (s1[i - 1] != s2[j - 1]), min(mat[i - 1][j], mat[i][j - 1]) + 1);
		cout<<mat[len1][len2]<<endl;
	}
}
