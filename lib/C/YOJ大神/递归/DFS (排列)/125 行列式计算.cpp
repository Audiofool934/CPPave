#include<stdio.h>
int n,det[10][10],fp[10][10]={0},output[2][10],dsum=0;
int sum=0;
int check(int row,int col){
    for(int i=1;i<=col;i++){
        if(fp[row][i]){
            return 0;
        }
    }
    return 1;
}
int verse(){
    int t=0;
    for(int i=1;i<=n-1;i++){
        for(int j=i;j<=n;j++){
            if(output[0][i]>output[0][j]){
                t++;
            }
        }
    }
    //printf(" t=%d ",t);
    if(t%2) return -1;
    else return 1;
}
int msum(){
    int mm=1;
    for(int i=1;i<=n;i++){
        //printf("%d ",output[1][i]);
        mm*=output[1][i];
    }
    //printf("\n//%d %d\n",verse(),mm);

    return verse()*mm;
}
void dete(int pos){
    if(pos==n+1){
        dsum+=msum();
    }
    for(int i=1;i<=n;i++){
        if(check(i,pos)){
            fp[i][pos]=1;
            output[1][pos]=det[i][pos];
            output[0][pos]=i;
            dete(pos+1);
            fp[i][pos]=0;
        }
    }
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&det[i][j]);
        }
    }
    dete(1);
    printf("%d",dsum);
    return 0;
}

