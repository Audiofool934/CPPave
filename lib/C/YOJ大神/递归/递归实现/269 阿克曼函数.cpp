#include<stdio.h>
int aci(int m, int n)
{
    if(m==0){
        return n+1;
    }
    if(n==0){
        return aci(m-1,1);
    }
    else{
        return aci(m-1,aci(m,n-1));
    }
}
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",aci(a,b));
    return 0;
}
//Bing:
#include <stdio.h>
int aci(int m, int n) {
    if (m == 0) {
        return n + 1;
    }
    else if (n == 0) {
        return aci(m - 1, 1);
    }
    else {
        return aci(m - 1, aci(m, n - 1));
    }
}
int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    printf("%d\n", aci(m, n));
    return 0;
}