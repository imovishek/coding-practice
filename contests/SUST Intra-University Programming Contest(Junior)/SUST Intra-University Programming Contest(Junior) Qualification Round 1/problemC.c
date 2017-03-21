#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<inttypes.h>
#define pf printf
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
typedef long long int lint;
typedef double dbl;
int main()
{
    char ara[150];
    int t,tst=1,i,j;
    sf("%d",&t);
    while(t--)
    {

        sf("%s",ara);
        pcase(tst++);pf(" ");
        for(i=0;ara[i];i++)
        {
            int flag=0;
            if(i!=0)pf(" ");
            int n=ara[i]-'a'+1;
            if(n>10){flag=1;n--;if(n==10)n=3;}
            int f,e;
            f=ceil((double)n/5.0);
            e=n%5;
            if(e==0)e=5;
            for( j=0;j<f;j++)
                printf(".");
            pf(",");
            for( j=0;j<e;j++)
                printf(".");

        }
        pf("\n");
    }
    return 0;
}
