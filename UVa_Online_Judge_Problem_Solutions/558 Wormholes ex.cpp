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
#define inf 2147483647
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)

using namespace std;
typedef long long int lint;
typedef double dbl;

struct EDGE
{
    int u, v, w;
    EDGE(int a, int b, int c)
    {
        u = a, v = b, w = c;
    }
};
vector<EDGE> E;
int dist[1007];
int n;
bool bellman_ford(int s)
{
    for(int i = 1; i<=n ; i++)
        dist[i] = 1000000007;
    dist[s] = 0;
    FOR(i, n)
    {
        int f = 0;
        for(EDGE e: E)
        {
            if(dist[e.v] > dist[e.u] + e.w)
            {
                f++;
                dist[e.v] = dist[e.u] + e.w;
            }
        }
        if(!f) break;
    }
    int f = 0;
    for(EDGE e: E)
    {
        if(dist[e.v] > dist[e.u] + e.w)
        {
            f++;
            dist[e.v] = dist[e.u] + e.w;
        }
    }
    return f;

}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, tst = 1;
    int m;
    sf1(t);
    while(t--)
    {
        E.clear();
        sf2(n, m);
        FOR(i, m)
        {
            int u, v, w;
            sf3(u, v, w);
            E.pb(EDGE(u,v,w));
        }
        if(bellman_ford(0)) pf("possible\n");
        else pf("not possible\n");

    }
    return 0;
}

