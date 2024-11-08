#include<stdio.h>
#include<math.h>
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n+1][m+1];

    int r[n*m][3],re=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%1d",&a[i][j]);//"%1d"很聪明
            if(a[i][j]==1){
                r[re][1]=i;
                r[re][2]=j;
                re++;
            }
        }
    }
    
    int sum=0;
    for(int i=1;i<=re-1;i++){
        for(int j=1;j<=n||j<=m;j++){//第j波感染
            int brk=0;
            for(int k=-j;k<=j;k++){
                /*for(int l=-j;l<=j||abs(l)+abs(k)==j;l++){//菱形
                    printf("r[i][1]=%d r[i][2]=%d\n",r[i][1],r[i][2]);
                    printf("r[i][1]+k=%d r[i][2]+l=%d\n",r[i][1]+k,r[i][2]+l);
                    if(a[r[i][1]+k][r[i][2]+l]==0){
                        //printf("%d %d\n",r[i][1],r[i][2]);
                        //printf("k=%d l=%d\n",k,l);
                        sum+=abs(l)+abs(k);
                        brk=1;
                        break;
                    }
                }
                printf("\n");
                */
                if(r[i][1]+k<=0||r[i][1]+k>=n+1)continue;
                if(a[r[i][1]+k][r[i][2]-j-k]==0||a[r[i][1]+k][r[i][2]+j+k]==0){
                    //printf("r[i][1]=%d r[i][2]=%d\n",r[i][1],r[i][2]);
                    printf("r[%d][1]+k=%d r[%d][2]-j-k=%d\n",i,r[i][1]+k,i,r[i][2]-j-k);
                    sum+=abs(-j-k)+abs(k);
                    brk=1;
                    break;                    
                }
            }
            if(brk==1)break;
        }
    }
    printf("%d\n",sum);
}