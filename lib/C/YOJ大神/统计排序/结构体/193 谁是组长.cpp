#include<stdio.h>
#include<iostream>
using namespace std;
struct pp{
    int nm;
    int sc;
};
int main()
{
    long n,m,p;
    scanf("%ld%ld",&n,&m);
    struct pp ppl[m+1];
    for(int i=1;i<=m;i++){
        ppl[i].sc=0;
        ppl[i].nm=0;
    } 
    int tt,nn=0;
    for(int i=1;i<=m;i++){
        tt=0;
        scanf("%ld",&p);
        //printf("%d %d\n",ppl[nn].nm,ppl[nn].sc);
        for(int j=1;j<=i;j++){
            if(ppl[j].nm==p){
                ppl[j].sc++;
                tt++;
                break;
            }
        }
        if(tt!=0) continue;
        else{
            nn++;
            ppl[nn].nm=p;
            ppl[nn].sc++;
            //printf("%d %d\n",ppl[nn].nm,ppl[nn].sc);
        }
    }
    /*printf("nn=%d\n",nn);
    for(int i=1;i<=nn;i++)
    {
        printf("%d %d\n",ppl[i].nm,ppl[i].sc);
    }
    printf("heyu\n");*/
    for(int i=1;i<=nn-1;i++){
        for(int j=1;j<=nn-i;j++){
            if(ppl[j].sc<ppl[j+1].sc){
                swap(ppl[j],ppl[j+1]);
            }
        }
    }
    if(ppl[1].sc>m/2) printf("%d",ppl[1].nm);
    else printf("-1");
    return 0;
}