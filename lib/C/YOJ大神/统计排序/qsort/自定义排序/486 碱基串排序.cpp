//思路1——模拟快排？但是只能60/100
//思路2——倒着排序，快排还不太会操作（冒泡可AC）
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
char rule[4];
struct line{
    char line[25];
    int tag[25];
};
void tagger(char line[],int tag[],int len){
    for(int i=0;i<len;i++){
        for(int j=0;j<4;j++)
            if(line[i]==rule[j]){
                tag[i]=j;
            }
    }
}
/*int sort(const void* a, const void* b){
    long long diff = ((struct line*)a)->tag - ((struct line*)b)->tag;
    if(((struct line*)a)->tag - ((struct line*)b)->tag > 0) return -1;
    else if(((struct line*)a)->tag - ((struct line*)b)->tag < 0) return 1;
    else return 0;
}*/
int main()
{
    int m,n;
    scanf("%d",&m);
    scanf("%s",rule);
    struct line input[m+1];
    for(int i=0;i<=m-1;i++){
        scanf("%s",input[i].line);
        n=strlen(input[i].line);
        tagger(input[i].line,input[i].tag,n);
    }
    
    /*for(int   i=0;i<=m-1;i++){
        for(int j=0;j<=n-1;j++){
            printf("%d ",input[i].tag[j]);
        }
        printf("\n");
    }*/
    
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<m-1;j++){
            for(int k=0;k<m-1-j;k++){
                if(input[k].tag[i]>input[k+1].tag[i]){
                    swap(input[k],input[k+1]);
                }
            }
        }
    }
    //qsort(input,m,sizeof(struct line),sort);
    for(int i=0;i<=m-1;i++){
        printf("%s\n",input[i].line);
    }

    return 0;
}

//思路3——by ymx，两行间按照行整体排序
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
char rule[4];
struct line{
    char line[25];
    int tag[25];
};
void tagger(char line[],int tag[],int len){
    for(int i=0;i<len;i++){
        for(int j=0;j<4;j++)
            if(line[i]==rule[j]){
                tag[i]=j;
            }
    }
}
int compare(int tag1[],int tag2[],int len){
    for(int i=0;i<len;i++){
        if(tag1[i]<tag2[i]) return 0;//优先，不交换
        if(tag1[i]>tag2[i]) return 1;
    }
    return 0;
}
int main()
{
    int m,n;
    scanf("%d",&m);
    scanf("%s",rule);
    struct line input[m+1];
    for(int i=0;i<=m-1;i++){
        scanf("%s",input[i].line);
        n=strlen(input[i].line);
        tagger(input[i].line,input[i].tag,n);
    }
    
    /*for(int i=0;i<=m-1;i++){
        for(int j=0;j<=n-1;j++){
            printf("%d ",input[i].tag[j]);
        }
        printf("\n");
    }*/
    
    for(int i=0;i<m-1;i++){
        for(int j=0;j<m-i-1;j++){
            if(compare(input[j].tag,input[j+1].tag,n)){
                swap(input[j],input[j+1]);
            }
        }
    }
    
    for(int i=0;i<=m-1;i++){
        printf("%s\n",input[i].line);
    }

    return 0;
}
