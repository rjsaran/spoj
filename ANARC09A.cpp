//DATE: 22/09/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/GCD2/

#include <bits/stdc++.h>

#define gc getchar_unlocked
#define pc putchar_unlocked
# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int

using namespace std;

int compute(string input){
  int open = 0, close = 0;
  int len = input.length();
  for(int i = 0; i < len; i++){
    if(input[i] == '{')
      open++;
    if(input[i] == '}'){
      if(open)
        open--;
      else close++;
    }
  }
  return open / 2 + close / 2 + open % 2 + close % 2;
}
int main(){
  string input;
  int i = 1;
  cin>>input;
  while(input[0] != '-'){
    cout<<i++<<". "<<compute(input)<<endl;
    cin>>input;
  }
}
