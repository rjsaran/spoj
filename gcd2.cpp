//DATE: 22/09/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/GCD2/

#include <bits/stdc++.h>

#define gc getchar_unlocked
#define pc putchar_unlocked
# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int

using namespace std;

int cmod(int A, string B){
  int len = B.length();
  int forward = 0;
  for(int i = 0; i < len; i++){
    int mool = B[i] - '0';
    if(forward)
      mool = forward * 10 + mool;
    forward = mool % A;
  }
  return forward;
}

int gcd(int A, int B){
  if(B == 0)
    return A;
  else 
    return gcd(B, A % B);
}

int main(){
  int T, A;
  string B;
  cin>>T;
  while(T--){
    cin>>A;
    cin>>B;
    if(A == 0)
      cout<<B<<endl;
    else {
      int mod = cmod(A, B);
      cout<<gcd(A, mod)<<endl;
    }
  }
}
