//DATE: 20/06/2016
//Author: Ramjeet Saran
//http://www.spoj.com/problems/MCOINS/

// GAME ALGORITHMS

# include <bits/stdc++.h>

# define gc getchar_unlocked
# define pc putchar_unlocked
# define li long  int
# define lli long long int

using namespace std;


int main() {
  int N, K, M;
  cin>>N>>K>>M;
  int *arr = new int[1000001];
  memset(arr, 0, 1000001);
  for(int i = 1; i <= 1000000; i++) {
    if(arr[i - 1] == 0 || (i - N >= 0 && arr[i - N] == 0) || (i - K >= 0 && arr[i - K] == 0)) {
      arr[i] = 1;
    }
  }
  int A;
  for(int j = 0; j < M; j++) {
    cin>>A;
    arr[A] == 1 ? cout<<"A" : cout<<"B";
  }
  cout<<endl;
}
