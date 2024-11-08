#include<stdio.h>
int a[10000]={0},r[10000],pos=0,yes=0,posbg,posed;
//假分数处理
int z(int n,int m){
    int itg=n/m;
    printf("%d.",itg);
    return n-(n/m)*m;
}
//循环节
int loop(int n){
    for(int i=1;i<n;i++){
        if(r[i]==r[n]){
            posbg=i;
            posed=n;
            return 1;
        }
    }
    return 0;
}

//模拟除法
void dvd(int n,int m)
{
    //能除尽
    if(n==0){
        yes=1;
        return;
    }
    //无限循环
    if(loop(pos)) return;//找到循环节
    while(n<m){
        n*=10;
        pos++;
    }
    a[pos]=n/m;
    r[pos]=n-m*a[pos];
    dvd(r[pos],m);
    return;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int nn=z(n,m);
    dvd(nn,m);
    if(yes){
        for(int i=1;i<=pos;i++){
            printf("%d",a[i]);
        }
        if(pos==0){
            printf("0");
        }
    }
    else{
        while(posbg>=0&&a[posbg]==a[posed]){
            posbg--;
            posed--;
        }
        for(int i=1;i<=posbg;i++){
            printf("%d",a[i]);
        }
        printf("(");
        for(int i=posbg+1;i<=posed;i++){
            printf("%d",a[i]);
        }
        printf(")");
    }
    return 0;
}
/* by ymx
#include<stdio.h>
#include<string.h>
int look_up(int x,int *bank,int l)
{
    for(int i=0;i<=l;i++)
    {
        if(bank[i]==x)return i;
    }
    return -1;
}
void division(int p,int q,char* ans1,char* loop)
{
    int record_p[10000]={0};
    for(int i=0;;i++)
    {
        record_p[i]=p;
        int digit=(10*p)/q;
        ans1[i]=digit+'0';
        if(digit==0)p*=10;
        else p=10*p-digit*q;
        if(p==0)
        {
            ans1[i+1]='\0';
            return;
        }
        int k=look_up(p,record_p,i);
        if(k==-1)continue;
        else{
            strncpy(loop,ans1+k,i-k+1);
            *(ans1+k)='\0';
            return;
        }
    }
}
int main()
{
    int p,q;
    scanf("%d%d",&p,&q);
    int Z=0;//整数部分
    if(p>=q)
    {
        Z=p/q;
        p%=q;
    }
    if(q==0)
    {
        printf("%d.0",Z);
        return 0;
    }
    char ans1[10000]="\0",loop[10000]="\0";
    division(p,q,ans1,loop);
    if(strlen(loop)>0)printf("%d.%s(%s)\n",Z,ans1,loop);
    else printf("%d.%s\n",Z,ans1);
    return 0;
}*/