#include<stdio.h>
int n,output[10],fp[10]={0},a[10]={0,1,2,3,4,5,6,7,8,9};
void A(int pos){
    if(pos==n){
        for(int i=0;i<n;i++){
            printf("%d ",output[i]);
        }
        printf("\n");
    }
    for(int i=0;i<n;i++){
        if(!fp[i]){
            output[pos]=a[i];
            fp[i]=1;
            A(pos+1);
            fp[i]=0;
        }
    }
    return;
}
int main()
{
    scanf("%d",&n);
    A(0);
    return 0;
}