#include<stdio.h>
#include<inttypes.h>
int main()
{
    int64_t i,n,sum;
    while(scanf("%"PRId64"",&n))
    {
        if(n<0)break;
        sum=n*(n+1)/2+1;
        printf("%"PRId64"\n",sum);
    }
    return 0;
}
