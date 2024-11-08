#include<stdio.h>
int main()
{
    int a,ld=0,lzw=0;
    while (!feof(stdin)){
        scanf("%d",&a);
        if(a==0){
            ld+=1;
        }
        if(a==1){
            lzw+=1;
        }
        if(ld>=21&&ld>=lzw+2){
            printf("0");
            break;
        }
        if(lzw>=21&&lzw>=ld+2){
            printf("1");
            break;
        }
    }
    return 0;
}
//while (!feof(stdin)){scanf("%d,&a")}读到.in文件结尾