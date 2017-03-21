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
#define pcase(x) printf("Case %d: ",x)
#define pi acos(-1.0)
#define FOR(i,x) for(int i=0; i<x ;i++)
#define inf 2147483647
#define mem(arr, x) memset(arr, x, sizeof(arr))
using namespace std;
typedef long long int lint;
typedef double dbl;

vector < int  > edge[107];
int flag[107];
int bfs(int u)
{
    queue <int> Q;
    Q.push(u);
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        for(int i=0;i<edge[u].size();i++)
        {
            int v = edge[u][i];
            if(!flag[v])
            {
                flag[v] = 1;
                Q.push(v);
            }
        }
    }
}
int main()
{
    int n,u,v;
    while(sf1(n) && n)
    {
        while(sf1(u) && u)
        {
            while(sf1(v) && v)
                edge[u].pb(v);
        }
        int stpoint, st;
        sf1(stpoint);
        FOR(i, stpoint)
        {
            mem(flag, 0);
            sf1(st);
            bfs(st);
            vector <int > vt;
            for(int i=1; i<=n; i++) if(flag[i]==0) vt.pb(i);
            pf("%d", vt.size());
            for(int i = 0; i < vt.size() ; i++)
                pf(" %d",vt[i]);
            puts("");
        }
        for(int i=1; i<=n; i++) edge[i].clear();
    }
    return 0;
}
