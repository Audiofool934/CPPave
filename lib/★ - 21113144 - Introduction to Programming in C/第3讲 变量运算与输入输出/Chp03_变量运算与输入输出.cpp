#include<stdio.h>
int main()
{
    float a=75.4;
    printf("%10.2f\n",a);//10.2:占十个位置，保留两位小数
    float b=12.3;
    printf("%f\n",b);//单精度默认.6f，且第七位不能保证；而double能保证16位
    double c=123456.003;
    printf("%.12f\n",c);//.12强行输出到12位小数，但优先保证整数位，因此后面会错
    int d=12;
    //printf("%f",d);//不要跨类型输出——会错
    long e=12;
    //printf("%d",e);//长短影响不大，因为对计算机而言，整数和小数的储存方式有巨大区别
    char name[20];
    //scanf("Plz input your name: %s",name);//scanf里面是啥就输啥
    //printf("Hello, %s",name);

    //单个字符读取，用getchar()
    char ch1, ch2;//字符 字符串
    ch1=getchar();
    //getchar();//为了满足输入要求，“吞掉回车”
    ch2=getchar();
    printf("%c %c\n",ch1,ch2);//getchar从缓存中读取，输入一个就get一个，ab连着输入就是ch1，ch2

    //字符串读取，get()
    char str1[20],str2[20];
    scanf("%s",str1);//scanf读取字符串不好，不能读空格；
    gets(str2);
    printf("%s\n",str2);
}
/* 第二次课
#include<stdio.h>
#if 0
int main()
{
    int a = 015;
    printf("%3d\n",a);
    printf("%3o\n",a);
    printf("%3x\n",a);
    long int b = 0x8000l;
    printf("%8ld\n",b);
    printf("%8lo\n",b);
    printf("%8lx\n",b);
    return 0;
}
#endif
#define PRICE 30
#define c 1
int A()
{
    printf("%d\n", c);
    return 0;
}
int main()
{
    float a;
    a = 1.23456e5;
    int b;
    b = 123;
    //printf("%d\n%f\n", (int)a, (float)b);
    //printf("%d\n", PRICE);
    //printf("%d\n%c\n", b, b);
    //printf("Out of the %s\n", &d);
    float arr[3] = {1.2, 2.3, 3.4};
    for (int i=0; i<3; i++)
    {
        printf("%d\n", (int)(arr[i] + 0.5));
    }
    char ch1, ch2;
    ch1 = getchar();
    getchar();//“消化”回车
    ch2 = getchar();
    printf("%c, %c\n", ch1, ch2);
    char str[50];
    scanf("%s", str);
    printf("%s\n", str);
    gets(str);
    printf("%s\n", str);
}
*/