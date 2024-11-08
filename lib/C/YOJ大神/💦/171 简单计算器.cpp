#include<stdio.h>
int main()
{
    long long a,b;
    char c;
    scanf("%ld %ld %c",&a,&b,&c);
    if((int)c=='+'){
        printf("%ld\n",a+b);
    }
    else if((int)c=='-'){
        printf("%ld\n",a-b);
    }
    else if((int)c=='*'){
        printf("%ld\n",a*b);
    }
    else if((int)c=='/'){
        if(b==0){
            printf("NO");
        }
        else{
            double c=a,d=b;
            printf("%.0f\n",c/d);
        }
    }
    else if((int)c=='%'){
        if(b==0){
            printf("NO");
        }
        else{
            printf("%ld\n",a%b);
        }
    }
    else{
        printf("NO");
    }
    return 0;
}
//用switch会更简洁
//注意特殊情况（分母不能为零）；强制类型转换