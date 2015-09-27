//DATE: 27/09/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/AIBOHP/

#include <bits/stdc++.h>

#define gc getchar_unlocked
#define pc putchar_unlocked
# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int

using namespace std;

static unsigned short int DP[6200][6200];

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

int compute(string IN){

    int len = IN.length();
    for(int i = 0; i <= len; i++) {
        for(int j = 0; j <= len; j++) {
            if (i == 0 || j == 0)
                DP[i][j] = 0;
            else {
                if(IN[i - 1] == IN[len - j])
                    DP[i][j] = DP[i - 1][j - 1] + 1;
                else
                    DP[i][j] = MAX(DP[i][j - 1], DP[i - 1][j]);
            }
            //cout<<DP[i][j]<<" ";
        }
        //cout<<endl;
    }

    return len - DP[len][len];
}

int main(){
  int T;
  string B;
  cin>>T;
  while(T--){
    cin>>B;
   fastwrite(compute(B));
  }
}
