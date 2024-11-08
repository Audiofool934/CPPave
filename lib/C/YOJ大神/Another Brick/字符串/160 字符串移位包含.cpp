#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
    char c[30],t[30],tmp[30];
    scanf("%s%s",c,t);
    int cnt=0,n=strlen(c),lth=strlen(t);
    char C[30][30];
    for(int i=0;i<=n;i++){
        strcpy(C[i],c);
        //printf("%s\n",C[i]);    
    }
    for(int i=1;i<=n;i++){//i<=n 和 i<=n-1 n就能回到起点了！！！
        C[i][0]=C[i-1][n-1];
        for(int j=1;j<=n-1;j++){
            C[i][j]=C[i-1][j-1];
        }
        //printf("%s\n",C[i]);
        for(int j=0;j+lth<=n;j++){
            int ctp=0;
            for(int k=0;k<=lth-1;k++){
                if(t[k]==C[i][j+k]){
                    ctp++;
                }
                else break;
            }
            if(ctp==lth){
                cnt++;
                printf("true");
                break;
            }
            //printf("%s\n",t);
        }
        if(cnt) break;
    }
    if(cnt==0){
        printf("false");
    }
    return 0;
}