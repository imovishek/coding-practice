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
struct data{
    int u, v, w;
    bool operator < (const data &a) const{
        return w<a.w;
    }
};

int n, m;
int par[1007];
data ara[1007];
int t, tst = 1;
vector<pii> edge[1007];


int find(int u)
{
    if(par[u]!=u) par[u] = find(par[u]);
    return par[u];
}
int vis[1007], bigflag = 0;
int dfs(int u, int en, int p, int mini)
{
    if(vis[u]) return inf;
//    pf("%d**\n", u);
    vis[u] = 1;
    if(u==en && p!=-1) {
            return mini;
    }
    int minimum = inf;
    FOR(i, edge[u].size()){
        minimum = min(minimum , dfs(edge[u][i].fs, en, u, min(mini, edge[u][i].sc)));
        if(bigflag) return minimum;
    }
}
int kruskal()
{
    sort(ara, ara+m);
    int flag[m+7];
    mem(flag, -1);
    mem(vis, 0);
    bigflag = 0;
    FOR(i, n) edge[i+1].clear();
    FOR(i, n) par[i+1] = i+1;
    int ans = 0;
    FOR(i, m)
    {
        int u = ara[i].u, v = ara[i].v, w = ara[i].w;
//        pf("%d %d %d %d***\n", u, v, w, i);
        int x = find(u), y = find(v);
        if(x!=y){
            par[x] = y;
            ans+=w;
            flag[i] = 0;
            edge[u].pb(pii(v, w));
            edge[v].pb(pii(u, w));
        }
    }
    pf("Case #%d : ", tst++);
    mem(vis, 0);
    dfs(ara[0].u, -1, -1, -1);
    int f = 0;
    FOR(i, n) if(vis[i+1]==0) {f = 1; break;}
    if(f) {pf("No way\n"); return 0;}
    f = 1;
    FOR(i, m) if(flag[i]!=0){f = 0; break;}
    if(f) {pf("No second way\n"); return 0;}
    int mini = inf;
//    pf("%d*###\n", ans);
    FOR(i, m)
    {
        if(flag[i]==-1){
            mem(vis, 0);
            bigflag = 0;
            int x = dfs(ara[i].u, ara[i].v, -1, inf);
//            pf("%d %d %d*******\n", ara[i].u, ara[i].v, x);
            mini = min(mini, ans-x+ara[i].w);
        }
    }
    pf("%d\n", mini);


}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    sf1(t);
    while(t--)
    {
        sf2(n, m);
        FOR(i, m)
        {
            sf3(ara[i].u, ara[i].v, ara[i].w);
        }
        kruskal();
        FOR(i, n+1) edge[i].clear();
        mem(vis, 0);
    }
    return 0;
}



/*

4
5 4
1 2 5
3 2 5
4 2 5
5 4 5
5 3
1 2 5
3 2 5
5 4 5
5 5
1 2 5
3 2 5
4 2 5
5 4 5
4 5 6
1 0


*/










