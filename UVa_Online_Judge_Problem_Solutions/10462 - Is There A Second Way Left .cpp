/*
OVISHEK PAUL, CSE - 15, SUST

*/

#include<bits/stdc++.h>
#define pii             pair<int,int>
#define mkp             make_pair
#define fs              first
#define sc              second
#define pb              push_back
#define ppb             pop_back()
#define pf              printf
#define pf1(a)          printf("%d\n",a)
#define hi              printf("hi!\n");
#define sf              scanf
#define sf1(a)          scanf("%d",&a)
#define sf2(a,b)        scanf("%d %d",&a,&b)
#define sf3(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define sf1ll(a)        scanf("%lld",&a)
#define sf2ll(a,b)      scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c)    scanf("%lld %lld %lld",&a,&b,&c)
#define pcase(x)        printf("Case %d: ",x)
#define MOD             1000000007
#define inf             1000000007
#define pi              acos(-1.0)
#define mem(arr,x)      memset((arr), (x), sizeof((arr)));
#define FOR(i,x)        for(int i=0;i<(x); i++)
#define FOR1(i,x)       for(int i=1;i<=(x); i++)
#define mx              100007

using namespace std;
typedef long long int lint;
typedef double dbl;
int par[107];
int id(int n)
{
    if(par[n]!=n) par[n] = id(par[n]);
    return par[n];
}

struct data
{
    int u, v, w;
    bool operator<(const data &a)const
    {
        return w<a.w;
    }
} edge[207];
int flag[207];
vector<int> G[107];
int n, m;
int kruskal(int sig = 0)
{
    FOR1(i, n) par[i] = i;
    int ans = 0;
    FOR(i, m)
    {
        if(flag[i]==0) continue;
        int x = id(edge[i].u), y = id(edge[i].v);
        if(x!=y)
        {
            ans+=edge[i].w;
            par[x] = y;
            if(sig)
            {
                flag[i] = 1;
            }
            G[edge[i].u].pb(edge[i].v);
            G[edge[i].v].pb(edge[i].u);

        }
    }
    return ans;
}
int vis[107];
int dfs(int u)
{
    if(vis[u]) return 0;
    vis[u] = 1;
    FOR(i, G[u].size())
    dfs(G[u][i]);
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        sf2(n, m);

        FOR(i, m)
        {
            data &a = edge[i];
            sf3(a.u, a.v, a.w);
        }
        sort(edge, edge+m);
        mem(flag, -1);
        FOR1(i, n) G[i].clear();
        int ans = inf;
        kruskal(1);
        mem(vis, 0);
        dfs(1);
        int f = 0;
        FOR1(i, n)
        if(vis[i]==0)
        {
            f = 1;
            break;
        }
        pf("Case #%d : ", tst++);
        if(f)
        {
            pf("No way\n");
            continue;
        }
        f = 0;
        FOR(i, m) if(flag[i] == -1)
        {
            f = 1;
            break;
        }
        if(!f)
        {
            pf("No second way\n");
            continue;
        }
        FOR(i, m)
        {
            if(flag[i]==1)
            {
                flag[i] = 0;
                mem(vis, 0);
                FOR1(i, n) G[i].clear();
                int now = kruskal();
                dfs(1);
                f = 0;
                FOR1(i, n)
                if(vis[i]==0)
                {
                    f = 1;
                    break;
                }
                if(!f)
                {
                    ans = min(now, ans);
                }
                flag[i] = 1;
            }
        }
        if(ans==inf) pf("No second way\n");
        else pf1(ans);
    }
    return 0;
}

/*
5 5
1 2 5
3 2 5
4 2 5
5 4 5
4 5 6
1 0
*/










