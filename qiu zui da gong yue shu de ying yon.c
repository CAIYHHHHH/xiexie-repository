#include<stdio.h>
int gys(int x,int y){
    while(y!=0){
        int temp=x%y;
        x=y;
        y=temp;
    }
    return x;
}
int main()
{
    int a,b,c,n;
    scanf("%d %d %d",&a,&b,&c);
    if(a>b){n=a;a=b;b=n;}
    if(a>c){n=a;a=c;c=n;}
    if(b>c){n=b;b=c;c=n;}
    int e;
    e=gys(a,c);
    printf("%d/%d",a/e,c/e);
}
