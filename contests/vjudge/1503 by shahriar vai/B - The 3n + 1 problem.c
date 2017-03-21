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
lint dp[10000005];
lint cycle(lint n)
{
    if(n==1)return 1;
    if(n<1000005){
        if(dp[n]!=0)return dp[n];
        if(n&1) {
            dp[n]= 2+cycle(n+n/2+1);
            return dp[n];
        }
        dp[n]= 1+cycle(n/2);
        return dp[n];
    }
    return ((n&1)? 2+cycle(n+n/2+1): 1+cycle(n/2));
}
int main()
{
    int l,m;
    while(scanf("%d %d",&l,&m)==2)
    {
        printf("%d %d ",l,m);
        if(l>m) {
            l=l^m;
            m=l^m;
            l=l^m;
        }
        lint i,maxi=0,cyc;
        for(i=l;i<=m;i++)
        {
            cyc=cycle(i);
            if(cyc>maxi)maxi=cyc;
        }
        printf("%d\n",maxi);
    }
    return 0;
}
