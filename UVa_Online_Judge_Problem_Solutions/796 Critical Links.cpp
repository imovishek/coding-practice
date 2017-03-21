#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a);
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pcase(x) printf("Case %d:\n",x)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
#define mx 100007
using namespace std;
typedef long long int lint;
typedef double dbl;

int n, m;
vector<int>edge[mx];
int low[mx], disc[mx], vis[mx];
vector<pii> vt;
bool comp(pii a, pii b)
{
    if(a.fs==b.fs) return a.sc<b.sc;
    return a.fs<b.fs;
}
void bridge(int u, int p)
{
    vis[u]=1;
    static int T = 1;
    low[u] = disc[u] = T++;
    int counti = 0;
    FOR(i, edge[u].size())
    {
        int v = edge[u][i];
        if(!vis[v])
        {
            counti++;
            bridge(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v]>disc[u]) {
                if(u<v) vt.pb(pii(u,v));
                else vt.pb(pii(v,u));
            }
        }
        else if(v!=p){
            low[u] = min(low[u], disc[v]);
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, tst = 1;
    while(sf1(n)!=EOF)
    {
        FOR(i, n)
        {
            int u, v, m;
            sf("%d (%d)", &u, &m);
            FOR(i, m)   {
                sf1(v);
                edge[u].pb(v);
                edge[v].pb(u);
            }
        }
        vt.clear();
        mem(vis, 0);
        FOR(i, n) if(!vis[i])bridge(i, -1);
        sort(vt.begin(), vt.end(), comp);
        pf("%d critical links\n", vt.size());
        FOR(i, vt.size())
        {
            pf("%d - %d\n", vt[i].fs, vt[i].sc);
        }
        puts("");
        FOR(i, n) edge[i].clear();

    }
    return 0;
}
