/*
ID: ovishek1
LANG: C++11
PROB: agrinet
*/
#include <bits/stdc++.h>
#define ll long long
#define mx 105
using namespace std;
int par[mx];
int find(int u)
{
    if(par[u] != u) return par[u] = find(par[u]);
    return par[u];
}
vector<pair<int, pair<int, int> > >edge;
int main()
{
    freopen("agrinet.in", "r", stdin);
    freopen("agrinet.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++) par[i] = i;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++){
            int w;
            scanf("%d", &w);
            edge.push_back({w, {i, j}});
        }
    sort(edge.begin(), edge.end());
    long long ans = 0;
    for(int i = 0; i<edge.size(); i++)
    {
        int u = find(edge[i].second.first), v = find(edge[i].second.second);
        if(u != v)
        {
            ans += edge[i].first;
            par[u] = v;
        }
    }
    printf("%lld\n", ans);
    return 0;
}

