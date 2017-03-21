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
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
using namespace std;
typedef long long int lint;
typedef double dbl;
int seq[25],ara[25],dp[25],dir[25];
int n;
bool compare(int u, int v)
{
    int i;
    for(i=0;i<n;i++) if(seq[i]==ara[u]) break;
    for(int j=i+1; j<n ;j++) if(seq[j]==ara[v])return true;
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
            if(LIS(v)> maxi){
                maxi=LIS(v);
                dir[u]=v;
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
        u=dir[u];
    }
    pf("*\n");
}
int main()
{
    sf1(n);
    int ara1[25];
    FOR(i,n) sf1(ara1[i]);
    FOR(i, n){
            seq[ara1[i]-1]=i+1;
    }
    while(sf1(ara1[0])!=EOF)
    {
        mem(dp, -1);
        mem(dir, -1);
        for(int i=1; i<n; i++){
            sf1(ara1[i]);
        }
        FOR(i, n){
            ara[ara1[i]-1]=i+1;
        }
        int maxi=0, pos;
        FOR(i, n)
            if(LIS(ara[i]-1) > maxi) {
                    maxi=LIS(ara[i]-1);
                    pos=i;
            }
        pf("%d\n", maxi);
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
