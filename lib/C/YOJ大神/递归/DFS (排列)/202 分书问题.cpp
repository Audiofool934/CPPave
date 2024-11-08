#include<stdio.h>
int mtd=0,n,books[12][12],mtds[12]={0},output[5005][12];
void dist(int psn)
{
    if(psn==n+1){
        for(int i=1;i<=n;i++)
            output[mtd+1][i]=output[mtd][i];
        mtd++;
        return;
    }

    for(int i=1;i<=n;i++){
        if((!mtds[i])&&(books[psn][i])){
            output[mtd][psn]=i;
            mtds[i]=1;
            dist(psn+1);
            mtds[i]=0;

        }
    }
    return;
}
int main()
{
    scanf("%d",&n);
    char tmp;
    getchar();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if((tmp=getchar())=='1')
                books[i][j]=1;
            else
                books[i][j]=0;
        }
        getchar();
    }
    dist(1);
    if(mtd==0) printf("NO");
    else{
        printf("%d\n",mtd);
        for(int i=0;i<mtd;i++){
            for(int j=1;j<=n;j++){
                printf("B%d",output[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}