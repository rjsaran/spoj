//DATE: 22/09/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/MIXTURES/

#include <bits/stdc++.h>

#define gc getchar_unlocked
#define pc putchar_unlocked
# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int

using namespace std;
int N;
ull memo[101][101];

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

int csum(int arr[], int i, int j){
    int ans = 0;
    for(int k = i ; k <= j; k++){
        ans += arr[k] % 100;
    }
    return ans % 100;
}

ull break_it(int arr[], int i, int j){
    if(memo[i][j] != -1){
        return memo[i][j];
    }
    if(i == j) {
       return memo[i][j] = 0;
    }
    if(i == j - 1) {
        return memo[i][j] = arr[i] * arr[j];
    }
    ull min = ULLONG_MAX;
    for(int k = i; k < j; k++){
        ull temp = break_it(arr, i, k) + break_it(arr, k + 1, j) + csum(arr, i, k) * csum(arr, k + 1, j);
        min = MIN(min, temp);
    }
    return memo[i][j] = min;
}
int main(){
  while(cin>>N){
    int arr[N];
      memset(memo, -1, sizeof memo);
      for(int i = 0; i < N; i++){
        arr[i] = fastread();
      }
      printf("%llu\n", break_it(arr, 0, N - 1));
  }
}
