#include <stdio.h>
#include <string.h>
int main()
{
	char i[10];
	//for(i=1;i>=1;i++)
	//	printf("我爱你");
	do
	{
	printf("您爱我吗\n");
	scanf("%s",&i);
	if(strcmp(i,"爱")==0)
	{
		printf("我也爱你\n");
	}
	else
	printf("爱我\n");
	}
	while(strcmp(i,"爱")!=0);
	return 0;
}
