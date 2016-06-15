//DATE: 15/0/2016
//Author: Ramjeet Saran
//http://www.spoj.com/problems/NHAY/


// ---- PROBLEM STATEMENT ---- //
/*
Write a program that finds all occurences of a given pattern in a given input string. 
This is often referred to as finding a needle in a haystack.

The program has to detect all occurences of the needle in the haystack. 
It should take the needle and the haystack as input, and output the positions of each occurence, as shown below. 
The suggested implementation is the KMP algorithm, but this is not a requirement. 
However, a naive approach will probably exceed the time limit, whereas other algorithms are more complicated... The choice is yours.

Input

The input consists of a number of test cases. Each test case is composed of three lines, containing:

the length of the needle,
the needle itself,
the haystack.
The length of the needle is only limited by the memory available to your program, so do not make any assumptions - instead, 
read the length and allocate memory as needed. 
The haystack is not limited in size, which implies that your program should not read the whole haystack at once. 
The KMP algorithm is stream-based, i.e. it processes the haystack character by character, so this is not a problem.

The test cases come one after another, each occupying three lines, with no additional space or line breaks in between.

Output

For each test case your program should output all positions of the needle's occurences within the haystack. 
If a match is found, the output should contain the position of the first character of the match. 
Characters in the haystack are numbered starting with zero.

For a given test case, the positions output should be sorted in ascending order, and each of these should be printed in a separate line. 
For two different test cases, the positions should be separated by an empty line
*/


# include <bits/stdc++.h>

# define gc getchar_unlocked
# define pc putchar_unlocked
# define li long  int
# define lli long long int

using namespace std;

lli fastRead() {

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

lli fastWrite(lli inp) {
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


vector<int> computeLPS(string pattern, li length) {
    li len = 0;
    li i = 1;
    vector<int> lps(length);
    
    lps[0] = 0;
    
    while (i < length) {
       if (pattern[i] == pattern[len]) {
         len++;
         lps[i] = len;
         i++;
       } else {
         if (len != 0) {
           len = lps[len - 1];
         }
         else {
           lps[i] = 0;
           i++;
         }
       }
    }
    return lps;
}

void KMPSearch(string pattern, li length) {
  vector<int> lps(length);
  int j = 0, i = 0;
  
  lps = computeLPS(pattern, length);
  
  string txt;
  getline(cin, txt);
  li txtlength = txt.length();
  
  while (i < txtlength) {
    if (pattern[j] == txt[i]) {
      j++;
      i++;
    }

    if (j == length) {
      fastWrite(i-j);
      j = lps[j-1];
    } else if (i < txt.length() && pattern[j] != txt[i]) {
      if (j != 0)
        j = lps[j-1];
      else
        i = i + 1;
    }
  }
}

int main() {
  li lengthOfNeedle;
  
  while( scanf("%ld", &lengthOfNeedle) != EOF) {
    string needle;
    getline(cin, needle);
    getline(cin, needle);
    
    KMPSearch(needle, lengthOfNeedle);
    cout<<endl;
  }
}
