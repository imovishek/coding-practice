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
vector<int> edge[10007];
unsigned long long int cnt = 0, mult = 1, extra = 1;
int low[10007], disc[10007], vis[10007], counti[10007], ex = 0, excnt = 0;
int arti[10007];
int AP(int u, int p)
{
    int counter = 0;
    static int T = 1;
    low[u] = disc[u] = T++;
    vis[u] = 1;
    if(edge[u].size()==1) counti[u] = 1;
    FOR(i, edge[u].size())
    {
        int v = edge[u][i];
        if(!vis[v])
        {
            vis[v] = 1;
            counter++;
            AP(v, u);
            low[u] = min(low[u], low[v]);
            counti[u] = counti[v] + 1;
            if(p==-1){
                if(!arti[v]){
                    excnt++;
                    extra*=counti[v];
                }
                if(counter>1) ex = 1;
            }
            else if(low[v]>=disc[u])
            {
                arti[u] = 1;
                cnt++;
                if(!arti[v])mult*=counti[v];
//                pf("%d %d %lld %lld***\n", u, v, cnt, mult);
            }

        }
        else if(v!=p)
        {
            low[u] = min(low[u], disc[v]);
            counti[u] = 1;
        }
    }
}
int main()
{
    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        int n, m;
        sf2(n, m);
        int u, v;
        FOR(i, n) edge[i].clear();
        FOR(i, m)
        {
            sf2(u, v);
            edge[u].pb(v);
            edge[v].pb(u);
        }
        mem(vis, 0);
        mem(arti, 0);
        FOR(i, n) counti[i] = -inf;
        cnt = 0, mult = 1, extra = 1;
        ex = 0, excnt = 0;
        AP(0, -1);
        if(ex) {
            cnt+=excnt;
            mult*=extra;
//            pf("%d\n", extra);
        }
        pcase(tst++);
        pf("%llu %llu\n", cnt, mult);
    }
    return 0;
}














