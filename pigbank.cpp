//DATE: 31/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/PIGBANK/

#include <bits/stdc++.h>

#define gc getchar_unlocked
#define pc putchar_unlocked
# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int
# define FOR(i,j,n) for(i = j; i < n; i++)
#define LIMIT INT_MAX - 50000

using namespace std;


void fastwrite(int inp){
  int a=(inp<0)?-inp:inp;
  char snum[20];
  int i=0;
  do
  {
    snum[i++]=a%10+48;
    a=a/10;
  }while(a!=0);
  if(inp<0)
  snum[i++]='-';
  i--;
  while(i>=0)
  pc(snum[i--]);
  pc('\n');
}

int fastread()
{
  char sign='\0',c=gc();
  int ret=0;
  while((c<'0'||c>'9')&&c!='-'){c=gc();}
  if(c=='-'){
    sign='1';
    c=gc();
  }
  while(c>='0'&&c<='9'){
    ret=10*ret+c-48;
    c=gc();
  }
  if(sign)ret=-ret;
  return ret;
}

int main(){
  int T, E, F, N, temp;
  T = fastread();
  int * V, * W, * DP;
  while(T--){
    E = fastread();
    F = fastread();
    N = fastread();
    V = new int[N];
    W = new int[N];
    for(int i = 0; i < N ; i++){
      V[i] = fastread();
      W[i] = fastread();
    }
    DP = new int[F - E + 1];
    DP[0] = 0;
    for(int C = 1; C <= F - E; C++){
      DP[C] = LIMIT;
      for(int i = 0; i < N; i++){
        temp = C >= W[i] ? DP[C - W[i]] + V[i]: LIMIT;
        DP[C] = MIN(DP[C], temp);
      }
    }
    if(DP[F - E] == LIMIT)
      printf("This is impossible.\n");
    else
      printf("The minimum amount of money in the piggy-bank is %d.\n", DP[F - E]);
  }
}
