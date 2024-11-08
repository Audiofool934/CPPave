#include <stdio.h>

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    int children[N];
    for (int i = 1; i <= N; ++i) {
        children[i] = i;
    }
    int idx=0;
    while(N>=1){
        idx=(idx-1+M)%N;
        /*printf("N=%d,idx=%d\n",N,idx);
        for(int i=1;i<=N;i++){
            printf("%d ",children[i]);
        }
        printf("\n");*/
        for(int i=idx+1;i<=N-1;i++){
            children[i]=children[i+1];
        }
        N--;
    }
    printf("%d\n", children[1]);
}