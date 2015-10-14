//DATE: 14/10/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/DANGER/

# include <bits/stdc++.h>
# include <cmath>
# define gc getchar_unlocked
# define pc putchar_unlocked
# define RWTYPE long int

using namespace std;

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

int main(){
  string in;
  double n;
  int _log, ans;
  cin>>in;
  while(1){
    if(in[0] == '0' && in[1] == '0' && in[3] == '0')
      break;
    n = (in[0] - '0') * 10 + (in[1] - '0');
    n *= pow(10, in[3] - '0');
   // cout<<n<<endl;
    _log = log2(n);
    //cout<<_log<<endl;
    ans = (n - (1 << _log)) * 2 + 1;
    cout<<ans<<endl;
    cin>>in;
  }
}
