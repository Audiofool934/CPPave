#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int a[n+1][n+1];//数组纯属南辕北辙
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=i;j>=1;j--){
            cnt++;
            if(cnt>m)break;
            //printf("%d",cnt);
            //a[i][j]='A'+j-1;
            printf("%c",'A'+j-1);
        }  
        for(int j=i+1;j<=m;j++){
            cnt++;
            if(cnt>m)break;
            //printf("%d",cnt);
            //a[i][j]='A'+j-i;
            printf("%c",'A'+j-i);
        }
        printf("\n");
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%c",a[i][j]);
        }
        printf("\n");
    }*/
    return 0;
}