#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
struct num
{
	long long int a;
	long long int ci;
	long long int last;
	long long int cun;
};
int cmp(const void*c,const void*b)
{   
	num *num1=(num*)c;
    // struct num *num1=(struct num*)c;
    struct num *num2=(struct num*)b;
    if(num1->ci!=num2->ci)
	    return num2->ci-num1->ci;
	else if (num1->last!=num2->last)
	    return num1->last-num2->last;
	    else return num1->a-num2->a;
}   

int main()
{
	struct num shu[10];
	long long int i,j;
	long long int sum=0,tmp;
	for(i=0;i<10;i++)
	{scanf("%lld",&shu[i].a);
	}

    for(i=0;i<10;i++)
    {    shu[i].cun=shu[i].a;
    	   for(;;)
		   {   
		   tmp=shu[i].cun;
		   sum=0;
		   while(tmp!=0)
		   {sum=sum*10+tmp%10;
		   tmp=tmp/10;
		   }
    		if(sum!=shu[i].cun) {
			shu[i].cun+=sum;shu[i].ci++;}
    		else {
			shu[i].last=sum;break;}
		    }
    } 

qsort(shu,10,sizeof(struct num),cmp);
    for(i=0;i<10;i++)
     printf("%lld %lld %lld\n",shu[i].a,shu[i].ci,shu[i].last);
	return 0;
}