#include<stdio.h>
#include<string.h>
int n1,n2,abc1[26]={0},abc2[26]={0},no;
char goal[205],pool[205];
void count(int bg,int len,int abc[],char gorp[205]){
    for(int i=0;i<26;i++) abc[i]=0;
    for(int i=bg;i<bg+len;i++){
        abc[gorp[i]-'a']++;
    }
    return;
}
int compare(){
    for(int i=0;i<26;i++){
        if(abc1[i]!=abc2[i]){
            return 0;
        }
    }
    return 1;
}
void search(int bg){
    if(bg+n1>n2){
        no=1;
        return;
    }
    count(bg,n1,abc2,pool);
    if(compare()){
        for(int i=bg;i<bg+n1;i++){
            printf("%c",pool[i]);
        }
        return;
    }
    search(bg+1);
    return;
}
int main()
{
    scanf("%s%s",goal,pool);
    n1=strlen(goal),n2=strlen(pool);
    count(0,n1,abc1,goal);
    search(0);
    //count(0,n2,abc2,pool);
    if(no)printf("false");
    /*for(int i=0;i<26;i++){
        printf("%d ",abc1[i]);
        
    }
    printf("\n");
    for(int i=0;i<26;i++){
        printf("%d ",abc2[i]);
    }*/
    return 0;
}