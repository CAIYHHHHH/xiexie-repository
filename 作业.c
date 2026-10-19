#include <stdio.h>
int main ()
{
	int math=85,English=90;
	printf("======================\n");
	printf(" 学生成绩管理系统 v1.0\n");
	printf("========================\n"); 
	printf("欢迎使用本系统！\n");
	printf("========================\n");
	printf("    学 生 成 绩 单 \n");
	printf("========================\n");
	printf("数学：   %d分\n",math);
	printf("英语：   %d分\n",English);
	printf("------------------------\n");
	int amount = math + English;
	printf("总分：   %d分\n",amount);
	float a = (math+English)/2.0;
	printf("平均分：  %g分\n",a);
	printf("========================");
	return 0;
}
