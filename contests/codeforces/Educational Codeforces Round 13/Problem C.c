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
lint maxi(lint a, lint b)
{
    if(a>b)
        return a;
    else return b;
}
int main()
{
    lint n,a,b,p,q,ans;
    sf("%I64d %I64d %I64d %I64d %I64d",&n,&a,&b,&p,&q);
    lint mult=a*b,ans2,ans1;
        ans1=((n/a)*p+(n/b-n/(mult))*q);
        ans2=((n/b)*q+(n/a-n/(mult))*p);
        ans1=maxi(ans1,ans2);

    printf("%I64d\n",ans1);
    return 0;
}
