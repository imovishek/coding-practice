#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<inttypes.h>
#define pf printf
#define sf scanf
#define double dbl
typedef long long int lint;

int dp[1001][31];
int w[101],p[101],cap,n;
int maxi(int a, int b)
{
    if(a>b)return a;
    else return b;
}
int rec(int pos, int cp)
{
    if(pos==n+1)
        return 0;
    if(dp[pos][cp]!=-1)
    {

        return dp[pos][cp];
    }
    int *ret = &dp[pos][cp];

    *ret=rec(pos+1,cp);

    if(cp+w[pos]<=cap)
    {
        *ret=maxi(*ret,rec(pos+1,cp+w[pos])+p[pos]);
        //printf("%d ",*ret);
    }

    return *ret;
}

int main()
{
    int i,m;

    int t;
    scanf("%d",&t);
    while(t--)
    {
        int sum=0;
        scanf("%d",&n);
        for(i=1; i<=n; i++)
            scanf("%d %d",&p[i],&w[i]);
        scanf("%d",&m);
        while(m--){
            memset(dp,-1,sizeof(dp));
            scanf("%d",&cap);
            int sumi=sum;
            sum+=rec(1,0);
        //printf("\n%d %d**\n",cap,sum-sumi);
        }
        printf("%d\n",sum);
    }
    return 0;
}
