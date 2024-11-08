#include<stdio.h>
int check;
void solve(int n,int m,int cnt){
    cnt++;
    if((cnt==m+1)&&(n%m==0)) check=1;
    if(n<m||n%m!=1||cnt>m+1) return;
    solve(n-n/m-1,m,cnt);
    return;
}
int main()
{
    int n;
        while(1){
        scanf("%d",&n);
        if(n==0) break;
        int cn=1;
        for(int i=n-1;i>=1;i--){
            check=0;
            solve(n,i,0);
            if(check){
                printf("%d\n",i);
                cn=0;
                break;
            }
        }
        if(cn) printf("no solution\n");
        }
    return 0;
}