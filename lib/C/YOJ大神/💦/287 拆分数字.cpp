#include<stdio.h>
int main()
{
    int N;
    scanf("%d",&N);
    if(N>=1000)
    {
        printf("%d,%d,%d,%d,4\n",N%10,(N/10)%10,(N/100)%10,(N/1000)%10);
    }
    if(1000>N&&N>=100)
    {
        printf("%d,%d,%d,3\n",N%10,(N/10)%10,(N/100)%10);
    }
    if(100>N&&N>=10)
    {
        printf("%d,%d,2\n",N%10,(N/10)%10);
    }
    if(10>N)
    {
        printf("%d,1\n",N%10);
    }
}
//简单方法？