#include<stdio.h>

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

int legendra_symbol(int a,int p)
{
	int s,i,a1,r;
	if(a<0)
	{
		while(a<0)
			a=a+p;
	}
	a1=a%p;
	if(a1==1)
		return 1;
	if(a1==p-1)
		return power((p-1)/2);
	if(a1==2)
	{
		if((p-1)%4==0)
			return power((p-1)/4);
		else
			return power((p+1)/4);
	}
	r=power((a1-1)/2);
	if(r==-1)
		r=power((p-1)/2);
	return r*legendra_symbol(p,a1);
}

int main()
{
	int p,a,a1,d;
	printf("Enter An Odd Prime :\t");
	scanf("%d",&p);
	printf("Enter An Integer :\t");
	scanf("%d",&a);
	if(gcd(a,p)>1)
		d=0;
	else
	{
		d=legendra_symbol(a,p);
		if(d==p-1)
			d=-1;
	}
	printf("The Legendre Symbol (%d,%d) =%d\n",a,p,d);
}
