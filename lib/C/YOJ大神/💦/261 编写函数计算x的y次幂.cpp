#include <stdio.h>
#include <stdlib.h>

int power( int x, int y)
{
int xx=1;
    for(int i=1;i<=y;i++){
        xx*=x;
    }
    return xx;
}
int main()
{
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d", power(x, y));
    return 0;

}