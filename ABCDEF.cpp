//DATE: 11/10/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/ABCDEF/

# include <bits/stdc++.h>

# define gc getchar_unlocked
# define pc putchar_unlocked
# define li long  int
# define RWTYPE long long int

using namespace std;

RWTYPE fastread(){

  char sign = '\0', c = gc();
  RWTYPE ret = 0;
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
  int N;
  li A, B, count = 0, lcount = 0, rcount = 0;

  N = fastread();
  int arr[N];

  li size = N * N * N + 10;
  li *leftSide, *rightSide;
  leftSide = (li *)malloc(sizeof(li) * size);
  rightSide = (li *)malloc(sizeof(li) * size);
  //li leftSide[size], rightSide[size];

  for(int i = 0; i < N; i++)
    arr[i] = fastread();

  li x = -1, y = -1; 
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      for(int k = 0; k < N; k++){
        leftSide[++x] = arr[i] * arr[j] + arr[k];
        if(arr[k]) {
          rightSide[++y] = (arr[i] + arr[j]) * arr[k]; 
        }
      }

  sort(leftSide, leftSide + x + 1);
  sort(rightSide, rightSide + y + 1);

  li i = 0, j = 0;
  while(i <= x && j <= y){
    if(leftSide[i] < rightSide[j])
      i++;
    else if(leftSide[i] > rightSide[j])
      j++;
    else {
      lcount = 1;
      rcount = 1;
      while(i <= x && leftSide[i] == leftSide[i + 1]){
        i++;
        lcount++;
      }
      while(j <= y && rightSide[j] == rightSide[j + 1]){
        j++;
        rcount++;
      }
      i++;
      j++;
      count += rcount * lcount;
    }
  }
  fastwrite(count);
}
