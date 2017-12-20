/*
ID: ovishek1
LANG: C++11
PROB: ditch
*/

#include <bits/stdc++.h>
using namespace std;
#define mx 205
int G[mx][mx];
int par[mx];
int vis[mx];
int n, m;
int bfs(int src, int sink)
{
    queue<int> Q;
    Q.push(src);
    par[src] = -1;
    memset(vis, 0, sizeof vis);
    while(!Q.empty())
    {
        int u = Q.front(); Q.pop();
        vis[u] = 1;
        if(u == sink) return 1;
        for(int v = 1; v <= m; v++)
            if(G[u][v] && vis[v]==0){
                vis[v] = 1;
                par[v] = u;
                Q.push(v);
            }
    }
    return 0;
}

int main()
{
    freopen("ditch.in", "r", stdin);
    freopen("ditch.out", "w", stdout);
//    int n, m;
    scanf("%d %d", &n, &m);
    while(n--)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        G[u][v] += w;
    }
    int ans = 0, cnt = 0;
    while(bfs(1, m))
    {
        //cout << "hi" << endl;
        int mini = INT_MAX;
        int u = m;
        while(par[u] != -1){
            mini = min(mini, G[par[u]][u]);
            u = par[u];
        }
        u = m;
        while(par[u] != -1){
            G[par[u]][u] -= mini;
            G[u][par[u]] += mini;
            u = par[u];
        }
        ans += mini;
    }
    printf("%d\n", ans);
    return 0;
}

