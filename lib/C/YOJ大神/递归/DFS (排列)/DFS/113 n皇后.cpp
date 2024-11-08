/*//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////*/
#include<stdio.h>
int n,fp[15][15]={0},mtd=0;
int check(int hang,int lie){
    for(int i=1;i<=lie;i++){
        if(fp[hang][i]||(hang-lie+i>=1&&fp[hang-lie+i][i])||(hang+lie-i>=1&&fp[hang+lie-i][i]))
            return 0;//注意数组越界。。。，vscode可以，yoj不行！
    }
    return 1;
}
void pos(int lie){
    if(lie==n+1){
        mtd++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(check(i,lie)){
            fp[i][lie]=1;
            pos(lie+1);
            fp[i][lie]=0;
        }
    }
    return;
}
int main()
{
    scanf("%d",&n);
    pos(1);
    printf("%d",mtd);
    return 0;
}
/*/////////////////////////////////////////////////////////
Bing
/////////////////////////////////////////////////////////*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 定义一个全局变量，用来存储解的个数
int count = 0;

// 定义一个函数，用来检查当前行的皇后是否和之前的皇后有冲突
int check(int row, int *queen)
{
    for (int i = 0; i < row; i++)
    {
        // 如果两个皇后在同一列或者同一斜线上，就返回0，表示有冲突
        if (queen[i] == queen[row] || abs(queen[i] - queen[row]) == row - i)
        {
            return 0;
        }
    }
    // 如果没有冲突，就返回1
    return 1;
}

// 定义一个函数，用来递归地尝试所有可能的摆法
void solve(int n, int row, int *queen)
{
    // 如果当前行等于n，说明已经找到了一个解，就把解的个数加一
    if (row == n)
    {
        count++;
    }
    else
    {
        // 否则，就遍历当前行的每一列，尝试把皇后放在这一列上
        for (int col = 0; col < n; col++)
        {
            // 把皇后放在当前列上
            queen[row] = col;
            // 检查是否有冲突
            if (check(row, queen))
            {
                // 如果没有冲突，就递归地尝试下一行
                solve(n, row + 1, queen);
            }
        }
    }
}

int main()
{
    // 从标准输入读取一个正整数n
    int n;
    scanf("%d", &n);
    // 分配一个大小为n的一维数组，用来存储每一行皇后的位置
    int *queen = (int *)malloc(sizeof(int) * n);
    // 调用solve函数，从第0行开始尝试
    solve(n, 0, queen);
    // 释放数组的内存空间
    free(queen);
    // 把解的个数输出到标准输出
    printf("%d\n", count);
    // 返回0，表示程序正常结束
    return 0;
}