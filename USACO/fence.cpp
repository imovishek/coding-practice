/*
ID: ovishek1
LANG: C++11
PROB: fence
*/

#include <bits/stdc++.h>
using namespace std;
#define mx 501
vector<pair<int, int> > edge[mx];
int deg[mx];
int vis[1250];
vector<int> ans;
int dfs(int u)
{
    for(auto p : edge[u])
    {
        int v = p.first, w = p.second;
        if(vis[w] == 0){
            vis[w] = 1;
            dfs(v);
        }
    }
    ans.push_back(u);
}

int main()
{
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        edge[u].push_back({v, i});
        edge[v].push_back({u, i});
        deg[u]++, deg[v]++;
    }
    int start = INT_MAX;
    for(int i = 1; i<mx; i++)
        if(deg[i] & 1) start = min(start, i);
    if(start == INT_MAX) start = 1;
    for(int i = 1; i<mx; i++) sort(edge[i].begin(), edge[i].end());
    dfs(start);
    reverse(ans.begin(), ans.end());
    for(int x : ans)
        cout << x << endl;
    return 0;
}
