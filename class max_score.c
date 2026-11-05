#include <stdio.h>
int main()
{
	int i,n;
	float score,max_score;
	printf("请输入班级人数：");
	scanf("%d",&n);
	printf("输入第一位学生的成绩：");
	scanf("%f",&max_score);
	for (i=2;i<=n;i++)
	{
		printf("请输入第%d学生的成绩：",i);
		scanf("%f",&score);
		if(score>max_score)
		{
			max_score=score;
		}
	}
	printf("班级最高分是：%.2f",max_score);
	return 0;
}
