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
vector<int> edge[107];
vector<string> vt;
string ara[107];
int n, vis[107], disc[107], low[107], arti[107];
void clear()
{
    FOR(i, n)
        edge[i].clear();
    mem(disc, 0);
    mem(low, 0);
    mem(vis, 0);
    mem(arti, 0);
    vt.clear();
}
int cnt = 0;
void ap(int u, int p)
{
//    pf("%d**\n", u);
    vis[u] = 1;
    static int T = 1;
    int counti = 0;
    low[u] = disc[u] = T++;
    FOR(i, edge[u].size())
    {
        int v = edge[u][i];
        if(!vis[v]){
            counti++;
            vis[v] = 1;
            ap(v, u);
            low[u] = min(low[u], low[v]);
            if(p==-1){
                if(counti>1 && !arti[u]){
                    arti[u] = 1;
                    cnt++;
                    vt.pb(ara[u]);
                }
            }
            else if(low[v]>=disc[u]){
                if(!arti[u]){
                    arti[u] = 1;
                    cnt++;
                    vt.pb(ara[u]);
                }
            }
        }
        else if(p!=v){
            low[u] = min(low[u], disc[v]);
        }
    }
}
int main()
{
    int t, tst = 0;
    int m;
    while(sf1(n) && n)
    {
        if(tst++>0) pf("\n");
        string u, v;
        map<string, int> mp;
        clear();
        FOR(i, n) {
            cin >> u;
            mp[u] = i;
            ara[i] = u;
        }
        sf1(m);
        int x, y;
        FOR(i, m)
        {
            cin >> u >> v;
            x = mp[u], y = mp[v];
            edge[x].pb(y);
            edge[y].pb(x);
//            pf("%d %d*\n", x, y);
        }
        cnt = 0;
        FOR(i, n) if(!vis[i])ap(i, -1);
        pf("City map #%d: %d camera(s) found\n", tst, cnt);
        sort(vt.begin(), vt.end());
        FOR(i, vt.size())
            pf("%s\n", vt[i].c_str());

    }
    return 0;
}
/*

6
sugarloaf
maracana
copacabana
ipanema
corcovado
lapa
7
ipanema copacabana
copacabana sugarloaf
ipanema sugarloaf
maracana lapa
sugarloaf maracana
corcovado sugarloaf
lapa corcovado

5
guanabarabay
downtown
botanicgarden
colombo
sambodromo
4
guanabarabay sambodromo
downtown sambodromo
sambodromo botanicgarden
colombo sambodromo
0


*/













