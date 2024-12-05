#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int n;
int a[N];
int cnt;

void selection_sort(int l, int r)
{
    if (l >= r) return;

    int k = l;
    for (int i = l + 1; i <= r; i ++ )
        if (a[i] < a[k])
            k = i;

    if (k != l)
    {
        swap(a[k], a[l]);
        printf("%d<->%d:", k, l);
        for (int i = 1; i <= n; i ++ )
            printf("%d ", a[i]);
        printf("\n");
        cnt ++ ;
    }

    selection_sort(l + 1, r);
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i ++ )
        cin >> a[i];

    selection_sort(1, n);

    printf("Total steps:%d\n", cnt);
    printf("Right order:");
    for (int i = 1; i <= n; i ++ )
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
//by tyf
#include <iostream>
#include <stdio.h>
using namespace std;

void paixu(int a[102][102],  int i, int j, int &step, int &min, int &xu,
           int n) {
	if (i == n) {
		return;
	}
	if (a[i][j] < min) {
		min = a[i][j];
		xu = j;
	}
    int num=xu;
	if (j == n) {
		if (a[i][i] > min && i < xu) {
			swap(a[i][i], a[i][xu]);
			min = a[i][xu];
			step++;
			for (int h = 1; h <= n; h++) {
				a[i + 1][h] = a[i][h];
			}
            min=n;
			paixu(a, i + 1, i + 2, step, min, xu, n);
			printf("%d<->%d:", i, num);
			for (int h = 1; h <= n; h++) {
				printf("%d ", a[i][h]);
			}
			printf("\n");
		} else {
			for (int h = 1; h <= n; h++) {
				a[i + 1][h] = a[i][h];
			}
            min=n;
			paixu(a, i + 1, i + 2, step, min, xu, n);
		}
	} else {
		paixu(a, i, j + 1, step, min, xu, n);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int a[102][102];
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[1][i]);
	}
	int step = 0, i = 1, j = 2, min = a[1][1], xu = 1;
	paixu(a,  i, j, step, min, xu, n);
	printf("Total steps:%d\n", step);
	printf("Right order:");
	for (int l = 1; l <= n; l++) {
		printf("%d ", a[n][l]);
	}
	return 0;
}
/*
#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
int minm(int a, int b){
    if(a<=b) return a;
    else return b;
}
int main()
{
    int n,min=100,tmp;
    scanf("%d",&n);
    int a[n+1];
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int j=1;j<=n-1;j++){
        for(int i=1;i<=n;i++){
            min=minm(min,a[i]);
        }
        tmp=a[j];
        a[j]=min;
        min=tmp;
    }
    for(int i=1;i<=n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}*/
/*
#include<stdio.h>
#include<iostream>
using namespace std;
int n,TS,minm,i=1;
int a[101];
int min(int a, int b){
    if(a<=b) return a;
    else return b;
}
int swap(int a, int b){
    int tmp;
    a=tmp;
    a=b;
    b=tmp;
}
void sort()
{
    i++;
    minm=min(minm,a[i]);
    if(i==n) return;
    sort();
}
int main()
{
    memset(a,0,sizeof a);
    scanf("%d",&n);
    for(int j=1;j<=n;j++)
        scanf("%d",&a[i]);
    for(int j=1;j<=n;j++){
        minm=a[i];
        sort();
        swap(a[i],minm);
    }
    for(int j=1;j<=n;j++)
        printf("%d ",a[i]);
    return 0;
}
*/