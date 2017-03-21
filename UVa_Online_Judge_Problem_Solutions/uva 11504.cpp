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

using namespace std;
typedef long long int lint;
typedef double dbl;
#define mx 100007
int n, m;
vector<int> edge[mx];
int vis[mx];
vector<int> vt;
void dfs(int u)
{
    vis[u] = 1;
    FOR(i, edge[u].size())
    {
        int v = edge[u][i];
        if(!vis[v])
            dfs(v);
    }
    vt.pb(u);
}
int main()
{
    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        sf2(n, m);
        FOR(i, m)
        {
            int u, v;
            sf2(u, v);
            edge[u].pb(v);
        }
        mem(vis, 0);
        vt.clear();
        FOR(i, n)if(!vis[i+1]) dfs(i+1);
        reverse(vt.begin(), vt.end());
        vector<int> res = vt;
        mem(vis, 0);
        int cnt = 0;
        FOR(i, res.size()){
            int v = res[i];
            if(!vis[v]) {dfs(v); cnt++;}
        }
        pf1(cnt);
        FOR(i, n+1) edge[i].clear();
    }
    return 0;
}














