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
using namespace std;
typedef long long int lint;
typedef double dbl;
int dp[1000];
int fibo(int n)
{
    if(n==1 || n==2)return 1;
    if(dp[n]!=-1)
        return dp[n];
    dp[n]=fibo(n-1)+fibo(n-2);
    dp[n]%=1007;
    return dp[n];
}
int G(int n)
{
    if(n==0)return 0;
    return (G(n-1)+fibo(4*n-1))%1007;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int t;
    sf1(t);
    lint n;
    int ara[28];
    for(int i=0;i<27;i++)
    {
        ara[i]=G(i);
        pf("%d %d\n",i,ara[i]);
    }
    while(t--){
        sf("%I64d",&n);
        if(n>=27)pf("1006\n");
        else{
            int maxi=0;
            for(int i=0;i<=n;i++)
            {
                if(maxi<ara[i])maxi=ara[i];
            }
            pf("%d\n",maxi);
        }

    }

    return 0;
}
