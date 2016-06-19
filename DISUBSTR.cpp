//DATE: 20/06/2016
//Author: Ramjeet Saran
//http://www.spoj.com/problems/DISUBSTR/

// SUFFIX ARRAY APPLICATION 
// TRY 1: using SET MAP GOT TLE

# include <bits/stdc++.h>

# define gc getchar_unlocked
# define pc putchar_unlocked
# define li long  int
# define lli long long int

using namespace std;

int LCP(string s1, string s2) {
  int counter = 0, len1 = s1.length(), len2 = s2.length();
  for(int i = 0; i < len1; i++) {
    if(s1[i] == s2[i]) {
      counter++;
    } else {
      break;
    }
  }
  return counter;
}
int main() {
  int T;
  cin>>T;
  while(T--) {
	  string S;
	  vector<string> suffixArray;
	  cin>>S;
	  int length = S.length();
	  for(int i = 0; i < length; i++) {
      suffixArray.push_back(S.substr(i));
	  }
    sort(suffixArray.begin(), suffixArray.end());
    int ans = suffixArray[0].length();
    for(int j = 1; j < length; j++) {
      // cout<<suffixArray[ j ] << " "<<suffixArray[ j - 1]<<endl;
      ans += suffixArray[j].length() - LCP(suffixArray[j], suffixArray[j - 1]);
    }
    cout<<ans<<endl;
  }
}
