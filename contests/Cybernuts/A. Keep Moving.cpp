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

vector<int> edge[mx];
int col[mx];

int dfs(int u)
{
    if(col[u]!=-1) return col[u];
    col[u] = 0;
    FOR(i, edge[u].size())
    {
        int v = edge[u][i];
        col[u]|= !dfs(v);
    }
    return col[u];
}

int main()
{
    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        int n, m, x;
        sf3(n, m, x);
        FOR(i, m)
        {
            int u, v;
            sf2(u, v);
            edge[u].pb(v);
        }
        mem(col, -1);
        dfs(x);
        int f = 0;
        FOR(i, edge[x].size())
        {
            if(col[edge[x][i]]==0) {
                f = 1;
                break;
            }
        }
        pcase(tst++);
        if(f) pf("Yes\n");
        else pf("No\n");
        FOR1(i, n) edge[i].clear();

    }
    return 0;
}














