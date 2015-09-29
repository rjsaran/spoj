//DATE: 29/09/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/FACEFRND/

#include <bits/stdc++.h>

#define gc getchar_unlocked
#define pc putchar_unlocked
# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int

using namespace std;

bool DF[101];
bool FOF[10010];

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
  int N, M, df, fof, ans = 0;
  N = fastread();
  while(N--){
   df = fastread();
   DF[df] = true; //put in direct frnd array
   if(FOF[df]){
      FOF[df] =false;
      ans--;
  }// if a direct frnd then remove from fof array
   M = fastread();
   while(M--){
    fof = fastread();
    if(!DF[fof] && !FOF[fof]){
      FOF[fof] = true;
      ans++;
    }
   }
  }
  fastwrite(ans);
}
