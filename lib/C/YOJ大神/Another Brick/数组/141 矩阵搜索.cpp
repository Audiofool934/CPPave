// 141 矩阵搜索
#include<stdio.h>
struct val{
    int i,j;
    int v;
};
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    getchar();
    int mtx[n+2][m+2];
    for(int i=0;i<=n+1;i++) {mtx[i][0]=0;mtx[i][m+1]=0;}
    for(int i=0;i<=m+1;i++) {mtx[0][i]=0;mtx[n+1][i]=0;}
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&mtx[i][j]);
        }
    }
    struct val line[n*m+1];
    int t=0;
    struct val va[n+1][m+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            va[i][j].v=mtx[i][j]+mtx[i-1][j]+mtx[i+1][j]+mtx[i][j+1]+mtx[i][j-1];
            va[i][j].i=i;
            va[i][j].j=j;
            line[j+t]=va[i][j];
        }
        t+=m;
    }

    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d ",va[i][j].v);
        }
        printf("\n");
    }*/

    /*struct val line[n*m+1];
    int t=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            line[j+t]=va[i][j];
        }
        t+=m;
    }*/ //这段与前面重复，浪费时间，更改后就对了！

    /*for(int i=1;i<=n*m;i++){
        printf("%d ",line[i].v);
    }
    printf("\n");*/

    struct val tmp;
    for(int i=1;i<=n*m-1;i++){
        for(int j=1;j<=n*m-i;j++){
            //printf("line[j].v=%d line[j+1].v=%d\n",line[j].v,line[j+1].v);
            if(line[j].v<line[j+1].v){
                tmp=line[j+1];
                line[j+1]=line[j];
                line[j]=tmp;
            }
            //printf("line[j].v=%d line[j+1].v=%d\n",line[j].v,line[j+1].v);
        }
    }

    /*for(int i=1;i<=n*m;i++){
        printf("%d ",line[i].v);
    }
    printf("\n");*/

    int num=0;
    for(int i=1;i<=n*m-1;i++){
        if(line[i].v==line[1].v){
            num++;
        }
        else break;
    }

    printf("%d %d\n",line[1].v,num);
    for(int i=1;i<=num;i++){
        printf("%d %d\n",line[i].i-1,line[i].j-1);//题目要求从0开始
    }
    return 0;
}