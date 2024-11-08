#include<stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    if(90<=a&&a<=100)
    printf("4.0\n");
    else if(86<=a&&a<=89)
    printf("3.7\n");
    else if(83<=a&&a<=85)
    printf("3.3\n");
    else if(80<=a&&a<=82)
    printf("3.0\n");
    else if(76<=a&&a<=79)
    printf("2.7\n");
    else if(73<=a&&a<=75)
    printf("2.3\n");
    else if(70<=a&&a<=72)
    printf("2.0\n");
    else if(66<=a&&a<=69)
    printf("1.7\n");
    else if(63<=a&&a<=65)
    printf("1.3\n");
    else if(60<=a&&a<=62)
    printf("1.0\n");
    else if(a<60)
    printf("0\n");
    return 0;
}
//注意if中&&的使用，不能直接if(90<=a<=100)