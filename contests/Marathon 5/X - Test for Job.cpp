/*
OVISHEK PAUL, CSE - 15, SUST

*/

#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<cmath>
#define pii             pair<lint,int>
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
#define inf             2147483647
#define pi              acos(-1.0)
#define mem(arr,x)      memset((arr), (x), sizeof((arr)));
#define FOR(i,x)        for(int i=0;i<(x); i++)
#define FOR1(i,x)       for(int i=1;i<=(x); i++)
#define mx              100007

using namespace std;
typedef int lint;
typedef double dbl;
int n, m;
vector<int> G[mx];
lint dist[mx];
lint ara[mx];

int ind[mx], out[mx];
lint maxi = -inf;
lint dp[mx];
lint dfs(vector<int> edge[], int u)
{
    if(out[u]==0) return dp[u] = ara[u];
    if(dp[u]!=-1) return dp[u];
    lint &ret = dp[u];
    ret = -inf;
    FOR(i, edge[u].size())
    {
        int v = edge[u][i];
        ret = max(ret, ara[u] + dfs(edge, v));
    }
    return ret;
}
void clear()
{
    mem(ind, 0);
    mem(out, 0);
    mem(dp, -1);
    maxi = -inf;
    FOR1(i, n) {
        G[i].clear();
    }
}
int main()
{
    int t, tst = 1;
    while(sf2(n, m)==2)
    {
        clear();
        FOR1(i, n) sf1(ara[i]);
        FOR(i, m)
        {
            int u, v;
            sf2(u, v);
            G[u].pb(v);
            ind[v]++;
            out[u]++;
        }
        vector<int> in ;
        FOR1(i, n){
            if(!ind[i]) in.pb(i);
        }

        FOR(i, in.size())
        {
            maxi = max(maxi, dfs(G, in[i]));
        }
        if(maxi== -inf) maxi = 0;
        pf1(maxi);

    }
    return 0;
}

/*

13 12
1 1 3 3 54 1 2 7 4 7 6 5 3
1 2
2 4
4 5
2 7
7 8
1 3
3 9
9 11
9 12
3 10
13 3
13 6

7 5
1
2
2
3
3
4
11
1 2
1 3
2 4
3 4
5 6

*/












