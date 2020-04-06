#include<stdio.h>
#include<stdlib.h>

int gcd(int a,int b)
{
	int r0,r1,q,t;
	if(a==0)
		return b;
	if(b==0)
		return a;
	r0=a;
	if(r0<0)
		r0=-r0;
	r1=b;
	if(r1<0)
		r1=-r1;
	while(r1>0)
	{
		q=r0/r1;
		t=r0-(r1*q);
		r0=r1;
		r1=t;
	}
	return r0;
}

int power(int i)
{
	if(i%2==0)
		return 1;
	else
		return -1;
}

int Jacobi_Symbol(int a,int n)
{
	int s,i,a1,r1,r;
	if(a<0)
	{
		while(a<0)
			a=a+n;
	}
	a1=a%n;
	if(a1==1)
		return 1;
	if(a1==n-1)
		return power((n-1)/2);
	if(a1==2)
		return power(((n*n)-1)/8);
	if(a1%2==0)
	{
		while(a1%2==0)
		{
			i++;
			a1=a1/2;
		}
		r1=power(i*(n*n - 1)/8);
		return r1*Jacobi_Symbol(a1,n);	
	}
	r=power(((a1-1)/2)*((n-1)/2));
	return r*Jacobi_Symbol(n,a1);
}

int main()
{
	int n,a,d;
	printf("Enter An Odd Positive Integer :\t");
	scanf("%d",&n);
	printf("Enter An integer :\t");
	scanf("%d",&a);
	if(gcd(a,n)>1)
		d=0;
	else
	{
		d=Jacobi_Symbol(a,n);
		printf("The Jacobi Symbol (%d,%d)=%d\n",a,n,d);
	}
}
