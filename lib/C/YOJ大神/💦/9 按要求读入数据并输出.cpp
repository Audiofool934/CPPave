#include<stdio.h>
int main()
{
    int a, b;
    scanf("%d,%d", &a, &b);

    float x, y;
    scanf("%f %f", &x, &y);

    char c, d ,e;
    scanf(" %c, %c", &c, &d);

    printf("%d,%d\n", a, b);
    printf("%.1f %.1f\n", x, y);
    printf(" %c, %c\n", c, d);

    return 0;
}
//scanf("怎么写的怎么输入")