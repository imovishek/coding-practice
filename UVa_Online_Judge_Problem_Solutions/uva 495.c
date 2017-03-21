#include<stdio.h>
#include<inttypes.h>
int64_t fib(int64_t ara[],int64_t n)
{
    if(n==0)return 0;
    if(n==1)return 1;
    if(ara[n]!=-1)return ara[n];
    ara[n]= fib(ara,n-1)+fib(ara,n-2);
    return ara[n];
}
int main()
{
    int64_t n, ara[100];
    for(n=99;n>=0;n--)ara[n]=-1;
    while(scanf("%"PRId64"",&n)!=EOF)
    {

        printf("The Fibonacci number for %"PRId64" is %"PRId64"\n",n,fib(ara,n));
    }
    return 0;
}
