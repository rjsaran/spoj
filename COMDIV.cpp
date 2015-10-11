//DATE: 11/10/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/COMDIV/

# include <bits/stdc++.h>

# define gc getchar_unlocked
# define pc putchar_unlocked
# define li long int
# define RWTYPE long int

using namespace std;

RWTYPE fastread(){

  char sign = '\0', c = gc();
  RWTYPE ret = 0;
  while((c < '0' ||c > '9') && c != '-'){
		c = gc();
	}
  if(c == '-'){
    sign = '1';
    c = gc();
  }
  while(c >= '0' && c <= '9'){
    ret = 10 * ret + c - 48;
    c = gc();
  }
  if(sign)
		ret =- ret;
  return ret;
}

RWTYPE fastwrite(RWTYPE inp) {
  RWTYPE a = (inp < 0) ? -inp : inp;
  char snum[20];
  int i = 0;
  do
  {
    snum[i++] = a % 10 + 48;
    a = a / 10;
  }while(a != 0);

  if(inp < 0)
    snum[i++] = '-';
  i--;

  while(i >= 0)
    pc(snum[i--]);
  pc('\n');
}

li gcd(li A, li B) {
  if(B == 0)
    return A;
  return gcd(B, A % B);
}

li num_div(int A) {
  int count = 0;
  int _sqrt = sqrt(A);
  for(int i = 1; i <= _sqrt; i++)
    if(A % i == 0)
      count += 2;
  if(_sqrt * _sqrt == A)
    count--;
  return count;
}

int main(){
  int t; 
  li A, B;
  t = fastread();
  while(t--){
    A = fastread();
    B = fastread();
    fastwrite(num_div(gcd(A, B)));
  }
}
