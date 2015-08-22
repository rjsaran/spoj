//DATE: 23/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/HUBULLU/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <string>

# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int
# define FOR(i,j,n) for(i = j; i < n; i++)

using namespace std;

int main(){
  lli n;
  int t;
  scanf("%d", &t);
  bool in;
  while(t--){

    scanf("%lld", &n);
    cin >> in;
    in == 0 ? printf("Airborne wins.\n") : printf("Pagfloyd wins.\n");
  }
  return 0;
}
