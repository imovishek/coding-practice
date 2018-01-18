/*
ID: ovishek1
LANG: C++11
PROB: butter
*/

#include <bits/stdc++.h>
using namespace std;
#define mx 805
vector<pair<int, int> > edge[mx];
int ara[1455];
int n, p, c;
int dijkstra(int u)
{
    priority_queue< pair<int, int> > pQ;
    pQ.push({0, u});
    int dist[mx];
    for(int i = 1; i<mx; i++) dist[i] = INT_MAX;
    dist[u] = 0;
    while(!pQ.empty())
    {
        auto top = pQ.top(); pQ.pop();
        int u = top.second;
        for(auto p : edge[u])
        {
            int v = p.first, w = p.second;
            if(dist[v] - w > dist[u])
            {
                dist[v] = dist[u] + w;
                pQ.push({-dist[v], v});
            }
        }
    }
    int ans = 0;
    for(int i = 1; i<=n; i++)
        ans += dist[ara[i]];
    return ans;
}

int main()
{
    freopen("butter.in", "r", stdin);
    freopen("butter.out", "w", stdout);
    scanf("%d %d %d", &n, &p, &c);
    for(int i = 1; i<=n; i++)
        scanf("%d", &ara[i]);
    while(c--)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }
    int ans = INT_MAX;
    for(int i = 1; i<=p; i++)
        ans = min(ans, dijkstra(i));
    printf("%d\n", ans);
    return 0;
}
