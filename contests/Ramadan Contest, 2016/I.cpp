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
#define pii pair<int,int>
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
using namespace std;
typedef long long int lint;
typedef double dbl;
int n;
int dp[100007];
int ara[100007];
int rec(int pos)
{
    if(pos>=n)return 0;
    if(dp[pos]!=-1)
        return dp[pos];
    int &ret=dp[pos];
    ret=rec(pos+2);
    if(pos+3<n)
        ret=max(ret,rec(pos+3));
    ret+=ara[pos];
    return ret;
}

int main()
{
    int t;
    sf("%d",&t);
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        sf("%d",&n);
        for(int i=0;i<n;i++)
        {
            sf("%d",&ara[i]);
        }
        pf("%d\n",max(rec(0),rec(1)));
    }
    return 0;
}
