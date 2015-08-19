//DATE: 18/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/ACODE/

#include <iostream>
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

	string input;
	ull temp;
	cin>>input;
	while(input[0] != 48){
		int len = input.length();
		ull arr[len];
		arr[0] = 1;

		temp =  input[1] - '0' + 10 * (input[0] - '0');
		arr[1] = temp < 27 && input[1] != 48 ? 2 : 1;

		for(int i = 2; i < len; i++){
			temp = input[i] - '0' + 10 * (input[i - 1] - '0');
			arr[i] = input[i] != 48 ? (temp < 27 && input[i - 1] != 48 ? arr[i-1] + arr[i - 2] : arr[i-1] ): arr[i-2];
			//cout<<arr[i]<<endl;
		}
		cout<<arr[len - 1]<<endl;
		cin>>input;
	}
}
