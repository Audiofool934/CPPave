#include<stdio.h>
int main()
{
    long long n,q,temp;
    scanf("%ld",&n);
    long long a[n][2],c[n];
    for(int i=0;i<n;i++){
        scanf("%ld %ld",&a[i][0],&a[i][1]);
    }

    scanf("%ld",&q);
    long long b[q][2],d[q];
    for(int i=0;i<q;i++){
        scanf("%ld %ld",&b[i][0],&b[i][1]);
    }
     
    for(int i=0;i<q;i++){
        for(int l=0;l<n;l++){
            c[l]=((a[l][0])-(b[i][0]))*((a[l][0])-(b[i][0]))+((a[l][1])-(b[i][1]))*((a[l][1])-(b[i][1]));
        }
        for(int l=0;l<n-1;l++){
            for(int i=0;i<n-1-l;i++){
                if(c[i]>c[i+1]){
                    temp=c[i];
                    c[i]=c[i+1];
                    c[i+1]=temp;
                }
            }
        }
        d[i]=c[0];
    }

    for(int i=0;i<q;i++){
        printf("%ld\n",d[i]);
    }
    return 0;
}
//需要简化算法