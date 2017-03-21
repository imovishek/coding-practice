#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#define pii pair<int,int>
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pcase(x) printf("DATA SET  %d\n\n",x)
#define pi acos(-1.0)
#define FOR(i,x) for(int i=0; i<x ;i++)
#define inf 2147483647
#define mem(arr, x) memset(arr, x, sizeof(arr))
using namespace std;
typedef long long int lint;
typedef double dbl;
vector < int > edge[50];
int level[50];
int bfs(int st, int en)
{
    queue<int>Q;
    Q.push(st);
    level[st] = 0;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int i = 0 ; i < edge[u].size(); i++)
        {
            int v = edge[u][i];
            if(level[v]==-1){
                level[v] = level[u] + 1;
                Q.push(v);
            }
            if(v == en) return level[v];
        }
    }
    return -1;
}
int main()
{
    #ifdef OVI
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t,m,n,p,tst = 1;
    sf1(t);
    pf("SHIPPING ROUTES OUTPUT\n\n");
    while(t--)
    {
        sf3(m, n, p);
        map < string, int > mp;
        string u, v;
        int a, b, pos = 0;
        FOR(i, m) {
            cin >> u;
            mp[u]=pos++;
        }
        FOR(i, n)
        {
            cin >> u >> v;
            a = mp[u];
            b = mp[v];

            edge[a].pb(b);
            edge[b].pb(a);
        }
        pcase(tst++);
        FOR(i, p)
        {
            int cost;
            cin >> cost >> u >> v;
            mem(level, -1);
            int dist = bfs(mp[u], mp[v]);
            if(dist!=-1) pf("$%d\n", 100 * dist * cost);
            else pf("NO SHIPMENT POSSIBLE\n");
        }
        pf("\n");
        FOR(i, m) edge[i].clear();
        mp.clear();
    }
    pf("END OF OUTPUT\n");

    return 0;
}
