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
#define mp make_pair
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
using namespace std;
typedef long long int lint;
typedef double dbl;
vector < int > edge[207];
int color[207];
queue<int> Q;
bool bfs(int u)
{
    Q.push(u);
    int v;
    color[u]=1;
    while(!Q.empty()){
        u=Q.front();
        Q.pop();
        for(int i=0;i<edge[u].size();i++)
        {
            v=edge[u][i];
            if(color[v]==-1)
            {
                color[v]=(color[u]==1)? 2 : 1;
                Q.push(v);
            }
            else if((color[u]==color[v]))
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int n,e,u,v;
    while(sf1(n) && n)
    {
        for(int i=0;i<n;i++)color[i]=-1;
        sf1(e);
        while(e--)
        {
            sf2(u,v);
            edge[u].pb(v);
            edge[v].pb(u);
        }

        if(bfs(0))
        {
            pf("BICOLORABLE.\n");
        }
        else pf("NOT BICOLORABLE.\n");

        while(!Q.empty())Q.pop();
        for(int i=0;i<n;i++)
            edge[i].clear();
    }
    return 0;
}
