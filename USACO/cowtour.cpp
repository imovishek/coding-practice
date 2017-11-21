/*
ID: ovishek1
LANG: C++11
PROB: cowtour
*/
#include <bits/stdc++.h>
using namespace std;
#define mx 155
vector< pair<int, int> > vt;
vector<int> edge[mx];
int graph[mx][mx];
double shortestDistance(int i, int j)
{
    double minx = min(abs(vt[i].first - vt[j].first), abs(vt[i].second - vt[j].second));
    return sqrt(1ll * abs(vt[i].first - vt[j].first) * abs(vt[i].first - vt[j].first) + 1ll * abs(vt[i].second - vt[j].second) * abs(vt[i].second - vt[j].second));
}
int n;
int VIS[mx];
double LiveMAX;
int nowi, nowj;
int dijkstra(int u)
{
    int col = u+1;
    vector<double> dist = vector<double> (n, 2000000000000.0);
    dist[u] = 0;
    int vis[n];
    memset(vis, 0, sizeof vis);
    priority_queue<pair<double, int> > pQ;
    pQ.push({0, u});
    int ret;
    while(!pQ.empty())
    {
        auto top = pQ.top(); pQ.pop();
        u = top.second;
        if(vis[u] == 1) continue;
        ret = u;
        LiveMAX = -top.first;
        vis[u] = 1;
        if(!VIS[u]) VIS[u] = col;
        for(int v = 0; v < n; v++)
        {
            if(graph[u][v] == 1){
                if(dist[v] > dist[u] + shortestDistance(u, v)){
                    dist[v] = dist[u] + shortestDistance(u, v);
                    pQ.push({-dist[v], v});
                }
            }
        }

    }
    return ret;
}

double minDiameter(int xx = -1)
{
    double maxi = 0.0;
        int to = dijkstra(xx);
        int from = dijkstra(to);
        double now = LiveMAX;
        //cout << "now " << to << " : " << dist[to] << " " << from << " " << now << endl;
        maxi = max(maxi, now);

    return maxi;
}
double dist[mx][mx];

int main()
{
    freopen("cowtour.in", "r", stdin);
    freopen("cowtour.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 0; i<n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        vt.push_back({x, y});
    }
    //cout << shortestDistance(0, 5) << "                ***" << endl;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            dist[i][j] = 10000000000120.0, dist[i][i] = 0;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++){
            scanf("%1d", &graph[i][j]);
            if(graph[i][j]) dist[i][j] = shortestDistance(i, j);
            //if(graph[i][j]) edge[i].push_back(j), edge[j].push_back(i);
        }
    for(int k = 0; k<n; k++)
        for(int i = 0; i<n; i++)
            for(int j = 0; j<n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
//    for(int i = 0; i<n; i++)
//    {
//        cout << "twing " ;
//        for(int j = 0; j<n; j++)
//            cout << dist[i][j] << " ";
//        cout << endl;
//    }
    double large[n], ans = 1010200102100.0;
    for(int i = 0; i<n; i++){
        large[i] = 0;
//        cout << i << " - >";
        for(int j =0 ; j<n; j++){
            if(dist[i][j] < 10000000000120.0){
                large[i] = max(large[i], dist[i][j]);
//                cout << j << " ";
            }
//            ans = max(ans, large[i]);
        }
//        cout << endl;
        //cout << large[i] << " " ;
    }
    //cout << endl;
    double ans0[n+2];
    for(int i = 0; i<=n+1; i++)
        ans0[i] = 0;

    for(int i = 0; i<n; i++)
        dijkstra(i);
//    for(int i = 0; i<n; i++)
//        cout << VIS[i] << " - ";
//    cout << endl;
    for(int i = 0; i<n; i++){
       ans0[VIS[i]] = max(ans0[VIS[i]], large[i]);
    }
//    for(int i = 0; i<=n; i++)
//        cout << ans0[i] << " ";
//    cout << endl;
    //cout << endl;
    //graph[0][5] = graph[5][0] = 1;
    //cout << minDiameter() << endl;

    //cout << endl;
    //return 0;
    for(int i = 0; i<n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            if(graph[i][j]==0 && VIS[i] != VIS[j]){
                double x;
                ans = min(ans, x = max(ans0[VIS[i]], max(ans0[VIS[j]], large[i] + large[j] + shortestDistance(i, j))));
                //cout << i << " " << j << " " << " " << x << endl;
            }
        }
    }
    printf("%.6f\n", ans);
    return 0;
}
