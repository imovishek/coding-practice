#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<set>
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
#define inf 100000007
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)

using namespace std;
typedef long long int lint;
typedef double dbl;
vector<pii> edge[1007];
vector<pii> edge2[1007];
int dist[1007];
int flag[1007];
int flagi[1007];
int n;
set<int> vt;
bool orginal(int a, int orgi, int cost = 0)
{
    if(a==orgi && cost<0) return 1;
    if(flagi[a]) return 0;
    flagi[a] = 1;
    int x =  0;
    FOR(i, edge[a].size())
    x|= orginal(edge[a][i].fs, orgi, cost+edge[a][i].sc);
    return x;
}
void dfs(int a)
{
    if(flag[a]) return;
    flag[a] = 1;
    vt.insert(a);
    FOR(i, edge2[a].size())
    dfs(edge2[a][i].fs);
}
bool bell()
{
    for(int i = 0; i<n ; i++) dist[i] = 0;
    dist[0] = 0;
    FOR(i, n)
    {
        int f = 0;
        FOR(j, n)
        FOR(k, edge[j].size())
        {
            int v = edge[j][k].fs;
            int w = edge[j][k].sc;
            if(dist[v]>dist[j] + w && dist[j]!=inf)
            {
                f++;
                dist[v] = dist[j] + w;
            }
        }
        if(!f) break;
    }
    int f = 0;
    for(int i = 0; i<n ; i++) flag[i] = 0;

    FOR(j, n)
    FOR(k, edge[j].size())
    {
        int v = edge[j][k].fs;
        int w = edge[j][k].sc;
        if(dist[v]>dist[j] + w && dist[j]!=inf)
        {
            if(flag[v]) continue;
            f=1;
            dfs(v);
            dist[v] = dist[j] + w;
        }
    }
    if(!f) return 0;
    return 1;
}

int main()
{
    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        int m;
        sf2(n, m);
        FOR(i, m)
        {
            int u, v, w;
            sf3(u, v, w);
            edge[v].pb(pii(u, w));
            edge2[v].pb(pii(u, w));
        }
        pcase(tst++);
        if(bell())
        {
            int x = vt.size();
            for(set<int>::iterator it = vt.begin() ; it!=vt.end() ; it++)
            {
                pf("%d",*it);
                x--;
                if(x!=0) pf(" ");
            }
            pf("\n");
            vt.clear();
        }
        else pf("impossible\n");
        FOR(i, n)
        {
            edge[i].clear();
            edge2[i].clear();
        }
    }
    return 0;
}

