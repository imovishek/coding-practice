#include<stdio.h>
#define sf scanf
#define pf printf

int main()
{
    int t,n;
    sf("%d",&t);
    while(t--)
    {
        int counti=0;
        sf("%d",&n);
        if(n==0)counti=1;
        while(n){
            n/=10;
            counti++;
        }
        pf("%d\n",counti);
    }
    return 0;
}
