#include<stdio.h>
#include<inttypes.h>
int is_prime(int n)
{
    int i;
    for(i=3;i*i<=n;i+=2)
    {
        if(n%i==0) return 0;
    }
    return 1;
}

int main()
{
    int64_t i,sum=2,n=2000000;

    for(i=3;i<=n;i+=2)
    {
        if(is_prime(i)) sum=sum+i;
    }
    printf("%"PRId64" ",sum);
    return 0;
}
