//DATE: 09/10/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/TWOSQRS/

#include <bits/stdc++.h>
#include <queue>

#define gc getchar_unlocked
#define pc putchar_unlocked
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int
# define NUM_PRIME 80000
# define MAX 1000000

using namespace std;

int num_prime = 0;
int primes[NUM_PRIME];
bool SIEVE[MAX + 1];

ull fastwrite(ull inp) {
  ull a = (inp < 0) ? -inp : inp;
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

void calculate_sieve() {
	int j;
	int limit = sqrt(MAX);
	primes[num_prime++] = 2;
	for(int i = 3; i <= MAX; i++){
		if(!SIEVE[i] && (i & 1)) {
			primes[num_prime++] = i;
			for(j = 1; j * i <= MAX; j++)
				SIEVE[j * i] = true;
		}
	}
}

int main(){

	int t;
	ull n;
	clock_t start, end;
  double cpu_time_used;
 	start = clock();
		calculate_sieve();
	t = fastread();
	while(t--) {
		n = fastread();
	//	printf("read value is %llu", n);
		int i = 0;
		int current_count;
		bool flag = false;
		while(n != 1 && i < num_prime){
			current_count = 0;
			while(n % primes[i] == 0){
				current_count++;
				n = n / primes[i];
			}
			if(primes[i] % 4 == 3 && current_count & 1) {
				flag = true;
				break;
			}
			i++;
		}
		if(n % 4 == 3) flag = true;
		flag ? printf("No\n") : printf("Yes\n");
	}
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("complete time taken: %f \n", cpu_time_used);
}
