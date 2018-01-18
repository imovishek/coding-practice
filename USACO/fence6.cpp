/*
ID: ovishek1
LANG: C++11
PROB: fence6
*/

#include <bits/stdc++.h>
using namespace std;
#define mx 106
vector<int> edge[mx][2];
int len[mx];
int dist[mx];
int dijkstra(int u)
{
    int st = u, ret = INT_MAX;
    priority_queue<pair<int, pair<int, int> > > pQ;
    pQ.push({-len[u], {u, -1}});
    for(int i = 1; i<mx; i++) dist[i] = INT_MAX;
    dist[u] = len[u];
    while(!pQ.empty())
    {
        auto top = pQ.top(); pQ.pop();
        u = top.second.first;
        int p = top.second.second;
        int d = -top.first;
//        cout << u << " -------- " << d << endl;
        int sig = 0;
        if(p==-1){
            for(int v : edge[u][1])
            {
                //cout << v << " )))))))) " << p << endl;
                if(v != p){
                    if(ret - d > dist[v] - len[st])
                        ret = dist[v] - len[st] + d;
                }
                if(v != p && dist[v] - len[v] > d)
                {
                    dist[v] = d + len[v];
                    pQ.push({-dist[v], {v, u}});
                }
            }
        }
        else if(binary_search(edge[u][0].begin(), edge[u][0].end(), p)) sig = 1;
        else sig = 0;
        for(int v : edge[u][sig])
        {
            //cout << v << " )))))))) " << p << endl;
            if(v != p){
                if(ret - d > dist[v] - len[st])
                    ret = dist[v] - len[st] + d;
            }
            if(v != p && dist[v] - len[v] > d)
            {
                dist[v] = d + len[v];
                pQ.push({-dist[v], {v, u}});
            }
        }
    }
    return ret;
}
int main()
{
    freopen("fence6.in", "r", stdin);
    freopen("fence6.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++)
    {
        int u, l, a, b, v;
        scanf("%d %d %d %d", &u, &l, &a, &b);

        for(int j = 0; j<a; j++)
        {
            scanf("%d", &v);
            edge[u][0].push_back(v);
        }
        for(int j = 0; j<b; j++)
        {
            scanf("%d", &v);
            edge[u][1].push_back(v);
        }
        sort(edge[u][0].begin(), edge[u][0].end());
        sort(edge[u][1].begin(), edge[u][1].end());
        len[u] = l;
    }
    int ans = INT_MAX;
//    cout << dijkstra(2) << endl;
    for(int i = 1; i<=n; i++)
        ans = min(ans, dijkstra(i));
    printf("%d\n", ans);

    return 0;
}

