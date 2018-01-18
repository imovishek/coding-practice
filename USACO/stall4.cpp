/*
ID: ovishek1
LANG: C++11
PROB: stall4
*/

#include <bits/stdc++.h>
using namespace std;
#define mx 405
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
        for(int v = 1; v <= n+m+2; v++)
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
    freopen("stall4.in", "r", stdin);
    freopen("stall4.out", "w", stdout);
//    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i<=n; i++)
    {
        int si;
        scanf("%d", &si);
        while(si--){
            int j;
            scanf("%d", &j);
            G[i][j+n] ++;
        }
    }
    int super_src = n+m+1, super_sink = n+m+2;
    for(int i = 1; i<=n; i++)
        G[super_src][i] = 1;
    for(int i = 1; i<=m; i++)
        G[i+n][super_sink] = 1;
    int ans = 0, cnt = 0;
    while(bfs(super_src, super_sink))
    {
        //cout << "hi" << endl;
        int mini = INT_MAX;
        int u = super_sink;
        while(par[u] != -1){
            mini = min(mini, G[par[u]][u]);
            u = par[u];
        }
        u = super_sink;
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


