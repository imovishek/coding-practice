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
map<int,vector<int> > edge;
map<int , int>level;
queue<int>Q;
int bfs(int u, int node, int l)
{
    int v,counti=node;
    Q.push(u);
    level[u]=0;
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        for(int i=0;i<edge[u].size();i++)
        {
            v=edge[u][i];
            if(level.find(v)==level.end())
            {
                level[v]=level[u]+1;
                Q.push(v);
                if(level[v]<=l)
                    counti--;
            }
        }
    }
    return --counti;
}
int main()
{
    int n,tst=1,u,v,st,l;
    while(sf1(n) && n)
    {
        int node=0;
        for(int i=0;i<n;i++)
        {
            sf2(u,v);
            if(edge.find(v)==edge.end())node++;
            edge[v].pb(u);
            if(edge.find(u)==edge.end())node++;
            edge[u].pb(v);
        }
        while(1)
        {
            sf2(st,l);
            if(st==0 && l==0)break;
//            memset(level,-1,sizeof(level));
            level.clear();
            pcase(tst++);
            if(edge.find(st)==edge.end()) pf("%d nodes not reachable from node %d with TTL = %d.\n",node,st,l);

            else pf("%d nodes not reachable from node %d with TTL = %d.\n",bfs(st,node,l),st,l);

        }
        edge.clear();
    }
    return 0;
}
