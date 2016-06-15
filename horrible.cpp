//DATE: 15/06/2016
//Author: Ramjeet Saran
//http://www.spoj.com/problems/HORRIBLE/


// USING SEGMENT TREE
// TRY1 * TRY 2: WITHOUT LAZY PROPOGATION (TLE)

// ---- PROBLEM STATEMENT ---- //
/*
World is getting more evil and it's getting tougher to get into the Evil League of Evil.
Since the legendary Bad Horse has retired, now you have to correctly answer the evil questions of Dr. Horrible,
who has a PhD in horribleness (but not in Computer Science).

You are given an array of N elements, which are initially all 0. After that you will be given C commands. They are -

* 0 p q v - you have to add v to all numbers in the range of p to q (inclusive),
where p and q are two indexes of the array.

* 1 p q - output a line containing a single integer which is the sum of all the array elements between p and q (inclusive)



Input

In the first line you'll be given T, number of test cases.

Each test case will start with N (N<=100 000) and C (C<=100 000). After that you'll be given
C commands in the format as mentioned above. 1 <= p,q <= N and 1 <= v <= 10^7.

Output

Print the answers of the queries.
*/


# include <bits/stdc++.h>

# define gc getchar_unlocked
# define pc putchar_unlocked
# define li long  int
# define lli long long int

using namespace std;

int fastRead() {

  char sign = '\0', c = gc();
  lli ret = 0;
  while((c < '0' ||c > '9') && c != '-') {
		c = gc();
	}
  if(c == '-') {
    sign = '1';
    c = gc();
  }
  while(c >= '0' && c <= '9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  if(sign) {
		ret =- ret;
  }
  return ret;
}

void fastWrite(lli inp) {
  lli a = (inp < 0) ? -inp : inp;
  char snum[20];
  int i = 0;
  do
  {
    snum[i++] = a % 10 + 48;
    a = a / 10;
  } while(a != 0);
  if(inp < 0) {
    snum[i++] = '-';
  }
  i--;
  while(i >= 0) {
   pc(snum[i--]);
  }
  pc('\n');
}

lli getMid(lli s, lli e) {
  return s + (e - s) / 2;
}

void updateValue(lli *st, lli *lazy, lli start, lli end, lli p, lli q, lli value, lli si) {
  
  if(lazy[si] != 0) {
    st[si] += (end - start + 1) * lazy[si];
    
    if(start != end) {
      lazy[2 * si + 1] += lazy[si];
      lazy[2 * si + 2] += lazy[si];
    }
    lazy[si] = 0;
  }

  if(start > end || q < start || p > end) {
    return;
  }
  if(start >= p && end <= q) {
    st[si] += (end - start + 1) * value; 
    if(start != end) {
      lazy[2 * si + 1] += value;
      lazy[2 * si + 2] += value;
    }
    return;
  }
  lli mid = getMid(start, end);
  updateValue(st, lazy, start, mid, p, q, value, 2 * si + 1);
  updateValue(st, lazy, mid + 1, end, p, q, value, 2 * si + 2);
  
  st[si] = st[2 * si + 1] + st[2 * si + 2];
}

lli getValue(lli *st, lli *lazy, lli start, lli end, lli p, lli q, lli si) {
    
  if(lazy[si] != 0) {
    st[si] += (end - start + 1) * lazy[si];
    
    if(start != end) {
      lazy[2 * si + 1] += lazy[si];
      lazy[2 * si + 2] += lazy[si];
    }
    lazy[si] = 0;
  }
  
  if(start > end || q < start || p > end) {
    return 0;
  }
  
  if(p <= start && q >= end) {
    return st[si];
  }
  
  lli mid = getMid(start, end);
  return getValue(st, lazy, start, mid, p, q, 2 * si + 1) + 
         getValue(st, lazy, mid + 1, end, p, q, 2 * si + 2);  
}

int main() {
  lli N, Q, T, d, p, q, v, x, max_size;
  T = fastRead();
  while(T--) {
    N = fastRead();
    Q = fastRead();
    x = (lli)(ceil(log2(N)));
    max_size = 2 * (lli) pow(2, x) - 1;
    lli *st = new long long int[max_size];
    lli *lazy = new long long int[max_size];
    memset(st, 0, max_size);
    memset(lazy, 0, max_size);
    for(lli i = 0; i < Q; i++) {
      scanf("%lld", &d);
      if(d == 0) {
        scanf("%lld%lld%lld", &p, &q, &v);
        updateValue(st, lazy, 0, N - 1, p - 1, q - 1, v, 0);
        // for(lli i = 0 ; i < max_size; i++) cout<<st[i]<<" "; 
        // cout<< endl;
        // for(lli i = 0 ; i < max_size; i++) cout<<lazy[i]<<" "; 
      } else {
        scanf("%lld%lld", &p, &q);
        fastWrite(getValue(st, lazy, 0, N - 1, p - 1, q - 1, 0));
      }
    }
  }
}
