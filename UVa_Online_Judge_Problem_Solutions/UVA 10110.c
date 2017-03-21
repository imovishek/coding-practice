#include<stdio.h>
#include<math.h>
#include<inttypes.h>

int main()
{

    int64_t sq,is_on,n,i;
    while(scanf("%"PRId64"",&n))
    {

        if(n==0)break;

        sq=sqrt(n);
        if(sq*sq==n)is_on=0;
        else is_on=1;

        if(!is_on)printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
