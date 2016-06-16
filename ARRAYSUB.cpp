//DATE: 16/06/2016
//Author: Ramjeet Saran
//http://www.spoj.com/problems/ARRAYSUB/


// ---- PROBLEM STATEMENT ---- //
/*
Given an array and an integer k, find the maximum for each and every contiguous subarray of size k.

Input

the number n denoting number of elements in the array then after a new line we have the numbers of the array

and then k in a new line

n<10^6

k<10^5

1 <= k <=n

and each element of the array is between 0 and 10^6

Output

print the output array
*/


//---- SOLUTION ----- //
/* USING DEQUEU O(n) method
We create a Dequeue, Qi of capacity k, that stores only useful elements of current window of k elements. 
An element is useful if it is in current window and is greater than all other elements on 
left side of it in current window. We process all array elements one by one and maintain Qi 
to contain useful elements of current window and these useful elements are maintained in sorted order.
 The element at front of the Qi is the largest and element at rear of Qi is the smallest of current window.
*/

# include <bits/stdc++.h>

# define gc getchar_unlocked
# define pc putchar_unlocked
# define li long  int
# define lli long long int

using namespace std;

int main() {
  li N, K;
  cin>>N;
  li arr[N];
  for(li i = 0; i < N; i++) {
    cin>>arr[i];
  }
  cin>>K;
  deque<li> _dq(K);
  
  li i = 0;
  for(; i < K; i++) {
    while(!(_dq.empty()) && arr[i] >= arr[_dq.back()]) {
      _dq.pop_back();
    }
    _dq.push_back(i);
  }
  
  for(; i < N; i++) {
    cout<<arr[_dq.front()]<<" ";
    while(!(_dq.empty()) && _dq.front() <= i - K) {
      _dq.pop_front();
    }
    while(!(_dq.empty()) && arr[i] >= arr[_dq.back()]) {
      _dq.pop_back();
    }
    _dq.push_back(i);
  }
  cout<<arr[_dq.front()];
}
