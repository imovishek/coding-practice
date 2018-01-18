/*
ID: ovishek1
LANG: C++11
PROB: comehome
*/
#include <bits/stdc++.h>
using namespace std;
#define mx 201
#define MOD 1000000007
vector<int> edge[200];
int wgt[mx][mx];
int main()
{
    freopen("comehome.in", "r", stdin);
    freopen("comehome.out", "w", stdout);
    for(int i = 1; i<mx; i++)
        for(int j = 1; j<mx; j++)
            wgt[i][j] = MOD;
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++)
    {
        char u, v;
        int w;
        scanf(" %c %c %d", &u, &v, &w);
        edge[u].push_back(v);
        edge[v].push_back(u);
        wgt[u][v] = wgt[v][u] = min(wgt[u][v], w);
    }
    int dist[mx], par[mx];
    for(int i = 0; i<mx; i++) dist[i] = MOD;
    priority_queue< pair<int, int> > pQ;
    for(char i = 'A'; i < 'Z'; i++)
        pQ.push({0, i}), dist[i] = 0, par[i] = i;
    int u;
    while(!pQ.empty())
    {
        auto top = pQ.top(); pQ.pop();
        u = top.second;
        if(u=='Z'){
            break;
        }
        for(int v : edge[u])
        {
            if(dist[v] > dist[u] + wgt[u][v])
            {
                par[v] = u;
                dist[v] = dist[u] + wgt[u][v];
                pQ.push({-dist[v], v});
            }
        }
    }
    int dis = dist[u];
    while(par[u] != u) u = par[u];
    printf("%c %d\n", char(u), dis);
    return 0;
}
