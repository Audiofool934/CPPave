#include<stdio.h>
int n,goal,seq[15][15],fp[15]={0},output[15],tmp1[15],hold=0;

int suma(int a[],int len){
    int sum=0;
    for(int i=1;i<=len;i++){
        sum+=a[i];
    }
    return sum;
}
//check(1,n,seq[1]);
int check(int level,int len,int a[]){
    int sum=suma(seq[level],len);
    if(sum==goal&&len==1){
        hold=1;
        return 1;
    }
    if(len==1) return 0;
    for(int i=1;i<=len-1;i++){
        tmp1[i]=seq[level][i]+seq[level][i+1];
    }
    level++;
    for(int i=1;i<=len-1;i++){
        seq[level][i]=tmp1[i];
    }
    return check(level,len-1,seq[level]);
}

void A(int pos){
    if(hold||pos==n+1){
        /*printf("pos=%d\n",pos);
        for(int i=1;i<=n;i++){
            printf("%d",seq[1][i]);
        }
        printf("\n");*/
        return;
    }
    for(int i=1;i<=10;i++){
        if(fp[i]==0){
            seq[1][pos]=i;
            fp[i]=1;
            A(pos+1);
            if(hold) return;
            if(check(1,n,seq[1])){
                for(int i=1;i<=n;i++){
                    printf("%d ",seq[1][i]);
                }
                return;
            }

            fp[i]=0;
        }
    }
}
int main()
{
    scanf("%d%d",&n,&goal);
    A(1);
    return 0;
    
}