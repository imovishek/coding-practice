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

class comp{
public:
    bool operator()(pii a, pii b)
    {
        return a.sc>b.sc;
    }
};
vector<pii> edge[100007];
int f = 0;
int flag[100007];
int dist[100007];
pii dir[100007];
int n;
int m, k, d;
map<pii, bool> mp;
int dijkstra()
{
    mem(flag, 0);
    for(int i = 1; i<n ; i++) dist[i] = inf;
    priority_queue<pii, vector<pii>, comp> pQ;
    pQ.push(pii(0, 0));
    dir[0] = pii(-1,-1);
    f = 0;
    while(!pQ.empty())
    {
        int u = pQ.top().fs;
        pQ.pop();
        flag[u] = 1;
        if(u==n-1) return dist[n-1];
        FOR(i, edge[u].size())
        {
            int v = edge[u][i].fs;
            int w = edge[u][i].sc;
            if(flag[v]==0 && dist[v] > dist[u] + abs(w))
            {
                if(w<0 && mp.find(pii(u, v))==mp.end()){
                    if(f>=d) continue;
                    mp[pii(u,v)] = 1;
                    f++;
                }
                dir[v] = pii(u, i);
                dist[v] = dist[u] + abs(w);
                pQ.push(pii(v, dist[v]));
            }
        }
    }
    return dist[n-1];
}
int path(int u , int cost )
{
    if(dir[u].fs==-1){return cost; }
    int w = edge[dir[u].fs][dir[u].sc].sc;
    if(w<0){
        cost+=abs(w);
    }
    return path(dir[u].fs, cost);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        sf3(n, m, k);
        sf1(d);
        FOR(i, m)
        {
            int u, v, w;
            sf3(u, v, w);
            edge[u].pb(pii(v, w));
        }
        FOR(i, k)
        {
            int u, v, w;
            sf3(u, v, w);
            edge[u].pb(pii(v, -w));
        }
        f = 0;
        mp.clear();
        int sig = dijkstra();

        pcase(tst++);
        if(sig==inf) pf("Impossible\n");
        else {
            pf("%d\n", sig);
        }
        FOR(i, n) edge[i].clear();
    }
    return 0;
}

