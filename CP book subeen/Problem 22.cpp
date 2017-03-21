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
    int t,n;
    sf("%d",&t);
    while(t--)
    {
        sf1(n);
        int sp=n-1, star=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<sp;j++) pf(" ");
            for(int j=0;j<star;j++)pf("*");
            pf("\n");
            sp--;
            star+=2;
        }
        pf("\n");
    }
    return 0;
}

