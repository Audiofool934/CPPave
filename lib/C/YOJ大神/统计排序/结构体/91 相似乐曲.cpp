#include<stdio.h>
#include<stdlib.h>
int glen,gsong[16]={0};//目标歌曲长度 直方图信息
typedef struct{
    int tag;//歌曲编号
    int len;//歌曲长度
    int a[16];//直方图信息
    int d;
}song;

song songs[105];
void vec(int n,int *a){
    for(int i=1;i<=16;i++){
        if((i-1)*15+i-1<=n&&n<=i*15+i-1){
            a[i-1]++;
        }
    }
}//扫描

void dist(int i){
    songs[i].d=0;
    for(int j=0;j<16;j++){
        songs[i].d+=(songs[i].a[j]-gsong[j])*(songs[i].a[j]-gsong[j]);
    }
}

int cmp(const void* songa,const void* songb){
    song *a=(song*)songa;
    song *b=(song*)songb;
    if(a->d==b->d) return a->tag-b->tag;
    return a->d-b->d;
}

int main()
{
    scanf("%d",&glen);
    for(int i=0;i<glen;i++){
        int x;
        scanf("%d",&x);
        vec(x,gsong);
    }
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        songs[i].tag=i;
        for(int j=0;j<16;j++){
            songs[i].a[j]=0;
        }
        scanf("%d",&songs[i].len);
        for(int j=0;j<songs[i].len;j++){
            int m;
            scanf("%d",&m);
            vec(m,songs[i].a);
        }
    }
    
    for(int i=0;i<n;i++){
        dist(i);
    }
    
    qsort(songs,n,sizeof(song),cmp);

    for(int i=0;i<k;i++){
        printf("%d ",songs[i].tag);
    }
    return 0;
}

/////////////////////////////////////////
/*
#include<stdio.h>
#include<math.h>
struct song{
        int n;
        int freq[101];
        int ff[17];
};

int main(void)
{
    //输入
    int n_0,n,i;
    scanf("%d",&n_0);
    int song_0[n_0+1];
    for(int i=1;i<=n_0;i++)
        scanf("%d",&song_0[i]);
    
    //song_0初始化
    int zz=1,song_0_ff[17];
    for(int l=1;l<=16;l++)
            song_0_ff[l]=0;
    for(int i=0;i<=240;i+=16){
        for(int l=1;l<=n_0;l++){
            if(i<=song_0[l]&&song_0[l]<=i+15){
                song_0_ff[zz]++;
            }
        }
        zz++;
    }
    //for(int i=1;i<=16;i++)
        //printf("%d ",song_0_ff[i]);
    //printf("\n");
    
    //输入
    scanf("%d%d",&n,&i);
    int freq[n+1][101],lenth[n];
    for(int i=1;i<=n;i++){
        scanf("%d",&lenth[i]);
        for(int l=1;l<=lenth[i];l++)
            scanf("%d",&freq[i][l]);
    }
    
    //歌曲信息录入结构体
    struct song songs[n+1];
    //初始化
    for(int i=1;i<=n;i++)
        for(int l=1;l<=16;l++)
            songs[i].ff[l]=0;
    for(int i=1;i<=n;i++){
        songs[i].n=i;
        //printf("i=%d\nsongs[i].n=%d\n",i,songs[i].n);//调试
        for(int l=1;l<=lenth[i];l++){
            songs[i].freq[l]=freq[i][l];
            //printf("songs[i].freq[l]=%d\n",songs[i].freq[l]);//调试
        }
        int tt=1;
        for(int i=0;i<=240;i+=16){
            for(int l=1;l<=lenth[i];l++){
                if(i<=songs[i].freq[l]&&songs[i].freq[l]<=i+15){
                    songs[i].ff[tt]++;
                    //printf("songs[i].freq[l]=%d \n",songs[i].freq[l]);
                    //printf("songs[i].ff[tt]=%d \n",songs[i].ff[tt]);
                }
            }
            tt++;
        }
        //for(int l=1;l<=16;l++)
            //printf("songs[i].ff[%d]=%d\n",l,songs[i].ff[l]);//调试
    }
    //for(int i=1;i<=n;i++)
        //printf("i=%d\nsongs[i].n=%d\n",i,songs[i].n);//调试
    //排序
    struct song tmp;//结构体数组交换
    for(int i=1;i<=n-1;i++){
        for(int l=1;l<=n-i;l++){//带等号的冒排书写细节
            double suml=0,sumla1=0;
            for(int i=1;i<=16;i++){
                suml+=(song_0_ff[i]-songs[l].ff[i])*(song_0_ff[i]-songs[l].ff[i]);//sum1(l)
                sumla1+=(song_0_ff[i]-songs[l+1].ff[i])*(song_0_ff[i]-songs[l+1].ff[i]);//sum2(l+1)
            }
            //printf("i:%d l:%d\n",i,l);
            //printf("suml=%lf, sumla1=%lf\n",suml,sumla1);
            //printf("songs[%d].n=%d\n",l,songs[l].n);
            if(sqrt(suml)>sqrt(sumla1)){
                tmp=songs[l];
                songs[l]=songs[l+1];
                songs[l+1]=tmp;
            }
            //for(int m=1;m<=n;m++)
                //printf("songs[%d].n=%d\n",m,songs[m].n);
        }
    }
    //输出
    for(int i=1;i<=i;i++)
        printf("%d ",songs[i].n-1);
    
    return 0;
}*/