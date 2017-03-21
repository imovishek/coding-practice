#include<stdio.h>
int main()
{
    int n,reslt;
    while(scanf("%d",&n)==1)
    {

        reslt=n;
        while(n>2)
        {
            reslt+=n/3;
            n=n/3+n%3;

        }
        if(n==2)reslt++;
    printf("%d\n",reslt);


    }

    return 0;
}

