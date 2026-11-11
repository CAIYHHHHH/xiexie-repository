#include <stdio.h>
#include <math.h>//要开平方就要引入工具 
int main()
{
    double a,b,c,p;
    scanf("%lf %lf %lf",&a,&b,&c);
    p=(a+b+c)/2.0;
    double e =sqrt(p*(p-a)*(p-b)*(p-c));//sqrt(a)是开a的平方，x的y次方就是pow(x,y),结尾记得加; 
    printf("%.1lf",e);//double变量在printf里面也要%lf 
    return 0;
}
