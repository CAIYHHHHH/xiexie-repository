//#include <stdio.h>
//int main()
//{
////	//求偶数个数 
////	int x,c;
////	scanf("%d",&x);
////	while(x>0)
////	{
////		if(x%2==0)
////		{
////			c++;
////		}
////		x/=10;
////	}
////	printf("%d",c);
//}
//（3）用户不断输入成绩（0-100），输入-1结束录入，统计及格人数和不及格人数。要求：输入非法成绩时提示错误并重新输入
//（用continue实现）；输入-1时结束录入（用break实现
//#include <stdio.h>
//int main()
// {
// 	int score,n=0,x=0;
//	 while(1)
//	 {
//	 	scanf("%d",&score);
//	 	if(score==-1)
//	 	{
//	 		break;
//		 }
//		if(score<0||score>100)
//		{
//			printf("输入错误，请重新输入\n");
//			continue;
//		}
//		if (score>=60)
//		{
//			n++;
//		}
//		else
//		x++;
//	  } 
//	  printf("及格人数为：%d",n);
//	  printf("不及格人数为：%d",x);
// }
//（4）猴子吃桃问题。第10天早上剩1个桃子，求第一天共摘了多少个。
//#include<stdio.h>
//int main()
//{
//	int peach=1;
//	int day;
//	for(day=9;day>=1;day--)
//	{
//		peach=(peach+1)*2;
//		}
//	printf("第一天一共摘了%d个桃子",peach);
//	return 0;
//}
//（5）输出斐波那契数列的前20项（f1=1, f2=1, fn=fn-1+fn-2）。
//include<stdio.h>
//int main()
//{
//	int f[21];
//	f[1]=1;
//	f[2]=1;
//	int i;
//	for(i=3;i<=20;i++)
//	{
//		f[i]=f[i-1]+f[i-2];
//	}
//	for(i=1;i<=20;i++)
//	{
//		printf("%d ",f[i]);
//	}
//	return 0;
//}
//（1）5行10列的"*"矩形：
//**********
//**********
//**********
//**********
//**********
//（2）5行的直角三角形（直角在左下角）：
//*
//**
//***
//****
//*****
//（3）5行的金字塔图形：
//    *
//   ***
//  *****
// *******
//*********
//#include<stdio.h>
//int main()
//{
//	int i,j,k;
//	for(i=1;i<=5;i++)
//	{
//		for(j=1;j<=10;j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	printf("\n");
//	for(i=1;i<=5;i++)
//	{
//		for(j=1;j<=i;j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	printf("\n");
//	for(i=1;i<=5;i++)
//	{
//		for(j=1;j<=5-i;j++)
//		{
//			printf(" ");
//		}
//		for(k=1;k<=2*i-1;k++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//}
//7）百钱百鸡问题。公鸡5文/只，母鸡3文/只，小鸡1文/3只，100文买100只，求各多少只。
//#include<stdio.h>
//int main()
//{
//	int x,y,z;
//	for(x=0;x<=20;x++)
//	{
//		for(y=0;y<=33;y++)
//		{
//			z=100-y-x;
//			if(5*x+3*y+z/3==100 && z%3==0)
//			{
//				printf("公鸡%d只，母鸡%d只，小鸡%d只\n",x,y,z);
//			}
//		}
//	}
//	return 0; 
//}
