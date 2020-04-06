#include<stdio.h>

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
	s=1;
	for(i=2;i<a1;i++)
	{
		if(a1%i==0)
		{
			s=0;
			return legendra_symbol(i,p)*legendra_symbol(a1/i,p);
			break;
		}
	}
	if(s==1)
	{
		r=power(((a1-1)/2)*((p-1)/2));
		return r*legendra_symbol(p,a1);
	}
}

int main()
{
	int p,a,a1,d;
	printf("Enter An Odd Prime :\t");
	scanf("%d",&p);
	printf("Enter An Integer :\t");
	scanf("%d",&a);
	d=legendra_symbol(a,p);
	if(d==p-1)
		d=-1;
	printf("The Legendre Symbol (%d,%d) =%d\n",a,p,d);
}
