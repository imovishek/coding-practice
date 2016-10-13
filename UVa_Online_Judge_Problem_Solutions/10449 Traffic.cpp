#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#define pii pair<int,int>
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a);
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 100000007
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)

using namespace std;
typedef long long int lint;
typedef double dbl;
struct Edge{
    int u, v, w;
    Edge(int a, int b, int c)
    {
        u = a;
        v = b;
        w = c;
    }
};
vector<Edge>E;
int dist[205], n;
void bellman_ford(int s)
{
    for(int i = 1; i<205; i++) dist[i] = inf;
    dist[s] = 0;
    FOR(i, n)
    {
        int f = 0;
        for(Edge e : E)
            if(dist[e.v] > dist[e.u] + e.w && dist[e.u]!=inf)
            {
                dist[e.v] = dist[e.u] + e.w;
                f++;
            }
        if(!f) break;
    }

    for(Edge e : E)
            if(dist[e.v] > dist[e.u] + e.w && dist[e.u]!=inf)
            {
                dist[e.v] = -inf;
            }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, tst = 1;
    while(sf1(n)==1)
    {

        int ara[n+1];
        for(int i = 1; i<=n ; i++) sf1(ara[i]);
        int r;
        sf1(r);
        FOR(i, r){
            int u, v;
            sf2(u, v);
            E.pb(Edge(u, v, (ara[v]-ara[u]) * (ara[v]-ara[u]) * (ara[v]-ara[u])));
        }
        bellman_ford(1);
        int q;
        sf1(q);
        pf("Set #%d\n",tst++);
        FOR(i, q)
        {
            int a;
            sf1(a);
            if(dist[a]<3 || dist[a]==inf) pf("?\n");
            else pf("%d\n",dist[a]);
        }
        E.clear();

    }
    return 0;
}










