#include<stdio.h>
int main()
{
    int n,k,reslt;
    while(scanf("%d %d",&n,&k)==2)
    {
        reslt=n;
        while(n>=k)
        {
            reslt+=n/k;
            n=n/k+n%k;

        }
    printf("%d\n",reslt);


    }

    return 0;
}

