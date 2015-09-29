//DATE: 29/09/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/HOTELS/

#include <bits/stdc++.h>

#define gc getchar_unlocked
#define pc putchar_unlocked
# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int

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
  int N, i, j;
  ull M, current_max, max = 0;
  N = fastread();
  cin>>M;
  int arr[N];
  for(int i = 0; i < N; i++)
    arr[i] = fastread();
  i = 0;
  j = 0;
  current_max = max = 0;
  while(j < N){
    current_max += arr[j];
    while(current_max > M && i < j)
      current_max -= arr[i++];
    if(current_max <= M)
      max = MAX(max, current_max);
    j++;
  }
  cout<<max<<endl;
}
