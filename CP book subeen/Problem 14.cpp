#include<stdio.h>
#define sf scanf
#define pf printf

int main()
{
    int t,n,i;
    sf("%d",&t);
    while(t--)
    {
        sf("%d",&n);
        pf("%s\n","odd\0even\0"+((n&1)?0:4));
    }
    return 0;
}

