#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<inttypes.h>
int is_prime(int n)
{
    int i;
    for( i=3;i<=sqrt(n);i+=2)
    {
        if(n%i==0)return 0;
    }
    return 1;
}
int main()
{
    int i,counti=0;
    for( i=3;i<100;i+=2)
    {
        if(is_prime(i)){
            printf("%d, ",i);
            counti++;
        }
    }
    printf("\n%d\n",counti);
    return 0;
}
