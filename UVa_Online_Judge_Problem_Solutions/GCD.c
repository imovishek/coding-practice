#include<stdio.h>
long long GCD(long long a, long long b)
{
    long long x;
    if(a<b){x=a;a=b;b=x;}
    while(b>0)
    {
        x=a%b;
        a=b;
        b=x;
    }
    return a;
}
int main()
{
    printf("%ld\n",GCD(81,75));
    return 0;
}
