//DATE: 13/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/PRIME1/

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;
int numprimes = 0;
int primes[3500];

int isprime(long int x){
	for(int i = 0; i < numprimes && primes[i] <= sqrt(x); i++){
		if(!(x%primes[i]))
			return 0;
	}
	return 1;
}

int main()
{
	long int t,start,end;
	for(int i = 2; i <= 32000; i++){
		if(isprime(i))
			primes[numprimes++] = i;
	}
	cin>>t;
	while(t--){
		cin>>start>>end;
		if(start == 1)
			start = 2;
		for(long int i = start; i <= end; i++){
			if(isprime(i))
				cout<<i<<endl;
		}
	}
}
