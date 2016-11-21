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
vector <int> edge[27];
queue<int> Q;
int level[27];
int bfs(int st,int en)
{
   memset(level,-1,sizeof(level));
   level[st]=0;
   Q.push(st);
   while(!Q.empty())
   {
       int u=Q.front();
       Q.pop();
       if(u==en){while(!Q.empty())Q.pop();return level[en];}
       for(int i=0;i<edge[u].size();i++)
       {
            int v=edge[u][i];
            if(level[v]==-1)
            {
                level[v]=level[u]+1;
                Q.push(v);
            }
       }
   }
}
int main()
{
    int tst=1,a;
    while(sf1(a)==1)
    {
        int u,v;
        while(a--)
        {
            sf1(u);
            edge[u].pb(1);
            edge[1].pb(u);
        }
        for(int i=2;i<20;i++)
        {
            sf1(a);
            while(a--)
            {
                sf1(u);
                edge[u].pb(i);
                edge[i].pb(u);
            }
        }
        sf1(a);
        pf("Test Set #%d\n",tst++);
        while(a--)
        {
            sf2(u,v);
            pf("%2d to %2d: %-d\n",u,v,bfs(u,v));
        }
        pf("\n");
        for(int i=1;i<21;i++)
            edge[i].clear();
    }
    return 0;
}
