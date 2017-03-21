#include<stdio.h>
#include<string.h>
#define sf scanf
#define pf printf

int main()
{
    int t,n,i,j;
    sf("%d",&t);
    while(t--)
    {
        sf("%d",&n);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)
                pf("*");
            pf("\n");
        }
        if(t)pf("\n");
    }
    return 0;
}



