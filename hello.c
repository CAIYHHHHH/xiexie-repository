#include <stdio.h>

int main()
{
double inch = 0;
double feet = 0;
printf("¼¸Ó¢³ß£¨¿Õ¸ñ£©¼¸Ó¢´ç£º");
scanf("%lf %lf",&inch,&feet);
printf("%f\n",((inch+feet/12)*0.3048));
return 0; 
 
}

