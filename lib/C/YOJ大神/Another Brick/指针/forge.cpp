#include <stdio.h>
void search(float (*pointer)[4], int n)
{
    float *pt;
    pt=*(pointer+n);
    for(int i=0;i<4;i++)
        printf("%5.2f\t",*(pt+i));
    printf("\n");
    return;
}
int main()
{ 
    float score[ ][4]={{60,70,80,90}, {56,89,67,88},{34,78,90,66}};
    float *p; 
    int k;
    scanf("%d",&k);
    printf("The scores of No.%d are:\n",k);
    search(score,k-1);//二维数组名表示第0行的行地址
    return 0;
}
