#include<stdio.h>
#include<stdlib.h>

int mod(int i,int j,int p)
{
	int product=1,k;
	for(k=1;k<=j;k++)
	{
		product=(product*i)%p;
	}
	return product;
}

int main()
{
	int i,j,p;
	printf("Enter An Odd Prime :\t");
	scanf("%d",&p);
	printf("The quadratic residure modulo %d are given by\n",p);
	for(i=1;i<p;i++)
	{
		j=mod(i,(p-1)/2,p);
		if(j==1)
			printf("%d\t",i);
	}
	printf("\n");
}
