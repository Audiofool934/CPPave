#include<stdio.h>
int n,m,p,a[6][6],b[6][6];
int sum(int i,int j){
    int sm=0;
    for(int k=1;k<=p;k++){
        sm+=a[i][k]*b[k][j];
    }
    return sm;
}
void MatrixM(){
    
    int c[6][6]={0};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            c[i][j]=sum(i,j);
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }

    return;
}
int main()
{
    
    scanf("%d%d%d",&n,&p,&m);
    //a[][] n行 p列, b[][] p行 m列
    for(int i=1;i<=n;i++){
        for(int j=1;j<=p;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=p;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&b[i][j]);
        }
    }
    MatrixM();
    
    return 0;
}