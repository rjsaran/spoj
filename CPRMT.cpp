//DATE: 13/10/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/CPRMT/

# include <bits/stdc++.h>
# define MIN(a,b) a<b ? a : b;

using namespace std;

int main(){
  string A, B;
  int len1, len2;
  while(cin>>A && cin>>B){
    int hash1[26] = {0};
    int hash2[26] = {0};
    len1 = A.length();
    len2 = B.length();
    for(int i = 0; i < len1; i++)
      hash1[A[i] - 'a']++;
    for(int i = 0; i < len2; i++)
      hash2[B[i] - 'a']++;
    for(int i = 0; i < 26; i++){
      int min = MIN(hash2[i], hash1[i]);
      while(min--)
        printf("%c", i + 'a');
    }
    printf("\n");
  }
}
