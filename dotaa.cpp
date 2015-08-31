//DATE: 31/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/DOTAA/

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
  int T, N, M, D, C;
  float H;
  T = fastread();
  while(T--){
    N = fastread();
    M = fastread();
    D = fastread();
    C = 0;
    for(int i = 0; i < N; i++){
      scanf("%f", &H);
      C += ceil(H / D) - 1;
    }
    C >= M ? printf("YES\n") : printf("NO\n");
  }
}
