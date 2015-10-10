//DATE: 10/10/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/ACPC11B/

# include <bits/stdc++.h>
# include <queue>

# define gc getchar_unlocked
# define pc putchar_unlocked
# define MIN(a,b) a<b ? a : b;
# define li long int
# define lli long long int
# define ull unsigned long long int
# define _MAX 1000000;
using namespace std;

lli fastread()
{
  char sign = '\0', c = gc();
  lli ret = 0;
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

li mod_b_search(li sorted[], int low, int high, li K, int len){
  int mid = (low + high) / 2;
  li a = _MAX;
  li b = _MAX;

  if(low > high) {
    if(low != len)
      a = sorted[low] - K < 0 ? K - sorted[low] : sorted[low] - K;

    if(high != -1)
      b = sorted[high] - K < 0 ? K - sorted[high] : sorted[high] - K;

    return MIN(a, b);
  }

  if(sorted[mid] == K)
    return 0;
  else if(sorted[mid] > K)
    return mod_b_search(sorted, low, mid -1 , K, len);
  else return mod_b_search(sorted, mid + 1, high, K, len);
}

int main(){

	int t, N, M;
  t = fastread();
  while(t--){
    N = fastread();
    li first[N];
    for(int i = 0; i < N; i++)
      first[i] = fastread();

    M = fastread();
    li second[M];
    for(int i = 0; i < M; i++)
      second[i] = fastread();

    li min = _MAX;

    if(N < M) {
      sort(first, first + N);
      for(int i = 0; i < M; i++)
        min = MIN(min, mod_b_search(first, 0, N - 1, second[i], N));
    }
    else {
      sort(second, second + M);
       for(int i = 0; i < N; i++)
        min = MIN(min, mod_b_search(second, 0, M -1, first[i], M));
    }

    printf("%ld\n", min);
  }
}
