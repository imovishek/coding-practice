#include<stdio.h>
#include<inttypes.h>
int main()
{

     unsigned long long  i,x,j,n,r,mult,min,max;
    while(scanf("%"PRIu64" %"PRIu64"",&n,&r)==2)
    {

        mult=1;
        if(n==0 && r==0)break;
        min=n-r;max=r;

        if(min>max){x=min;min=max;max=x;}

        x=max+1;
        j=n-max;
        for(i=1;i<=j;i++,x++)
        {
            mult*=x;
            mult/=i;

        }

        printf("%"PRIu64" things taken %"PRIu64" at a time is %"PRIu64" exactly.\n",n,r,mult);
    }
    return 0;
}
