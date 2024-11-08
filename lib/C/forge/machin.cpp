#include<stdio.h>
#include<iostream>
using namespace std;
int main(void)
{   //本程序每四位数输出，如果请求计算的位数不是4的整数倍，最后输出可能会少1~3位数
	long a[2]={956,80},b[2]={57121,25},i=0,j,k,p,q,r,s=2,t,u,v,N,M=10000;
	printf("%9cMachin%6cpi=16arctan(1/5)-4arctan(1/239)\nPlease input a number.\n",32,32);
	cin>>N,N=N/4+3;

	long *pi=new long[N],*e=new long[N];//储存pi
	
    while(i<N)pi[i++]=0;//初始化

	while(--s+1)//循环两次
	{
		for(*e=a[k=s],i=N;--i;)
            e[i]=0;
        //初始化数组e的第二个到最后一个元素为0（因为循环是从i=N开始，且因为--i的使用，实际上是跳过了为第一个元素赋非零值的步骤），同时根据s的值来初始化数组e的第一个元素。这是在准备数组e用于之后的计算过程中的一个步骤。
		for(q=1; j=i-1,i<N; e[i]?0:++i,q+=2,k=!k)//遍历arctan(1/5)和arctan(1/239)的每一位
        //q为除数的增量
			for(r=v=0; ++j<N; pi[j]+=k?u:-u)
            u=(t=v*M+(e[j]=(p=r*M+e[j])/b[s]))/q,r=p%b[s],v=t%q;
	}
	while(--i)(pi[i]=(t=pi[i]+s)%M)<0?pi[i]+=M,s=t/M-1:s=t/M;
	
    for(cout<<"3.";++i<N-2;)printf("%04ld",pi[i]);
	delete []pi,delete []e,cin.ignore(),cin.ignore();
	return 0;
}