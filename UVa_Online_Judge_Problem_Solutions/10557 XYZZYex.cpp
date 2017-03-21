#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#define pii pair<int,int>
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a);
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf -100000007
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
#define II ({int a; sf1(a); a;})
using namespace std;
typedef long long int lint;
typedef double dbl;
int node[107];
vector<int> edge[107];
int dist[107], n;
int flag[107];
bool dfs(int s)
{
    if(s==n) return 1;
    FOR(i, edge[s].size())
    {
        if(flag[edge[s][i]]==0){
            flag[edge[s][i]] = 1;
            if(dfs(edge[s][i])) return 1;
        }
    }
    return 0;
}
bool bell_ford()
{
    for(int i = 2; i<= n ; i++) dist[i] = inf;
    dist[1] = 100;
    FOR(i, n){
        int f = 0;
        for(int j = 1; j<=n ; j++)
        FOR(k, edge[j].size())
        {
            int v = edge[j][k];
            if(dist[v] < dist[j] + node[v] && dist[j] + node[v]>0 && node[j]!=inf)
            {
                f++;
                dist[v] = dist[j] + node[v];
            }
        }
        if(!f) break;
    }
    int f = 0;
        for(int j = 1; j<=n ; j++)
        FOR(k, edge[j].size())
        {
            int v = edge[j][k];
            if(dist[v] < dist[j] + node[v] && dist[j] + node[v]>0 && node[j]!=inf)
            {
                f++;
                mem(flag, 0);
                flag[v] = 1;
                if(dfs(v)) return 1;
                dist[v] = dist[j] + node[v];
            }
        }
    if(dist[n]!=inf) f = 1;
    else f = 0;
    return f;
//    FOR(i, n-1) pf("%d %d ",i+1, dist[i+1]);
//    pf("***\n");
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, tst = 1;
    while(sf1(n) && n!=-1)
    {
        for(int i = 1; i<=n ; i++)
        {
            sf1(node[i]);
            int q ;
            sf1(q);
            FOR(j ,q)
            {
                int u;
                sf1(u);
                edge[i].pb(u);
            }

        }
        if(!bell_ford()) pf("hopeless\n");
        else pf("winnable\n");
        FOR(i, n+1) edge[i].clear();
    }
    return 0;
}


