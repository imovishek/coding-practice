#include<stdio.h>
int main()
{
    long long int a,b;
    int i=0;
    while (i<10 && 2==scanf("%lld %lld",&a,&b))
    {

    printf("%lld\n",b-a);
    i++;
    }

    return 0;
}
