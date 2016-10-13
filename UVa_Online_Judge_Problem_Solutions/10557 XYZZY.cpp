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
#define inf -100000007
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
#define II ({int a; sf1(a); a;})
using namespace std;
typedef long long int lint;
typedef double dbl;
int node[107];
struct Edge{
    int u, v;
    Edge(int a, int b)
    {
        u = a;
        v = b;
    }
};
int dist[107], n;
vector<Edge> E;
bool bell_ford()
{
    for(int i = 2; i<= n ; i++) dist[i] = inf;
    dist[1] = 100;
    FOR(i, n){
        int f = 0;
        for(Edge e : E)
        {
            if(dist[e.v] < dist[e.u] + node[e.v] && dist[e.u] + node[e.v]>0 && node[e.u]!=inf)
            {
                f++;
                dist[e.v] = dist[e.u] + node[e.v];
            }
        }
        if(!f) break;
    }
    int f = 0;
    for(Edge e : E)
        {
            if(dist[e.v] < dist[e.u] + node[e.v] && dist[e.u] + node[e.v]>0 && node[e.u]!=inf)
            {
                f++;
                dist[e.v] = dist[e.u] + node[e.v];
            }
        }
    if(!f) if(dist[n]!=inf) f = 1;
    return f;
//    FOR(i, n-1) pf("%d %d ",i+1, dist[i+1]);
//    pf("***\n");
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, tst = 1;
    while(sf1(n) && n!=-1)
    {
        E.clear();
        for(int i = 1; i<=n ; i++)
        {
            sf1(node[i]);
            int q ;
            sf1(q);
            FOR(j ,q)
            {
                int u;
                sf1(u);
                E.pb(Edge(i, u));
            }

        }

        if(!bell_ford()) pf("hopeless\n");
        else pf("winnable\n");
    }
    return 0;
}

