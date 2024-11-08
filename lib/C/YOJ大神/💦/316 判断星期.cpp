#include<stdio.h>
int main()
{
    int d;
    scanf("%d",&d);
    switch((d-1)%7){
        case(0):{printf("SUN");break;}
        case(1):{printf("MON");break;}
        case(2):{printf("TUE");break;}
        case(3):{printf("WED");break;}
        case(4):{printf("THU");break;}
        case(5):{printf("FRI");break;}
        case(6):{printf("SAT");break;}
    }
    return 0;
}