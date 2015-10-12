//DATE: 13/10/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/GLJIVE/

# include <bits/stdc++.h>

# define gc getchar_unlocked
# define pc putchar_unlocked
# define li long  int
# define RWTYPE long long int

using namespace std;

int main(){
  int att[10];
  for(int i = 0; i < 10; i++)
    scanf("%d", &att[i]);
  int sum = 0;
  int i = 0;
  while(sum < 100 && i < 10)
    sum += att[i++];
  if(sum > 100){
    if(sum - 100 <= 100 - sum + att[i - 1])
      printf("%d\n", sum);
    else printf("%d\n", sum - att[i - 1]);
  }
  else printf("%d\n", sum);
}
