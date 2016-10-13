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
#define inf 2147483647
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)

using namespace std;
typedef long long int lint;
typedef double dbl;
int n, m;
vector<pii> edge[1007];
int dist[1007];
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        sf2(n, m);
        FOR(i, m)
        {
            int u, v, t;
            sf3(u, v, t);
            edge[u].pb(pii(v,t));
        }
        FOR(i, n) dist[i] = 10000007;
        dist[0] = 0;
        FOR(i, n)
        {
            int f = 0;
            FOR(j, n)
            {
                FOR(k, edge[j].size())
                {
                    int v = edge[j][k].fs;
                    int w = edge[j][k].sc;
                    if(dist[v]>dist[j]+w)
                    {
                        dist[v] = dist[j]+w;
                        f++;
                    }
                }
            }
        }
        int f = 0;
        FOR(j, n)
        {
            FOR(k, edge[j].size())
            {
                int v = edge[j][k].fs;
                int w = edge[j][k].sc;
                if(dist[v]>dist[j]+w)
                {
                    dist[v] = dist[j]+w;
                    f++;
                    break;
                }
            }
        }
        FOR(i, n) edge[i].clear();
        if(f) pf("possible\n");
        else pf("not possible\n");
    }
    return 0;
}








