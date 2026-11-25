//3<=n<=7,输入n则求出满足（举例：153=1*1*1+5*5*5+3*3*3）这种类型的数，n代表位数 
#include<stdio.h>
int main()
{
	int n,i=1;
	scanf("%d",&n);
	int frist=1;
	while(i<n)
	{
		frist*=10;
		i++;
	}
//	printf("%d",frist);
	i=frist;
	while(i<frist*10)
	{
		int t=i;
		int sum=0;
		do{
			int d=t%10;
			t/=10;
			int p=d;
			int j=1;
			while(j<n)
			{
				p*=d;
				j++;
			}
			sum+=p;
		}while(t>0);
		if(sum==i)
		{
			printf("%d\n",i);
		}
		i++;
	}
}
