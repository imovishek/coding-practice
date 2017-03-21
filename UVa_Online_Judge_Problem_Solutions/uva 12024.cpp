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
#define pcase(x) printf("Case %d: ",x)
#define pi acos(-1.0)
using namespace std;
typedef long long int lint;
typedef double dbl;
int dp[20];
int D(int n)
{
    if(n==1)return 0;
    if(n==2)return 1;
    if(dp[n]!=-1)
        return dp[n];
    dp[n]=(n-1)*(D(n-1)+D(n-2));
    return dp[n];
}
int fac[15];
int fact(int n)
{
    if(n==1)return 1;
    if(fac[n]!=-1)
        return fac[n];
    fac[n]=n*fact(n-1);
    return fac[n];
}
int main()
{
    int t,n;
    sf1(t);
    while(t--)
    {
        memset(fac,-1,sizeof(fac));
        memset(dp,-1,sizeof(dp));
        sf1(n);
        pf("%d/%d\n",D(n),fact(n));
    }
    return 0;
}
