#include<stdio.h>
#include<math.h>
#include<inttypes.h>
int is_prime(int n)
{
    int i,j;
    for(i=3;i<=sqrt(n);i+=2)
    {
        if(n%i==0) return 0;

    }

    return 1;
}


void main()
{
    int64_t i,j,n=600851475143;//600851475143
    for(i=3;i<=sqrt(n);i+=2)
    {
        if(n%i==0 && is_prime(i)==1) printf("%" PRId64 " ",i);
    }

printf("\n%" PRId64 " ",n);
}
