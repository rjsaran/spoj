//DATE: 31/08/2015
//Author: Ramjeet Saran
//http://www.spoj.com/problems/SBANK/

#include <bits/stdc++.h>

# define MAX(a,b) a>b ? a : b;
# define MIN(a,b) a<b ? a : b;
# define lli long long int
# define ull unsigned long long int
# define FOR(i,j,n) for(i = j; i < n; i++)

using namespace std;

struct node {
	int count;
	int * account;
	struct node * left, * right;
};

int campare(struct node * ptr1, struct node * ptr2){
	for(int i = 0; i < 6; i++){
	//	cout<<ptr1->account[i]<<" "<<ptr2->account[i]<<endl;
		if(ptr1->account[i] > ptr2->account[i])
			return 1;
		if(ptr1->account[i] < ptr2->account[i])
			return 2;
	}
	return 0;
}

struct node * getnode(int * account){
	struct node * newnode = (struct node *)malloc(sizeof(struct node));

	newnode->account = account;
	newnode->count = 1;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

struct node * insert(struct node *  root, struct node * ptr){
	if(!root)
		return ptr;
	switch(campare(root, ptr)){
		case 0:
			root->count++;
			break;
		case 1:
			root->left = insert(root->left, ptr);
			break;
		case 2:
			root->right = insert(root->right, ptr);
			break;
	}

	return root;
}

void inorder(struct node * root){
	if(root){
		inorder(root->left);
		printf("%02d ", root->account[0]);
		printf("%08d ", root->account[1]);
		for(int i = 2; i < 6; i++)
		printf("%04d ", root->account[i]);
		printf("%d\n", root->count);
		inorder(root->right);
	}
}
int main(){

	int T, N;
	struct node * root;
	int * account;
	scanf("%d",&T);
	while(T--){
		root = NULL;
		scanf("%d", &N);
		for(int i = 0; i < N; i++){
			account = new int[6];
			for(int j = 0; j < 6; j++){
				scanf("%d", &account[j]);
			}
			if(!root)
				root = insert(root, getnode(account));
			else
				insert(root, getnode(account));
		}
		inorder(root);
		printf("\n");
	}
}
