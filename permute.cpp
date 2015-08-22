/*
	Name: PERMUTE2
	Copyright: @raj
	Author: ramjeet saran
	Date: 02/07/14 09:04
	Description: Practice(easy) » Ambiguous Permutations
*/

#include<stdio.h>
int main()
{
	int n,i,f;
	int a[100010];
	scanf("%d",&n);
	a[0]=-1;
	while(n)
	{
		f=0;
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(i=1;i<=n;i++)
			if(a[a[i]]==i)
				f++;
		f==n?printf("ambiguous\n"):printf("not ambiguous\n");
		scanf("%d",&n);
	}
	return 0;
}		