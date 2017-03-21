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
vector<int>edge[1007];
int level[1007];
void bfs(int st){
    queue<int> Q;
    Q.push(st);
    level[st] = 0;
    while(!Q.empty())
    {
        int u, v;
        u = Q.front();
        Q.pop();
        FOR(i, edge[u].size())
        {
            v = edge[u][i];
            if(level[v]==-1)
            {
                level[v] = level[u] + 1;
                Q.push(v);
            }
        }
    }
}
int main()
{
    int t;
    sf1(t);
    int flag=0;
    while(t--)
    {
        if(flag) puts("");
        flag = 1;
        int n, e;
        sf2(n , e);
        int u, v;
        while(e--)
        {
            sf2(u, v);
            edge[u].pb(v);
            edge[v].pb(u);
        }
        FOR(i,n) level[i] = -1;
        bfs(0);

        for(int i = 1; i<n ;i++)
        {
            pf("%d\n",level[i]);
        }
        FOR(i, n) edge[i].clear();
    }
    return 0;
}


