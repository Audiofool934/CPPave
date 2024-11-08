#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;
typedef struct{
    char cc;
    int cnt;
}abcde;
int cmp(const void* aa,const void* bb){
    abcde* a=(abcde*)aa;
    abcde* b=(abcde*)bb;
    return b->cnt-a->cnt;
}
int main()
{
    //a 97 z 122; A 65 Z 90
    char c[255];
    gets(c);
    int n=strlen(c);
    abcde abc[26];
    for(int i=0;i<26;i++){
        abc[i].cc=97+i;
        abc[i].cnt=0;
    }
    for(int i=0;i<n;i++){
        if((int)c[i]>93)//如果是小写字母
        {
            c[i]-=32;
        }
        //printf("%d ",c[i]-65);
        abc[(int)c[i]-65].cnt++;
    }
    qsort(abc,26,sizeof(abcde),cmp);
    for(int i=0;i<26;i++){
        if(abc[i].cnt==0)break;
        printf("%c %d\n",abc[i].cc,abc[i].cnt);
    }
    return 0;
}



#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;
struct abcde{
    char cc;
    int cnt;
};
int main()
{
    //a 97 z 122; A 65 Z 90
    char c[255];
    gets(c);
    int n=strlen(c);
    struct abcde abc[26];
    for(int i=0;i<26;i++){
        abc[i].cc=97+i;
        abc[i].cnt=0;
    }
    for(int i=0;i<n;i++){
        if((int)c[i]>93)//如果是小写字母
        {
            c[i]-=32;
        }
        //printf("%d ",c[i]-65);
        abc[(int)c[i]-65].cnt++;
    }
    for(int i=0;i<26-1;i++){
        for(int j=0;j<26-i-1;j++){
            if(abc[j].cnt<abc[j+1].cnt){
                swap(abc[j],abc[j+1]);
            }
        }
    }
    for(int i=0;i<26;i++){
        if(abc[i].cnt==0)break;
        printf("%c %d\n",abc[i].cc,abc[i].cnt);
    }
    return 0;
}