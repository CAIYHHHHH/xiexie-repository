//第一天，骑士收到一枚金币；之后两天（第二天和第三天），每天收到两枚金币；之后三天（第四、五、六天），
//每天收到三枚金币；之后四天（第七、八、九、十天），每天收到四枚金币……；
//这种工资发放模式会一直这样延续下去：当连续 n 天每天收到 n 枚金币后，骑士会在之后的连续 n+1 天里，每天收到 n+1 枚金币。
//请计算在前 k 天里，骑士一共获得了多少金币。
#include<stdio.h>
int main()
{
    int k,i;
    int coin=1;
    int days=0;
    int sum=0;
    scanf("%d",&k);
    while(days<k){
    for(i=1;i<=coin;i++)
    {
        sum+=coin;
        days++;
        if(days==k)
        {
            break;
        }
    }
        coin++;
    }
    printf("%d",sum);
}
//金币与天数（括号内）相等 
