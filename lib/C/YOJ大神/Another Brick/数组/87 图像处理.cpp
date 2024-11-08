#include<stdio.h>
#include<math.h>
struct pix{
    int Ri;int Gi;int Bi;
};
int main(void)
{
    int n,m,hi=0;
    char x,y,z;
    scanf("%d%d",&n,&m);
    getchar();
    struct pix pixs[n+2][m+2][1000];//注意控制内存～
    //输入（要命！）
    for(int i=1;i<=n;i++){
        for(int l=1;l<=m;l++){
            getchar();getchar();
            scanf("%d",&pixs[i][l][1].Ri);
            getchar();getchar();
            scanf("%d",&pixs[i][l][1].Gi);
            getchar();getchar();
            scanf("%d",&pixs[i][l][1].Bi);
        }
        getchar();
    }
    while(1){
        int zero=0;
        hi++;
        for(int i=1;i<=n;i++){
            for(int l=1;l<=m;l++){
                pixs[i][l][hi+1].Ri=pixs[i][l][hi].Ri;
                pixs[i][l][hi+1].Gi=pixs[i][l][hi].Gi;
                pixs[i][l][hi+1].Bi=pixs[i][l][hi].Bi;
                if(pixs[i][l][hi].Ri==0&&pixs[i][l][hi].Gi==0&&pixs[i][l][hi].Bi==0){
                    zero++;
                    int sumR=0,sumG=0,sumB=0,sum=0;
                    if(pixs[i-1][l][hi].Ri!=0||pixs[i-1][l][hi].Gi!=0||pixs[i-1][l][hi].Bi!=0) sum+=1;
                    if(pixs[i+1][l][hi].Ri!=0||pixs[i+1][l][hi].Gi!=0||pixs[i+1][l][hi].Bi!=0) sum+=1;
                    if(pixs[i][l+1][hi].Ri!=0||pixs[i][l+1][hi].Gi!=0||pixs[i][l+1][hi].Bi!=0) sum+=1;
                    if(pixs[i][l-1][hi].Ri!=0||pixs[i][l-1][hi].Gi!=0||pixs[i][l-1][hi].Bi!=0) sum+=1;
                    
                    sumR+=pixs[i-1][l][hi].Ri+pixs[i+1][l][hi].Ri+pixs[i][l+1][hi].Ri+pixs[i][l-1][hi].Ri;
                    sumG+=pixs[i-1][l][hi].Gi+pixs[i+1][l][hi].Gi+pixs[i][l+1][hi].Gi+pixs[i][l-1][hi].Gi;
                    sumB+=pixs[i-1][l][hi].Bi+pixs[i+1][l][hi].Bi+pixs[i][l+1][hi].Bi+pixs[i][l-1][hi].Bi;
                    
                    if(sumR==0&&sumG==0&&sumB==0){
                        pixs[i][l][hi+1].Ri=0;
                        pixs[i][l][hi+1].Gi=0;
                        pixs[i][l][hi+1].Bi=0;
                    }
                    else{
                        pixs[i][l][hi+1].Ri=ceil((double)sumR/(double)sum);
                        pixs[i][l][hi+1].Gi=ceil((double)sumG/(double)sum);
                        pixs[i][l][hi+1].Bi=ceil((double)sumB/(double)sum);
                    }
                }
            }
        }
        if(zero==m*n) break;//注意特殊情况
        int bh=0;
        for(int i=1;i<=n;i++)
            for(int l=1;l<=m;l++)
                if(pixs[i][l][hi].Ri==0&&pixs[i][l][hi].Gi==0&&pixs[i][l][hi].Bi==0)//注意这里是hi——联系好while中的hi++
                    bh++;
        if(bh==0) break;
    }
    for(int i=1;i<=n;i++){
        for(int l=1;l<=m;l++){
            printf("R %d G %d B %d ",pixs[i][l][hi].Ri,pixs[i][l][hi].Gi,pixs[i][l][hi].Bi);
        }
        printf("\n");
    }
}
/*调试
#include<stdio.h>
#include<math.h>
struct pix{
    int Ri;
    int Gi;
    int Bi;
};
int main(void)
{
    int n,m,hi=0;
    char x,y,z;
    scanf("%d%d",&n,&m);
    getchar();
    struct pix pixs[n+2][m+2][1000];//数组的“边界”是0
    //初始化——事实证明这是最坑的一步——直接超时
    for(int k=0;k<=m*n+1;k++){
        for(int i=0;i<=n+1;i++){
            for(int l=0;l<=m+1;l++){
                pixs[i][l][k].Ri=0;
                pixs[i][l][k].Gi=0;
                pixs[i][l][k].Bi=0;
            }
        }
    }
    for(int i=1;i<=n;i++){//要命的输入输出！
        for(int l=1;l<=m;l++){
            //scanf("%c%d%c%d%c%d\n",&x,&pixs[i][l][1].Ri,&y,&pixs[i][l][1].Gi,&z,&pixs[i][l][1].Bi);
            getchar();getchar();
            scanf("%d",&pixs[i][l][1].Ri);
            getchar();getchar();
            scanf("%d",&pixs[i][l][1].Gi);
            getchar();getchar();
            scanf("%d",&pixs[i][l][1].Bi);
        }
        getchar();
    }
    for(int i=1;i<=n;i++){
        for(int l=1;l<=m;l++){
            printf("R %d G %d B %d ",pixs[i][l][1].Ri,pixs[i][l][1].Gi,pixs[i][l][1].Bi);
        }
        printf("\n");
    }
    //又是一步浪费时间的“初始化”...——应该算作调试的一部分
    for(int k=1;k<=1000;k++){
        for(int i=1;i<=n;i++){
            for(int l=1;l<=m;l++){
                pixs[i][l][k].Ri=pixs[i][l][1].Ri;
                pixs[i][l][k].Gi=pixs[i][l][1].Gi;
                pixs[i][l][k].Bi=pixs[i][l][1].Bi;
            }
        }
    }
    for(int i=0;i<=n+1;i++){
        for(int l=0;l<=m+1;l++){
            printf("R %d G %d B %d ",pixs[i][l][1].Ri,pixs[i][l][1].Gi,pixs[i][l][1].Bi);
        }
        printf("\n");
    }
    int zz=0;
    for(int i=1;i<=n;i++){
        for(int l=1;l<=m;l++){
            if(pixs[i][l][1].Ri==0&&pixs[i][l][1].Gi==0&&pixs[i][l][1].Bi==0)
                zz++;
        }
    }
    while(1){
        hi++;
        for(int i=1;i<=n;i++){
            for(int l=1;l<=m;l++){
                pixs[i][l][hi+1].Ri=pixs[i][l][hi].Ri;
                pixs[i][l][hi+1].Gi=pixs[i][l][hi].Gi;
                pixs[i][l][hi+1].Bi=pixs[i][l][hi].Bi;
                if(pixs[i][l][hi].Ri==0&&pixs[i][l][hi].Gi==0&&pixs[i][l][hi].Bi==0){
                    //第hi层修复
                    int sumR=0,sumG=0,sumB=0,sum=0;
                    //printf("%d %d %d\n",pixs[i][l][hi].Ri,pixs[i][l][hi].Gi,pixs[i][l][hi].Bi);
                    //审题 上下左右...
                    if(pixs[i-1][l][hi].Ri!=0||pixs[i-1][l][hi].Gi!=0||pixs[i-1][l][hi].Bi!=0) sum+=1;
                    if(pixs[i+1][l][hi].Ri!=0||pixs[i+1][l][hi].Gi!=0||pixs[i+1][l][hi].Bi!=0) sum+=1;
                    if(pixs[i][l+1][hi].Ri!=0||pixs[i][l+1][hi].Gi!=0||pixs[i][l+1][hi].Bi!=0) sum+=1;
                    if(pixs[i][l-1][hi].Ri!=0||pixs[i][l-1][hi].Gi!=0||pixs[i][l-1][hi].Bi!=0) sum+=1;
                    
                    sumR+=pixs[i-1][l][hi].Ri+pixs[i+1][l][hi].Ri+pixs[i][l+1][hi].Ri+pixs[i][l-1][hi].Ri;
                    sumG+=pixs[i-1][l][hi].Gi+pixs[i+1][l][hi].Gi+pixs[i][l+1][hi].Gi+pixs[i][l-1][hi].Gi;
                    sumB+=pixs[i-1][l][hi].Bi+pixs[i+1][l][hi].Bi+pixs[i][l+1][hi].Bi+pixs[i][l-1][hi].Bi;
                    
                    //printf("hi=%d\n",hi);
                    //printf("%d %d %d\n",sumR,sumG,sumB);
                    
                    if(sumR==0&&sumG==0&&sumB==0){
                        pixs[i][l][hi+1].Ri=0;
                        pixs[i][l][hi+1].Gi=0;
                        pixs[i][l][hi+1].Bi=0;
                    }
                    else{
                        pixs[i][l][hi+1].Ri=ceil((double)sumR/(double)sum);
                        pixs[i][l][hi+1].Gi=ceil((double)sumG/(double)sum);
                        pixs[i][l][hi+1].Bi=ceil((double)sumB/(double)sum);
                    }
                    for(int i=1;i<=n;i++){
                        for(int l=1;l<=m;l++){
                            printf("R %d G %d B %d ",pixs[i][l][hi+1].Ri,pixs[i][l][hi+1].Gi,pixs[i][l][hi+1].Bi);
                        }
                        printf("\n");
                    }
                }
            }
        }
        //breakhold
        int bh=0;
        for(int i=1;i<=n;i++){
            for(int l=1;l<=m;l++){
                if(pixs[i][l][hi].Ri==0&&pixs[i][l][hi].Gi==0&&pixs[i][l][hi].Bi==0){
                    bh++;
                }
            }
        }
        if(bh==0) break;
    }

    for(int k=1;k<=hi;k++){
        printf("k= %d\n",k);
        for(int i=1;i<=n;i++){
            for(int l=1;l<=m;l++){
                printf("R %d G %d B %d ",pixs[i][l][k].Ri,pixs[i][l][k].Gi,pixs[i][l][k].Bi);
            }
            printf("\n");
        }
        printf("\n");
    }
    
    if(zz==m*n){
        for(int i=1;i<=n;i++){
            for(int l=1;l<=m;l++){
                printf("R 0 G 0 B 0 ");
            }
            printf("\n");
        }
    }
    else{
        for(int i=1;i<=n;i++){
            for(int l=1;l<=m;l++){
                printf("R %d G %d B %d ",pixs[i][l][hi].Ri,pixs[i][l][hi].Gi,pixs[i][l][hi].Bi);
            }
            printf("\n");
        }
    }
}
*/