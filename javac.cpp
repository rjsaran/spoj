//DATE: 26/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/JAVAC/

#include <bits/stdc++.h>

# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int
# define FOR(i,j,n) for(i = j; i < n; i++)

using namespace std;
int checkForError(char * in, int len){
	if(isupper(in[0]) || in[0] == '_' || in[len - 1] == '_')
		return 1;
	int cpp = 0, java = 0;
	for(int i = 0; i < len; i++){
		if(isupper(in[i]))
			java = 1;
		else if(in[i] == '_'){
			cpp = 1;
			if(in[i + 1] == '_')
				return 1;
		}
		if(cpp && java)
			return 1;
	}
	return 0;
}

int main(){

	char in[200];
	int len;
	while(scanf("%s",in) == 1){
		len = strlen(in);
		if(checkForError(in, len)){
			cout<<"Error!"<<endl;
		}
		else {
			for(int i = 0; i < len; i++){
				if(isupper(in[i]))
					printf("_%c", tolower(in[i]));
				else if(in[i] == '_'){
					printf("%c", toupper(in[i + 1]));
					i++;
				}
				else printf("%c", in[i]);
			}
			cout<<endl;
		}
	}
	
}
