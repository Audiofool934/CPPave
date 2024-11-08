#include<stdio.h>
int main()
{
    char weeiday[7][10]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    int d1,d2;
    scanf("%d %d",&d1,&d2);
    if(d1==7)
    {
        printf("Monday\n");
    }
    else
    {
        printf("%s\n",weeiday[d1]);
    }
    if(d2==1)
    {
        printf("Sunday\n");
    }
    else
    {
        printf("%s\n",weeiday[d2-2]);
    }
    return 0;
}
//注意数组是从0开始，而输入是从1开始；注意两个if语句！全面性