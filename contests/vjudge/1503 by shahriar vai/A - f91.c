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
lint dp[1000005];
lint cycle(lint n)
{
    if(n==1)return 0;
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
    lint l,m;
    while(scanf("%lld %lld",&l,&m)==2)
    {
        if(l==0 && m==0)break;
        if(l>m) {
            l=l^m;
            m=l^m;
            l=l^m;
        }
        lint i,maxi=0,cyc;
        lint num;
        for(i=l;i<=m;i++)
        {
            if(i==1)cyc=3;
            else cyc=cycle(i);
            if(cyc>maxi){maxi=cyc;num=i;}
        }
        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",l,m,num,maxi);
    }
    return 0;
}
