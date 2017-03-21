#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#define pf printf
#define sf scanf
#define pcase(x) printf("Case %d: ",x)
#define check(x,y) (flag[313*x+(y>>5)]&(1<<(y&31)))
#define seti(x,y) flag[313*x+(y>>5)]|=(1<<(y&31))
using namespace std;
typedef long long int lint;
typedef double dbl;
int dp[100][10001],flag[31400];
int n,cap;
int coin[100];
int maxi(int a, int b)
{
    if(a>b)
        return a;
    return b;
}
int rec(int pos,int cp)
{
    if(cp==0)return 1;
    if(pos==n)
        return 0;
    if(check(pos,cp))
    {
        return dp[pos][cp];
    }
    int &ret=dp[pos][cp];
    ret=0;
    int val=0;
    for(int i=0;i<=cap;i++)
    {
        if(cp-val>=0){
            ret+=rec(pos+1,cp-val);
        }
        else break;
        val+=coin[pos];
        if(ret>100000007)
            ret%=100000007;
    }
    seti(pos,cp);
    return ret;
}
int main()
{
    int t,tst=1;
    scanf("%d",&t);
    while(t--)
    {
        memset(flag,0,sizeof(flag));
        scanf("%d %d",&n,&cap);
        for(int i=0;i<n;i++)
            scanf("%d",&coin[i]);
        pcase(tst++);
        printf("%d\n",rec(0,cap));
    }
    return 0;
}

