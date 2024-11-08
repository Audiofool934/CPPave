#include <stdio.h>

int main() {
    int cr[8] = {120, 40, 85, 50, 100, 140, 70, 100};
    int oc[8] = {0};
    int mtd[4];
    int cnt = 0;
    int Na, Nb, Nc, Nd;
    scanf("%d %d %d %d", &Na, &Nb, &Nc, &Nd);

    for (int i = 0; i < 8; i++) {
        if (cr[i] >= Na) {
            mtd[0] = i + 1;
            oc[i] = 1;
            for (int j = 0; j < 8; j++) {
                if (!oc[j] && cr[j] >= Nb) {
                    mtd[1] = j + 1;
                    oc[j] = 1;
                    for (int k = 0; k < 8; k++) {
                        if (!oc[k] && cr[k] >= Nc) {
                            mtd[2] = k + 1;
                            oc[k] = 1;
                            for (int l = 0; l < 8; l++) {
                                if (!oc[l] && cr[l] >= Nd) {
                                    mtd[3] = l + 1;
                                    printf("%d %d %d %d\n", mtd[0], mtd[1], mtd[2], mtd[3]);
                                    cnt++;
                                }
                            }
                            oc[k] = 0;
                        }
                    }
                    oc[j] = 0;
                }
            }
            oc[i] = 0;
        }
    }
//虽然是枚举，但也要有递归的想法，一个oc[]是完不成的！上一层给下一层
    if (cnt == 0) {
        printf("-1\n");
    }

    return 0;
}
/*
#include<stdio.h>
int main()
{
    int a,b,c,d,cr[9]={0,120,40,85,50,100,140,70,100},oc[9]={1,1,1,1,1,1,1,1,1},mtd[5],cnt=0;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    for(int i=1;i<=8;i++) printf("%d ",cr[i]);
    printf("\n");
    for(int i=1;i<=8;i++) printf("%d ",oc[i]);
    printf("\n");
    for(int i=1;i<=8;i++){
        if(a<=cr[i]){
            mtd[1]=i;
            oc[i]=0;
            printf("%d\n",mtd[1]);
        }
        else continue;
        for(int j=1;j<=8;j++){
            if(b<=cr[j]&&oc[j]){
                mtd[2]=j;
                oc[j]=0;
            }
            else continue;
            for(int k=1;k<=8;k++){
                if(c<=cr[k]&&oc[k]){
                    mtd[3]=k;
                    oc[k]=0;
                }
                else continue;
                for(int l=1;l<=8;l++){
                    if(d<=cr[l]&&oc[l]){
                        mtd[4]=l;
                        cnt++;
                        printf("%d %d %d %d\n",mtd[1],mtd[2],mtd[3],mtd[4]);
                    }
                }
                for(int s=1;s<=8;i++) oc[s]=1;//严重错误
            }
        }
    }
    if(cnt==0) printf("-1\n");
    return 0;
}
*/
