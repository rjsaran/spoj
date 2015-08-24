//DATE: 24/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/WEIRDFN/

# include <queue>
# include <vector>
# include <iostream>
# define lli long long int

using namespace std;
 
struct comparator{
    bool operator() ( lli i, lli j){
        return i > j;
    }
};
priority_queue<lli, vector<lli>, comparator> minHeap;
priority_queue<lli, vector<lli> > maxHeap;
lli median = 0;
int sizeMax = 0;
int sizeMin = 0;

lli getMedian(lli T ){
    if(sizeMax > sizeMin){
        if(T >= median){
            minHeap.push(T);
            sizeMin++;
        }
        else {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(T);
            sizeMin++;
        }
        median = maxHeap.top();
    }
    else if(sizeMax < sizeMin){
        if(T <= median){
            maxHeap.push(T);
            sizeMax++;
        }
        else {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(T);
            sizeMax++;
        }
        median = maxHeap.top();
    }
    else {
        if( T <= median){
            sizeMax++;
            maxHeap.push(T);
            median = maxHeap.top();
        }
        else {
            sizeMin++;
            minHeap.push(T);
            median = minHeap.top();
        }
    }
    return median;
}
int main(int argc, char const *argv[])
{
    int t, N;
    lli A, B, C, ans;
    scanf("%d", &t);
    while(t--){
        scanf("%lld%lld%lld%d", &A, &B, &C, &N);
        sizeMin = sizeMax = median = 0;
        minHeap = priority_queue <lli, vector<lli>, comparator >();
        maxHeap = priority_queue <lli, vector<lli> >();
        ans = 1;
        lli Fn = 1;
        for(int i = 2; i <= N; i++){
            Fn = (((A * getMedian(Fn) ) % 1000000007 + (B * i) % 1000000007 ) % 1000000007 + C ) % 1000000007;
            ans += Fn;
        }
        printf("%lld\n", ans);
    }
}