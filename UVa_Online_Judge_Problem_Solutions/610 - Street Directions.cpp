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
vector<int>edge[1007];
vector<pii> vt;
int vis[1007], low[1007], disc[1007];
int dfs(int u, int p)
{
    vis[u] = 1;
    static int T = 1;
    low[u] = disc[u] = T++;
    FOR(i, edge[u].size())
    {
        int v = edge[u][i];
        if(!vis[v]){
            vt.pb(pii(u, v));
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(disc[u]<low[v]){
                vt.pb(pii(v, u));
//                hi
//                pf("%d %d***\n", u, v);
            }
        }
        else if(v!=p){
            if(vis[v]==1)vt.pb(pii(u, v));
            low[u] = min(disc[v], low[u]);
        }
    }
    vis[u] = 2;
}

int main()
{
    int t, tst = 1;
    int n, m;
    while(sf2(n, m))
    {
        if(n==0 && m==0) return 0;
        FOR1(i, n) edge[i].clear();
        vt.clear();
        mem(vis, 0);
        FOR(i, m)
        {
            int u, v;
            sf2(u, v);
            edge[u].pb(v);
            edge[v].pb(u);
        }
        pf1(tst++);
        pf("\n");
        dfs(1, -1);
        FOR(i, vt.size()) pf("%d %d\n", vt[i].fs, vt[i].sc);
        pf("#\n");
    }
    return 0;
}

/*
7 10
1 2
1 3
2 4
3 4
4 5
4 6
5 7
6 7
2 5
3 6

7 9
1 2
1 3
1 4
2 4
3 4
4 5
5 6
5 7
7 6

*/












