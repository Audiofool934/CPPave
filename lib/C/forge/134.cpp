#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int ans[5],guess[n+1][7],output[5];
    for(int i=1;i<=n;i++){
        getchar();
        for(int j=1;j<=4;j++){
            guess[i][j]=getchar()-48;
        }
        scanf("%d%d",&guess[i][5],&guess[i][6]);
    }
    int find=0;
    for(int i=1;i<=9;i++){ans[1]=i;
        for(int j=0;j<=9;j++){ans[2]=j;
            for(int k=0;k<=9;k++){ans[3]=k;
                for(int l=0;l<=9;l++){ans[4]=l;
                    for(int o=1;o<=n;o++){
                        if(ans[1]==3&&ans[2]==5&&ans[3]==8&&ans[4]==5){
                            printf("Yes\n");
                        }
                        int cnt5=0,cnt6=0,fp[4]={0};
                        for(int p=1;p<=4;p++){
                            if(ans[p]==guess[o][p]) cnt6++;
                            for(int q=1;q<=4;q++){         
                                if(!fp[q]&&ans[p]==guess[o][q]){
                                    fp[q]=1;
                                    cnt5++;
                                }
                            }
                        }
                        if(cnt5!=guess[o][5]||cnt6!=guess[o][6]){
                            break;
                        }
                        if(o==n) {
                            for(int i=1;i<=4;i++){
                                output[i]=ans[i];
                            }
                            find++;
                        }
                    }
                }
            }
        }
    }
    if(find==1){
        for(int i=1;i<=4;i++){
            printf("%d",output[i]);
        }
    }
    else{
        printf("Not sure");
    }
    return 0;
}