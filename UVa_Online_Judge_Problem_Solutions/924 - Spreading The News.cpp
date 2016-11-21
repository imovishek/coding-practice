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
vector<int>edge[2507];
int level[2507];
pii bfs(int st){
    int maxi = 0;
    queue<int> Q;
    Q.push(st);
    level[st] = 0;
    int flag = 0, counti = -1, depth;
    while(!Q.empty())
    {
        int u, v;
        u = Q.front();
        Q.pop();
        if(level[u]==flag) counti++;
        else{
            if(maxi<counti) {
                maxi = counti;
                depth = flag;
            }
            flag = level[u];
            counti = 1;
        }
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

    if(maxi<counti) {
        maxi = counti;
        depth = flag;
    }
    return pii(maxi, depth);
}
int main()
{
    int n;
    sf1(n);
    FOR(i, n)
    {
        int e;
        sf1(e);
        int v;
        while(e--)
        {
            sf1(v);
            edge[i].pb(v);
        }
    }
    int t, st;
    sf1(t);
    while(t--)
    {
        sf1(st);
        FOR(i,n) level[i] = -1;
        pii p = bfs(st);
        if(p.fs==0)
            pf("0\n");
        else pf("%d %d\n",p.fs,p.sc);
    }

    return 0;
}

