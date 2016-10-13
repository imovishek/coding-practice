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
#define pcase(x) printf("Test #%d:\n",x)
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
using namespace std;
typedef long long int lint;
typedef double dbl;
int seq[25],ara[10007],dp[10007];
int n;
bool compare(int u, int v)
{
    if(ara[u]>= ara[v]) return true;
    return false;
}
int LIS(int u)
{
    if(dp[u]!=-1)return dp[u];
    int maxi=0, v;
    for(int v=u+1; v<n; v++)
    {
        if(compare(u, v))
        {
            if(LIS(v)> maxi)
            {
                maxi=LIS(v);
            }
        }
    }
    dp[u]=maxi+1;
    return dp[u];
}
void printpath(int u)
{
    int flag=0;
    while(u!=-1)
    {
        if(flag) pf(" ");
        flag=1;
        pf("%d",ara[u]);

    }
    pf("*\n");
}
int main()
{
    int tst=1;
    int flag=0;
    while(sf1(ara[0]) && ara[0]!=-1)
    {

        if(flag)pf("\n");
        flag=1;
        n=1;
        while(sf1(ara[n]) && ara[n++]!=-1);
            n--;
            mem(dp, -1);
            int maxi=0;
            FOR(i, n)
            if(LIS(i) > maxi)
            {
                maxi=LIS(i);
            }
            pcase(tst++);
            pf("  maximum possible interceptions: %d\n", maxi);
    }
        return 0;
    }
    /*
    4
    4 2 3 1
    1 3 2 4
    3 2 1 4
    3 2 4 1
    4 3 2 1
    */
