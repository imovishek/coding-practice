#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<inttypes.h>
#define pf printf
#define sf scanf
#define mx 1000000007
#define pcase(x) printf("Case %d: ",x)
typedef long long int lint;
typedef double dbl;

lint bigmod(lint b, lint p, lint m)
{
    lint mo;
    if(p==0)return 1;
    if(p&1)
    {
        mo=bigmod(b,p-1,m);
        printf("%d*\n",mo);
        return (b*mo)%m;
    }
    mo=bigmod(b,p/2,m);
    printf("%d*\n",mo);
    return (mo*mo)%m;

}
int main()
{
    lint first,last,ans,a,b,n,x,modin,anmod;
    scanf("%I64d %I64d %I64d %I64d",&a,&b,&n,&x);
    anmod=bigmod(a,n,mx);
    first=(x*anmod)%mx;
    modin=bigmod(a-1,mx-2,mx);
    last=(((b*anmod)%mx-1+mx)*modin)%mx;
    ans=(first+last)%mx;
    printf("%I64d\n",ans);
    return 0;
}
