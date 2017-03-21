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
int main()
{
    lint n,k,ans;
    scanf("%lld %lld",&n,&k);
    ans=(n/k+1)*k;
    printf("%lld\n",ans);
    return 0;
}
