#include<stdio.h>
int main()
{
    int n,tt;
    char b,e;
    scanf("%d",&n);
    int ab=0,ac=0,ad=0,bc=0,bd=0,cd=0;
    while(1){
        scanf("%d",&tt);
        if(tt==0) break;
        scanf("%c%c",&b,&e);
        if(b=='A'){
            if(e=='B'){
                if(tt==1) ab+=1;
                if(tt==2) ab-=1;
            }
            if(e=='C'){
                if(tt==1) ac+=1;
                if(tt==2) ac-=1;
            }
            if(e=='D'){
                if(tt==1) ad+=1;
                if(tt==2) ad-=1;
            }
        }
        if(b=='B'){
            if(e=='C'){
                if(tt==1) bc+=1;
                if(tt==2) bc-=1;
            }
            if(e=='D'){
                if(tt==1) bc+=1;
                if(tt==2) bc-=1;
            }
        }
        if(b=='C'){
            if(e=='D'){
                if(tt==1) cd+=1;
                if(tt==2) cd-=1;
            }
        }
    }
    ad=ad+ac+ab+bc+bd+cd;
    while(ab>0&&bc>0&&cd>0){
        ab-=1;bc-=1;cd-=1;
        ad-=2;
    }
    while(ab>0&&bc>0){
        ab-=1;bc-=1;
        ac-=1;
    }
    while(bc>0&&cd>0){
        bc-=1;cd-=1;
        bd-=2;
    }
    while(ab>0&&bd>0){
        ab-=1;bd-=1;
        ad-=1;
    }
    while(ac>0&&cd>0){
        ac-=1;cd-=1;
        ad-=1;
    }
    printf("%d",n-ad);
    return 0;
}

/* tyf 另解
#include <stdio.h>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	int l, a = 0, b = 0, c = 0;
	char z1, z2;
	do {
		scanf("%d", &l);
		if (l == 0) {
			breai;
		}
		scanf("%c%c",  &z1, &z2);
		if (l == 1) {
			for (int i = z1; i <= z2 - 1 ; i++) {
				if (i == 65) {
					a++;
				}
				if (i == 66) {
					b++;
				}
				if (i == 67) {
					c++;
				}
			}
		}
		if (l == 2) {
			for (int i = z1; i <= z2 - 1 ; i++) {
				if (i == 65) {
					a--;
				}
				if (i == 66) {
					b--;
				}
				if (i == 67) {
					c--;
				}
			}
		}
	} while (true);
	int piao;
	if (a > b)
		b = a;
	if (b > c)
		c = b;
	int sheng;
	sheng = n - c;
	printf("%d", sheng);
	return 0;
}*/
//先做好数学工作再写程序！简单方法？