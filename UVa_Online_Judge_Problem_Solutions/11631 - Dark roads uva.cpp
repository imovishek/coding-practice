#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a)
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
#define FOR1(i,x) for(int i=1;i<=(x); i++)
#define mx 200001
using namespace std;
typedef long long int lint;
typedef double dbl;
int par[mx + 7];
int id(int n)
{
    if(par[n]!=n) par[n] = id(par[n]);
    return par[n];
}
struct data{
    int u, v, w;
    bool operator < (const data &a)
    {
        return w < a.w;
    }
} edge[mx+7];

int n, m;
lint MST()
{
    lint ans = 0;
    sort(edge, edge+m);
    FOR1(i, n) par[i] = i;
    FOR(i, m)
    {
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;
        int x = id(u), y = id(v);
        if(x!=y)
        {
            par[y] = x;
            ans += 0LL + w;
        }
    }
    return ans;
}
int main()
{
    int t, tst = 1;
    while(sf2(n, m)){
        if(n==0 && m==0) return 0;
        lint ans = 0;
        FOR(i, m)
        {
            sf3(edge[i].u, edge[i].v, edge[i].w);
            ans += 0LL + edge[i].w;
        }
        ans -= MST();
        pf("%lld\n", ans);
    }
    return 0;
}














