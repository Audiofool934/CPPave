#include<stdio.h>
#include<string.h>
#include<iostream>

int ceiling(int a,int b){
	if(a%b==0){
		return a/b;
	}else{
		return a/b+1;
	}
}

struct photo {
		int r;
		int g;
		int b;
		photo():r(0),g(0),b(0){}
	};

int sum(struct photo a[][102],int i,int j){
	int t=a[i][j].r+a[i][j].g+a[i][j].b;
	return t;
}

int bad(struct photo a[][102],int i,int j,int n,int m){
	if (i < 1 || i > n || j < 1 || j > m) {
        return 0;
    }
	if (sum(a, i, j) == 0) {
        return 1;
    }
    return 0;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	struct photo a[n+2][102], temp[n + 2][102];;
	int i,j;
	char color;
	for(i=1;i<n+1;i++){
		for(j=1;j<m+1;j++){
			scanf(" %c %d %c %d %c %d",&color,&a[i][j].r,&color,&a[i][j].g,&color,&a[i][j].b);
            temp[i][j] = a[i][j];
		}
	}

	while(1){
        int zero = 0;
		for(i=1;i<n+1;i++){
			for(j=1;j<m+1;j++){
				if(bad(a,i,j,n,m)){
                    zero++;

					int sumr = 0, sumg = 0, sumb = 0;
                    int neighborCount = 0;

                    if (i > 1 &&!bad(a, i - 1, j, n, m)) {
                        sumr += a[i - 1][j].r;
                        sumg += a[i - 1][j].g;
                        sumb += a[i - 1][j].b;
                        neighborCount++;
                    }
                    if (i < n &&!bad(a, i + 1, j, n, m)) {
                        sumr += a[i + 1][j].r;
                        sumg += a[i + 1][j].g;
                        sumb += a[i + 1][j].b;
                        neighborCount++;
                    }
                    if (j > 1 &&!bad(a, i, j - 1, n, m)) {
                        sumr += a[i][j - 1].r;
                        sumg += a[i][j - 1].g;
                        sumb += a[i][j - 1].b;
                        neighborCount++;
                    }
                    if (j < m &&!bad(a, i, j + 1, n, m)) {
                        sumr += a[i][j + 1].r;
                        sumg += a[i][j + 1].g;
                        sumb += a[i][j + 1].b;
                        neighborCount++;
                    }

                    if (neighborCount > 0) {
                        temp[i][j].r = ceiling(sumr, neighborCount);
                        temp[i][j].g = ceiling(sumg, neighborCount);
                        temp[i][j].b = ceiling(sumb, neighborCount);
                    }
				}
			}
		}

        for (i = 1; i < n + 1; i++) {
            for (j = 1; j < m + 1; j++) {
                a[i][j] = temp[i][j];
            }
        }
        
        if (zero == m * n || zero == 0) break;
	}
	for(i=1;i<n+1;i++){
		for(j=1;j<m+1;j++){
			printf("R %d ",a[i][j].r);
			printf("G %d ",a[i][j].g);
			printf("B %d ",a[i][j].b);
		}
		printf("\n");
	}
	return 0;
}
