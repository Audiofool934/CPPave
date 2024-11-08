#include<stdio.h>
#include<iostream>
using namespace std;
struct words{
    int lth;
    char w[55];
};
int main()
{
    char book[10000];
    struct words word[205];
    int cnt=1,t=1,k=0,tt=0,A=0,m;
    while((book[t]=getchar())!=EOF) t++;
    book[0]=' ';
    int a_words=1;
    for(int i=0;i<=t-1;i++){
        if(book[i]==' '&&book[i+1]!=' '){
            while(book[i+1]!=' '&&i+1<=t){
                k++;
                word[a_words].w[k]=book[i+1];
                if(book[i+1]=='A'||book[i+1]=='a'){
                    A=1;
                    cnt=0;
                }
                i++;
            }
            word[a_words].lth=k;
            if(A){
                a_words++;
                A=0;
            }
            k=0;
        }
    }
    int longA=-1;
    if(cnt) printf("-1");
    else{
        for(int i=1;i<=a_words;i++){
            longA=max(longA,word[i].lth);
        }
        for(int i=1;i<=a_words;i++){
            if(longA==word[i].lth){
                for(int j=1;j<=word[i].lth;j++){
                    printf("%c",word[i].w[j]);
                }
                break;
            }
        }
    }
    return 0;
}

#include<stdio.h>
#include<math.h>
#include<iostream>
#include<string.h>
using namespace std;
struct words{
    int lth;
    char w[55];
};
int main()
{
    char book[10000];
    struct words word[205];
    int cnt=1,t=1,k=0,tt=0,A=0,m;
    while((book[t]=getchar())!=EOF) t++;
    /*
    for(int i=1;i<=t;i++){
        printf("%c",book[i]);
    }
    printf("\n");
    */
    book[0]=' ';
    int a_words=1;
    for(int i=0;i<=t-1;i++){
        if(book[i]==' '&&book[i+1]!=' '){//第一个单词？
            //printf("进入if\n");
            while(book[i+1]!=' '&&i+1<=t){
                k++;
                word[a_words].w[k]=book[i+1];
                if(book[i+1]=='A'||book[i+1]=='a'){
                    A=1;
                    cnt=0;
                }
                i++;
                //printf("1 ");
                //printf("%c",book[i+1]);
            }
            word[a_words].lth=k;
            /*
            printf("a_words=%d\n",a_words);
            printf("word[a_words].lth=%d\n",word[a_words].lth);
            for(int j=1;j<=word[a_words].lth;j++){
                printf("%c",word[a_words].w[j]);
            }
            printf("\n");
            */
            if(A){
                a_words++;
                /*puts(word[0]);
                for(int s=1;s<=m;s++){
                    printf("%c",word[s]);
                }
                printf(" ");*/
                A=0;
            }
            k=0;
        }
    }
    int longA=-1;
    if(cnt) printf("-1");
    else{
        for(int i=1;i<=a_words;i++){
            longA=max(longA,word[i].lth);
        }
        //printf("longA=%d\n",longA);
        for(int i=1;i<=a_words;i++){
            if(longA==word[i].lth){
                for(int j=1;j<=word[i].lth;j++){
                    printf("%c",word[i].w[j]);
                }
                break;
            }
        }
    }
    return 0;
}