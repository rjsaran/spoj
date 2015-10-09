//DATE: 09/10/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/PIR/

#include <bits/stdc++.h>
#include <queue>

#define gc getchar_unlocked
#define pc putchar_unlocked
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int

using namespace std;

ull fastread()
{
  char sign = '\0', c = gc();
  ull ret = 0;
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

int main(){

	int t;
  double u, v, w, W, V, U;
  double A, B, C;
  double volume;
  t = fastread();
  while(t--){
    scanf("%lf%lf%lf%lf%lf%lf", &u, &v, &w, &W, &V, &U);
    A = v * v + w * w - U * U;
    B = w * w + u * u - V * V;
    C = u * u + v * v - W * W;
    volume =  sqrt((4 * u * u * v * v * w * w) - (u * u * A * A) - (v * v * B * B) - (w * w * C * C) + (A * B * C)) / 12;
    printf("%.4lf\n", volume);
  }
}
