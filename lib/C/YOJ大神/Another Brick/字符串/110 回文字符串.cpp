#include <stdio.h>
int main() {
    char c,a[1001];
    int l=1;
    /*while ((c = getchar()) != EOF){
        l++;
        a[l]=c;
    }*/
    while((a[l]=getchar())!=EOF) l++;
    //printf("%d",l);
    int brk=1;
    for(int i=1;i<=(l-1)/2;i++){
        if(a[i]==a[l-i])
            continue;
        else{
            printf("No");
            brk=0;
            break;
        }
    }
    if(brk) printf("Yes");
    return 0;
}