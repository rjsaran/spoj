//DATE: 26/08/2013
//Author: Ramjeet Saran
//http://www.spoj.com/problems/TEST/

#include <stdio.h>
 
int main()
	{
		int n,i;
		scanf("%2d",&n);
		for(i=n;i!=42;)
			{
				printf("\n%d",i);
				scanf("%d",&i);
			}
		return 0;
	}  
