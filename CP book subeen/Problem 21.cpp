#include<stdio.h>
#include<string.h>
#define sf scanf
#define pf printf

int main()
{
    int t,n;
    sf("%d",&t);
    while(t--)
    {
        sf("%d",&n);
        pf("%s\n","red\0blue"+((n&1)?4:0));
    }
    return 0;
}



