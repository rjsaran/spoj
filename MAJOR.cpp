//DATE: 10/10/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/MAJOR/

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

	int t, n, head, count;
  t = fastread();
  while(t--){
    n = fastread();
    int arr[n];
    count = 1;
    head = arr[0] = fastread();
    for(int i = 1; i < n; i++){
      arr[i] = fastread();
      if(arr[i] == head) count++;
      else count--;
      if(count == 0) {
        head = arr[i];
        count = 1;
      }
    }
    count = 0;
    for(int i = 0; i < n; i++)
      if(arr[i] == head) count++;
    count > n / 2 ? printf("YES %d\n", head) : printf("NO\n");
  }
}
