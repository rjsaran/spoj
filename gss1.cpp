//DATE: 23/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/GSS1/

#include <bits/stdc++.h>

# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int
# define FOR(i,j,n) for(i = j; i < n; i++)

using namespace std;

struct TREE{
	lli max;
	lli sum;
	lli left;
	lli right;
};
TREE * tree;
int  *arr;

struct TREE build_segment_tree(int i, int j, int ind){
	if(i == j){
		tree[ind].max = tree[ind].sum = tree[ind].left = tree[ind].right = arr[i];
		return tree[ind];
	}
	int mid = i + (j - i) / 2;
	struct TREE left = build_segment_tree(i, mid, 2 * ind + 1);
	struct TREE right = build_segment_tree(mid + 1, j, 2 * ind + 2);
	tree[ind].sum = left.sum + right.sum;
	tree[ind].left = max(left.left, left.sum + right.left);
	tree[ind].right = max(right.right, right.sum + left.right);
	tree[ind].max = max(left.max, max(right.max, left.right + right.left));
	return tree[ind];
}

struct TREE RMQSUM(int i, int j, int l , int r, int ind){
	struct TREE temp;
	if(l <= i && r >= j)
		return tree[ind];
	if(l > j || r < i){
		temp.max = temp.sum = temp.left = temp.right = INT_MIN;
		return temp;
	}
	int mid = i + (j - i) / 2;
	struct TREE left = RMQSUM(i, mid, l, r, 2 * ind + 1);
	struct TREE right = RMQSUM(mid + 1, j, l, r, 2 * ind + 2);
	temp.sum = left.sum + right.sum;
	temp.left = max(left.left, left.sum + right.left);
	temp.right = max(right.right, right.sum + left.right);
 	temp.max = max(left.max, max(right.max ,left.right + right.left));
	return temp;
}

int main(){
	int N, l, r;
	lli M;
	scanf("%d", &N);
	arr = new int[N];
	struct TREE ans;
	int _log = ceil(log2(N));
	int size = 2 * (1<<_log) - 1;
	tree = (struct TREE *)malloc(sizeof(struct TREE) * size);
	for(int i =  0; i < N; i++)
		scanf("%d", &arr[i]);
  build_segment_tree(0, N - 1, 0);

	scanf("%lld", &M);
	for(lli i = 0; i < M; i++){
		scanf("%d%d", &l, &r);
		ans = RMQSUM(0, N - 1, l - 1, r - 1, 0);
		printf("%lld\n", ans.max);
	}
}
