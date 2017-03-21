#include<stdio.h>
#include<math.h>
#define sf scanf
#define pf printf
int main()
{
    int t,i;
    int a;
    scanf("%d",&t);
    while(t--)
    {
        sf("%d",&a);
        int sq=sqrt(a);
        pf("%s","YES\0NO\0"+((sq*sq==a)?0:4));
        puts("");
    }

    return 0;
}

