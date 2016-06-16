//DATE: 16/06/2016
//Author: Ramjeet Saran
//http://www.spoj.com/problems/AMR12D/


// ---- PROBLEM STATEMENT ---- //
/*
With water from the stream Galadriel filled the basin to the brim, and breathed on it, 
and when the water was still again she spoke. 'Here is the Mirror of Galadriel,' she said.
'I have brought you here so that you may look in it, if you will. For this is what your folk would call magic, 
I believe; though I do not understand clearly what they mean; and they seem also to use the same word of the
 deceits of the Enemy. But this, if you will, is the magic of Galadriel. Did you not say that you wished to see 
 Elf-magic?' - Galadriel to Frodo and Sam, describing her Mirror.

We call a string S magical if every substring of S appears in Galadriel's Mirror (under lateral inversion). 
In other words, a magical string is a string where every substring has its reverse in the string.

Given a string S, determine if it is magical or not.

Input (STDIN):

The first line contains T, the number of test cases. The next T lines contain a string each. 

Output (STDOUT):

For each test case, output "YES" if the string is magical, and "NO" otherwise.

Constraints:

1 <= T <= 100

1 <= |S| <= 10

S contains only lower-case characters.

Sample Input:

2

aba

ab

Sample Output:

YES

NO
*/

// ------------ SOLUTION ----------- //
// EASY ONE (JUST CHECK IF PANLINDROME OR NOT)

# include <bits/stdc++.h>
# include <cstring>

# define gc getchar_unlocked
# define pc putchar_unlocked
# define li long  int
# define lli long long int

using namespace std;

void checkIsPalin(string S) {
  int length = S.length();
  int mid = length / 2;
  for(int i = 0; i <= length / 2; i++) {
    if(S[i] != S[length - i - 1]) {
      cout<<"NO"<<endl;
      return;
    }
  }
  cout<<"YES"<<endl;
}
int main() {
  int T;
  string S;
  cin>>T;
  while(T--) {
    cin>>S;
    checkIsPalin(S); 
  }
}
