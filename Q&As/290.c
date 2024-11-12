#include<stdio.h>

struct costumer {
    int nm;
    int t[101];
};

int main()
{
    int n;
    scanf("%d",&n);
    struct costumer cms[n+1];
    for(int i=1;i<=n;i++){
        scanf("%d",&cms[i].nm);
        for(int j=1;j<=cms[i].nm;j++){
            scanf("%d",&cms[i].t[j]);
        }
    }
    
    /*for(int i=1;i<=n;i++){
        printf("%d\n",cms[i].nm);
    }*/

    int a[cms[1].nm];
    int NO=1,cnt=0,mm=0;
        for(int i=1;i<=cms[1].nm;i++){
            a[i]=0;
            for(int j=2;j<=n;j++){
                for(int k=1;k<=cms[j].nm;k++){
                    if(cms[1].t[i]==cms[j].t[k]){
                        mm++;
                        NO=0;
                    }
                }
            }
            //printf("mm=%d\n",mm);
            if(mm==n-1){
                cnt++;
                a[cnt]=cms[1].t[i];
                //printf("cms[1].t[i]=%d\n",cms[1].t[i]);
            }
            mm=0;
        }
    if(NO){
        printf("NO\n");
    }
    else{
        for(int i=1;i<=cnt-1;i++){
            for(int j=1;j<=cnt-i;j++){
                if(a[j]>a[j+1])
                    swap(a[j],a[j+1]);
            }
        }
        for(int i=1;i<=cnt;i++)
            printf("%d ",a[i]);
    }

}