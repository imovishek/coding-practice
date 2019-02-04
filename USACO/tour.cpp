/*
ID: ovishek1
LANG: C++11
PROB: tour
*/
#include <bits/stdc++.h>

using namespace std;

#define EPS .000001
#define INF 1000000

#define MXN 100000 + 10
#define MXK 110
#define MXQ
#define SZE
#define MOD 1000000007

using namespace std;

///V*E^2 Complexity
///number of augment path * (V+E)
///Base doesn't matter

struct Edge
{
    int to, next, cap, flow, cost;
} edge[MXN];

int head[MXN], tol;
int pre[MXN], dis[MXN];
bool vis[MXN];
int E;
int cost;

void init(int t)
{
    E = t;
    tol = 0;
    memset(head, -1, sizeof head);
}

void addEdge(int u, int v, int cap, int cost)
{

    //cout << u << " " << v << " " << cap << " " << cost << endl; 
    edge[tol].to = v;
    edge[tol].cap = cap;
    edge[tol].cost = cost;
    edge[tol].flow = 0;
    edge[tol].next = head[u];
    head[u] = tol++;

    edge[tol].to = u;
    edge[tol].cap = 0;
    edge[tol].cost = -cost;
    edge[tol].flow = 0;
    edge[tol].next = head[v];
    head[v] = tol++;
}

bool spfa(int s, int t)
{
    queue<int> q;
    for (int i = 0; i < E; i++)
    {
        dis[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    dis[s] = 0;
    vis[s] = true;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].to;
            if (edge[i].cap > edge[i].flow &&
                dis[v] > dis[u] + edge[i].cost)
            {
                dis[v] = dis[u] + edge[i].cost;
                pre[v] = i;
                if (!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    if (pre[t] == -1)
        return false;
    else
        return true;
}

int minCostMaxflow(int s, int t, int &cost)
{
    int flow = 0;
    cost = 0;
    while (spfa(s, t))
    {
        int Min = INF;
        for (int i = pre[t]; i != -1; i = pre[edge[i ^ 1].to])
        {
            if (Min > edge[i].cap - edge[i].flow)
                Min = edge[i].cap - edge[i].flow;
        }
        for (int i = pre[t]; i != -1; i = pre[edge[i ^ 1].to])
        {
            edge[i].flow += Min;
            edge[i ^ 1].flow -= Min;
            cost += edge[i].cost * Min;
            //cout << cost << endl;
        }
        flow += Min;
    }
    return flow;
}

int main()
{
    freopen("tour.in", "r", stdin);
    freopen("tour.out", "w", stdout);
    //ios_base::sync_with_stdio(false);
    int n, m;
    scanf("%d %d", &n, &m);
    init(n+n+2);
    string name[n+1];
    map<string, int> idx;
    for(int i = 1; i<=n; i++)
    {
        cin >> name[i];
        idx[name[i]] = i;
        int nw = 1;
        nw += (i==1);
        nw += (i==n);
        addEdge(i, i+n, nw, -1);
    }

    for(int i = 0; i<m; i++){
        string a, b;
        cin >> a >> b;
        int u = idx[a], v = idx[b];
        if(u > v) swap(u, v);
        addEdge(u + n, v, 1, 0);
    }
    int ans = 0;
    int flow = minCostMaxflow(1, n+n, ans);
    if(flow==2){
        cout << -ans-2 << endl;
    } else{
        cout << 1 << endl;
    }

    return 0;
}
