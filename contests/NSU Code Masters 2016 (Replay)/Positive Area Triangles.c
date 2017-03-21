#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<inttypes.h>
#define pf printf
#define sf scanf
#define pcase(x) printf("Case %d: ",x)
typedef long long int lint;
typedef double dbl;
lint nC(int n)
{
    return n*(n-1)(n-2)/6;
}
int main()
{
    int n,m,mult;
    lint ans;
    while(scanf("%d %d",&n,&m)==2)
    {
        ans=0;
        n++,m++;
        mult=n*m;
        ans+=nC(mult)%1000000007;
        if(n==m)
        {

        }
    }
    return 0;
}
