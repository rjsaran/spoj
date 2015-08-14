//DATE: 14/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/TOANDFRO/

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;
int main(){
	int col;
	cin>>col;
	while(col){
		string str;
		int len,row,flag=0,k=0;
		cin>>str;
		len = str.length();
		row =len / col;
		char mat[row][col];
		for(int i=0; i<row; i++){
			if(flag == 0)
				for(int j=0; j<col;j++)
					mat[i][j] = str[k++];
			else 
				for(int j=col-1; j>=0;j--)
					mat[i][j] = str[k++];
			flag = (flag + 1) % 2; 
		}
		for(int i=0;i<col;i++)
			for(int j=0;j<row;j++)
				cout<<mat[j][i];
		cout<<endl;
		cin>>col;
	}
}
