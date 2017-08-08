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

vector<pii> edge[mx];
bool vis[mx];
int maxi = 0;
int dfs(int u, int sum)
{
    vis[u] = 1;
    FOR(i, edge[u].size())
    {
        int v = edge[u][i].fs;
        if(!vis[v]) dfs(v, edge[u][i].sc + sum);
    }
    maxi = max(maxi, sum);
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
        int n, allsum = 0;
        sf1(n);
        FOR(i, n-1)
        {
            int u, v, w;
            sf3(u, v, w);
            edge[u].pb(pii(v, w));
            edge[v].pb(pii(u, w));
            allsum += w;
        }
        maxi = 0;
        mem(vis, 0);
        dfs(1, 0);
        pcase(tst++);
        pf1(2*allsum - maxi);
        FOR1(i, n) edge[i].clear();
    }
    return 0;
}














