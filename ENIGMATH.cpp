//DATE: 18/06/2016
//Author: Ramjeet Saran
//http://www.spoj.com/problems/ENIGMATH/

// A GCD / LCM APPLICATION
 
# include <bits/stdc++.h>

# define gc getchar_unlocked
# define pc putchar_unlocked
# define li long int
# define lli long long int

using namespace std;

li gcd(li A, li B) {
  if(B == 0)
    return A;
  return gcd(B, A % B);
}

int main(){
  int T;
  scanf("%d", &T);
  while(T--) {
   li A, B;
   scanf("%ld%ld", &A, &B);
   li GCD = gcd(A, B);
   printf("%ld %ld\n", B / GCD, A / GCD);
  }
}
