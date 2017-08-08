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
#define mx              800007

using namespace std;
typedef long long int lint;
typedef double dbl;
vector<int> edge[mx];
int dist[mx];
int n;
int bfs(int t, int g)
{
    queue<int> q;
    q.push(t);
    FOR1(i, n) dist[i] = -1;
    dist[t] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        if(u==g) return dist[u];
        FOR(i, edge[u].size())
        {
            int v = edge[u][i];
            if(dist[v]==-1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return -1;
}

int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        int m;
        sf2(m, n);
        int ara[n+1];
        FOR1(i, n) sf1(ara[i]);
        FOR(i, m){
            int u, v;
            sf2(u, v);
            edge[u].pb(v);
            edge[v].pb(u);
        }
        int t, g;
        sf2(t, g);
        int sig = bfs(t, g);
        pcase(tst++);
        if(sig==-1){
            pf("Path not found\n");
        }
        else{
            if(ara[g]<sig) pf("Don't travel\n");
            else pf("%d\n", ara[g]-sig);
        }
        FOR1(i, n) edge[i].clear();
    }
    return 0;
}














