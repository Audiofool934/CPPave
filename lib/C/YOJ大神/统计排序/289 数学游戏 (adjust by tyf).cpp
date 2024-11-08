#include<stdio.h>
long X(int a,int b,int c,int d,int e,int x)
{
    long y=a*x*x*x*x+b*x*x*x+c*x*x+d*x+e;
    return y;
}
int main()
{
    int n,i,a,b,c,d,e,x,s_pp=0,sum_pp=0,s_i=0,sum_i=0;
    long ans1,ans2;
    scanf("%d%d",&n,&i);
    for(int i=0;i<n;i++){
        scanf("%d%d%d%d%d%d%ld%ld",&a,&b,&c,&d,&e,&x,&ans1,&ans2);
        if(ans1==X(a,b,c,d,e,x)){
            s_pp+=1;//分数
            sum_pp+=1;//连续答对的题目数
            if(sum_pp>i){
                s_pp+=(sum_pp-i);
            }
        }
        if(ans1!=X(a,b,c,d,e,x)){
            sum_pp=0;//连续答对题目数清零
        }
        if(ans2==X(a,b,c,d,e,x)){
            s_i+=1;
            sum_i+=1;
                if(sum_i>i){
                    s_i+=(sum_i-i);
                }
        }
        if(ans2!=X(a,b,c,d,e,x)){
            sum_i=0;
        }
    }
    printf("\n");
    printf("%d %d\n",s_pp,s_i);
    return 0;
}

#include<stdio.h>
long X(int a,int b,int c,int d,int e,int x)
{
    long y=a*x*x*x*x+b*x*x*x+c*x*x+d*x+e;
    return y;
}
int main()
{
    int n,i,a,b,c,d,e,x,s_pp=0,sum_pp=0,s_i=0,sum_i=0;
    long ans1,ans2;
    scanf("%d%d",&n,&i);
    for(int i=0;i<n;i++){
        scanf("%d%d%d%d%d%d%ld%ld",&a,&b,&c,&d,&e,&x,&ans1,&ans2);
        if(ans1==X(a,b,c,d,e,x)){
            s_pp+=1;//分数
            sum_pp+=1;//连续答对的题目数
            if(i==n-1){//最后一次是正确的情况下的加分奖励
                if(sum_pp>i){
                    s_pp+=(sum_pp-i);
                }
            }
        }
        if(ans1!=X(a,b,c,d,e,x)){
            if(sum_pp>i){//答错之后判断是否有之前的加分奖励
                s_pp+=(sum_pp-i);
            }
            sum_pp=0;//连续答对题目数清零
        }
        if(ans2==X(a,b,c,d,e,x)){
            s_i+=1;
            sum_i+=1;
            if(i==n-1){
                if(sum_i>i){
                    s_i+=(sum_i-i);
                }
            }
        }
        if(ans2!=X(a,b,c,d,e,x)){
            if(sum_i>i){
                s_i+=(sum_i-i);
            }
            sum_i=0;
        }
    }
    printf("\n");
    printf("%d %d\n",s_pp,s_i);
    return 0;
}
//对比两段代码，到底是哪里导致了理解偏差？