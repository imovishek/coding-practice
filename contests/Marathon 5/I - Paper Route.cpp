#include<bits/stdc++.h>
#define pii pair<lint,lint>
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
#define sf1ll(a) scanf("%I64d",&a)
#define sf2ll(a,b) scanf("%I64d %I64d",&a,&b)
#define sf3ll(a,b,c) scanf("%I64d %I64d %I64d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
#define mx 100000
using namespace std;
typedef long long int lint;
typedef double dbl;

vector<pii> edge[mx+7];
lint dist[mx+7];
bool vis[mx+7];
lint whole = 0, ans = inf;
void dfs(lint u, lint sum)
{
    vis[u] = 1;
    ans = min(ans, whole - sum + dist[u]);

    FOR(i, edge[u].size())
    {
        lint v = edge[u][i].fs;
        lint w = edge[u][i].sc;
        if(!vis[v]){
            dfs(v, sum+0LL+w);
        }
    }
}
void clear(lint n)
{
    FOR(i, n+1) edge[i].clear();
    mem(vis, 0);
    whole = 0;
    ans = inf;
}

int main()
{
    int t, tst = 1;
    lint n;
    while(sf1ll(n)!=EOF)
    {
        clear(n);
        FOR(i, n+1) sf1ll(dist[i]);
        FOR(i, n)
        {
            lint u, v, w;
            sf3ll(u, v, w);
            edge[u].pb(pii(v, w));
            edge[v].pb(pii(u, w));
            whole += 0LL + w + w;
        }
        ans = whole + dist[0];
        dfs(0, 0);
        pf("%I64d\n", ans);
    }
    return 0;
}

/*


4
1234567
10000050
208005090
184839384
234585454
0 1 100000000
0 2 34563243
1 3 12345678
2 4 1000000000


*/












