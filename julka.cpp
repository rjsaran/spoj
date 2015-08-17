//DATE: 14/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/JULKA/

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int main(){
	string N,M;
	for(int itr = 0; itr < 10; itr++){
		cin>>N>>M;
		int lenN = N.length();
		int lenM = M.length();
		int lenS = 0;
		int flag = 0;
		int i = 0, j = 0, k = 0;
		int borrow = 0;
		string subresult,divideresult;
		//code for subtraction
		while(i < lenN && j < lenM){
			int mool = (N[lenN - i -1] - '0') - (M[lenM - j -1] - '0') - borrow;
			borrow = mool < 0 ? 1: 0;
			subresult[lenS++] = mool < 0 ? mool + 10 + '0' : mool + '0';
			i++;
			j++;
		}
		while(i < lenN){	
			int mool = (N[lenN - i -1] - '0') - borrow;
			borrow = mool < 0 ? 1: 0;
			subresult[lenS++] = mool < 0 ? mool + 10 + '0' : mool + '0';
			i++;
		}
		while(j<lenM){
			int mool = (M[lenM - j -1] - '0') - borrow;
			borrow = mool < 0 ? 1: 0;
			subresult[lenS++] = mool < 0 ? mool + 10 + '0' : mool + '0';
			j++;
		}

		//code for divide

		int lenD = 0;
		i = lenS - 1;
		int forward = 0;
		while(i >= 0){
			int mool = subresult[i] - '0';
			if(forward == 1)
				mool += 10 ;
			subresult[i] = mool / 2 + '0';
			forward = mool % 2;
			i--;
		}
		for(i = 0; i < lenM / 2; i++){
		 	int temp = M[i];
		 	M[i] = M[lenM - i - 1];
		 	M[lenM - i - 1] = temp;;
		}
		
		// code for add
		string addresult = "0";
		int lenA = 0;
		int carry = 0;
		i = 0;
		j = 0;
		while(i < lenS && j < lenM){
			int mool = (subresult[i] - '0') + (M[j] - '0') + carry;
			addresult[lenA++] = (mool % 10) + '0';
			carry = mool > 9 ? 1 : 0;
			i++;
			j++;
		}
		while(i < lenS){	
			int mool = (subresult[i] - '0') + carry;
			addresult[lenA++] = (mool % 10) + '0';
			carry = mool > 9 ? 1 : 0;
			i++;
		}
		while(j < lenM){
			int mool = (M[j] - '0') + carry;
			addresult[lenA++] = (mool %10) + '0';
			carry = mool > 9 ? 1 : 0;
			j++;
		}
		while(carry){
			addresult[lenA++] = (carry%10) + '0';
			carry /= 10;
			cout<<(carry%10);
		}

		flag = 0;
		 for(i = 0; i < lenA; i++) {
		 	if(addresult[lenA - i - 1] != 48)
		 		flag = 1;
		 	if(flag == 1)
		 		cout<<addresult[lenA - i - 1];
		 }

		 if(flag == 0)
		 	cout<<"0";
		 cout<<endl;

		 flag = 0;
		 for(i = 0; i < lenS; i++)
		 {
		 	if(subresult[lenS - i - 1] != 48)
				flag = 1;
		 	if(flag == 1)
				cout<<subresult[lenS - i - 1];
			//cout<<subresult[lenS - i - 1];
		}
		if(flag == 0)
			cout<<"0";
		 cout<<endl;

	}

}
