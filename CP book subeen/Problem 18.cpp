#include<stdio.h>
#include<string.h>
#define pf printf
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
int main()
{
    int t,r,w,l;
    sf("%d",&t);
    while(t--)
    {
        sf3(r,w,l);
        pf("%s\n","YES\0NO"+((r<=l/2 && r<=w/2 ) ? 0 : 4));
    }
    return 0;
}
