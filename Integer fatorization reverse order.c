#include <stdio.h>
int main()
{
	int x=0;
	printf("输入一位整数："); 
	scanf("%d",&x);
	int t=0;
	do{
		int d=x%10;
		t=t*10+d;
		x/=10;
	}while(x>0);
	printf("%d\n",t);
	x=t;
	do{
		int d= x%10;
		printf("%d",d);
		if (x>9)
		{
			printf(" ");
		}
		x/=10;
	}while (x>0);
	printf("\n");
	return 0;
}
