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
vector<pii> edge[100007];
int dist[100007];
int vis[100007];
int maxi[100007];
class comp{
public:
    bool operator()(const pii &a, const pii &b) const{
        return a.sc<b.sc;
    }
};

int n, m, s, t, p;
int dijkstra()
{
    for(int i = 1; i<=n; i++){ dist[i] = -inf; vis[i] = 0;}
    dist[s] = 0;
    priority_queue<pii, vector<pii>, comp> pQ;
    pQ.push(pii(s, 0));
    maxi[s] = -inf;
    while(!pQ.empty())
    {
        int u = pQ.top().fs;
        if(u==t) return maxi[u];
        pQ.pop();
        vis[u] = 1;
        FOR(i, edge[u].size())
        {
            int v = edge[u][i].fs;
            int w = edge[u][i].sc;
            if(!vis[v] && dist[v] < dist[u] + w && dist[u] + w <= p)
            {
                dist[v] = dist[u] + w;
                maxi[v] = max(maxi[u], w);
                pQ.push(pii(v, maxi[v]));
            }
        }
    }
    return -inf;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int ti, tst = 1;
    sf1(ti);
    while(ti--)
    {
        sf3(n, m, s);
        sf2(t, p);
        FOR(i, m)
        {
            int u, v, w;
            sf3(u, v, w);
            edge[u].pb(pii(v, w));
        }
        mem(maxi, 0);
        int sig = dijkstra();
        pcase(tst++);
        if(sig==-inf) pf("-1\n");
        else pf1(maxi[t]);
        FOR(i, n+1) edge[i].clear();
    }
    return 0;
}
