#include<stdio.h>
int main()
{
    long long int a,b,c;

    while(scanf("%lld %lld %lld",&a,&b,&c)){

        if(a==0 && b==0 && c==0)
            break;
        if((a*a)+(b*b)==(c*c))
            printf("right\n");
        else if((a*a)+(b*b)!=(c*c))
            printf("wrong\n");

    }

    return 0;
}
