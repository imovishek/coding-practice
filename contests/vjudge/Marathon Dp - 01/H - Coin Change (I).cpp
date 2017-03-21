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
using namespace std;
typedef long long int lint;
typedef double dbl;
int dp[51][1001];
int n,cap;
int coin[51],limit[51];
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
    if(dp[pos][cp]!=-1)
    {
        return dp[pos][cp];
    }
    int &ret=dp[pos][cp];
    ret=0;
    int val=0;
    for(int i=0;i<=limit[pos];i++)
    {
        if(cp-val>=0){
            ret+=rec(pos+1,cp-val);
            ret%=100000007;
        }
        else break;
        val+=coin[pos];
    }
    return ret;
}
int main()
{
    int t,tst=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&cap);
        for(int i=0;i<n;i++)
            for(int j=0;j<=cap;j++)
                dp[i][j]=-1;
        for(int i=0;i<n;i++)
            scanf("%d",&coin[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&limit[i]);
        pcase(tst++);
        printf("%d\n",rec(0,cap));
    }
    return 0;
}
