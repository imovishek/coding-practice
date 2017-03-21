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
class comp{
public:
    bool operator()(const pii &a, const pii &b) const{
        return a.sc>b.sc;
    }
};
vector<pii> edge[5007];
int n;
int dist[5007];
int dist2[5007];
pii dir[5007];
int flag[5007];
int dijkstra(int s, int e)
{
    mem(flag, 0);
    for(int i = 1; i<=n ; i++)
        dist[i] = inf;
    dist[s] = 0;
    priority_queue<pii, vector<pii>, comp> pQ;
    pQ.push(pii(s,0));
    dir[s] = pii(-1,0);
    while(!pQ.empty())
    {
        int u = pQ.top().fs;
        pQ.pop();
        flag[u] = 1;
        FOR(i, edge[u].size())
        {
            int v = edge[u][i].fs;
            if(flag[v]==0 && dist[v]> dist[u] + edge[u][i].sc)
            {
                dist[v] = dist[u]+  edge[u][i].sc;
                dir[v] = pii(u, i);
                pQ.push(pii(v, dist[u] + edge[u][i].sc));
            }
        }
    }
    return dist[e];
}
int srt;

int mini = 0;
void find_path_min(int u)
{
    if(dir[u].fs==-1) return;
    mini = min(mini, edge[dir[u].fs][dir[u].sc].sc);
    find_path_min(dir[u].fs);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        int m;
        sf2(n, m);
        FOR(i, m)
        {
            int u, v, w;
            sf3(u, v, w);
            edge[u].pb(pii(v, w));
            edge[v].pb(pii(u, w));
        }
        srt = dijkstra(1 , n);
        for(int i = 0; i<=n ; i++) {dist2[i] = dist[i]; /*pf("%d ",dist[i]);*/}
//        pf("\n");
        dijkstra(n, 1);
//        for(int i = 0; i<=n ; i++) {pf("%d ",dist[i]);}
//        pf("\n");

        int ans = inf;
        for(int i = 1; i<=n ; i++)
        {
            FOR(j, edge[i].size())
            {
                int v = edge[i][j].fs;
                int w = edge[i][j].sc;
                if(dist2[i] + w + dist[v]!=srt)
                    ans = min(ans, dist2[i] + w + dist[v]);
                if(dist2[i] + w*3 + dist[v]!=srt)
                    ans = min(ans, dist2[i] + w*3 + dist[v]);
//                pf("*%d %d *%d %d\n",dist2[i] + w + dist[v], dist2[i] + w*3 + dist[v], i, v);
            }
        }
//        pf("%d**\n", srt);
        pcase(tst++);
        pf("%d\n", ans);

        FOR(i, n+1) edge[i].clear();
    }
    return 0;
}
/*

5
4 4
1 2 100
1 3 200
2 3 250
3 4 100

3
4 4
1 3 3
3 1 2
4 3 3
3 1 5
2 8
1 2 4
2 1 5
1 2 2
2 1 5
2 1 7
2 1 8
2 1 8
2 1 3
4 5
1 2 3
2 3 7
3 4 4
1 2 4
4 1 4
*/

