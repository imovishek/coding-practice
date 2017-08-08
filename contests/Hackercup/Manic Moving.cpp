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
int n, m, k;
pii ara[mx];
int grid[107][107];
int dp[107][2][2];

int rec(int u, int vora, int s)
{

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
        sf3(n, m, k);
        FOR1(i, n) FOR1(j, n) grid[i][j] = inf;
        FOR(i, m)
        {
            int u, v, w;
            sf3(u, v, w);
            graph[u][v] = w;
            graph[v][u] = w;
        }
        FOR(i, k)
            sf2(ara[i].fs, ara[i].sc);

        FOR1(i, n)
            FOR1(j, n)
                FOR1(k, n)
                    if(dist[i][k] !=inf && dist[k][j] != inf)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);


        FOR1(i, n) edge[i].clear();
    }
    return 0;
}














