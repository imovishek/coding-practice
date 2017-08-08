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
vector<int>edge[257];
int par[257];
int bfs(int st, int en)
{
    queue<int> Q;
    Q.push(st);
    int dist[257];
    mem(dist, -1);
    dist[st] = 0;
    par[st] = -1;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        if(u==en) return dist[u];
        FOR(i, edge[u].size())
        {
            int v = edge[u][i];
            if(dist[v]==-1)
            {
                par[v] = u;
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }
}
void path(int u)
{
    if(par[u]==-1) {
            pf("%c", u);
            return;
    }
    path(par[u]);
    pf("%c", u);
}

int main()
{
    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        int m, q;
        sf2(m, q);
        FOR(i, m)
        {
            string u, v;
            cin >> u >> v;
            edge[u[0]].pb(v[0]);
            edge[v[0]].pb(u[0]);
        }
        FOR(i, q)
        {
            string u, v;
            cin >> u >> v;
            bfs(u[0], v[0]);
            path(v[0]);
            pf("\n");
        }
        if(t) pf("\n");
        FOR(i, 257) edge[i].clear();
    }
    return 0;
}













