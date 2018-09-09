#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
#include <time.h>

using namespace std;

#define SZ(x) ((int)x.size())
#define mem(name,val) memset(name,(val),sizeof(name));
#define ll long long
#define SF scanf
#define PF printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1<<28)
#define mp make_pair
#define fs first
#define sc second
#define Read freopen("in.txt","r",stdin)
#define Write freopen("out.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

///V^2*E Complexity
///number of augment path * (V+E)
///Base doesn't matter

const int INF = 200000000;
const int MAXN = 900;///total nodes
const int MAXM = 100000;///total edges

int N,edges;
int last[MAXN],preve[MAXM],head[MAXM];
int Cap[MAXM],Flow[MAXM];
int dist[MAXN];
int nextEdge[MAXN];///used for keeping track of next edge of ith node

queue<int> Q;

void init(int N)
{
    edges=0;
    memset(last,-1,sizeof(int)*N);
}

//cap=capacity of edges , flow = initial flow
inline void addEdge(int u,int v,int cap,int flow)
{
    head[edges]=v;
    preve[edges]=last[u];
    Cap[edges]=cap;
    Flow[edges]=flow;
    last[u]=edges++;

    head[edges]=u;
    preve[edges]=last[v];
    Cap[edges]=0;
    Flow[edges]=0;
    last[v]=edges++;
}

inline bool dinicBfs(int S,int E,int N)
{
    int from=S,to,cap,flow;
    memset(dist,0,sizeof(int)*N);
    dist[from]=1;
    while(!Q.empty()) Q.pop();
    Q.push(from);
    while(!Q.empty())
    {
        from=Q.front();Q.pop();
        for(int e=last[from];e>=0;e=preve[e])
        {
            to=head[e];
            cap=Cap[e];
            flow=Flow[e];
            if(!dist[to] && cap>flow)
            {
                dist[to]=dist[from]+1;
                Q.push(to);
                ///Important
                if(to==E) return true;
                ///Need to be sure
            }
        }
    }
    return (dist[E]!=0);
}

inline int dfs(int from,int minEdge,int E)
{
    if(!minEdge) return 0;
    if(from==E) return minEdge;
    int to,e,cap,flow,ret;
    for(;nextEdge[from]>=0;nextEdge[from]=preve[e])
    {
        e=nextEdge[from];
        to=head[e];
        cap=Cap[e];
        flow=Flow[e];
        if(dist[to]!=dist[from]+1) continue;
        ret=dfs(to,min(minEdge,cap-flow),E);
        if(ret)
        {
            Flow[e]+=ret;
            Flow[e^1]-=ret;
            return ret;
        }
    }
    return 0;
}

int dinicUpdate(int S,int E)
{
    int flow=0;
    while(int minEdge = dfs(S,INF,E))
    {
        if(minEdge==0) break;
        flow+=minEdge;
    }
    return flow;
}

int maxFlow(int S,int E,int N)
{
    int totFlow=0;
    while(dinicBfs(S,E,N))
    {
        for(int i=0;i<=N;i++) nextEdge[i]=last[i];
        totFlow+=dinicUpdate(S,E);
    }
    return totFlow;
}
double x[800],y[800];
int pen[800],jump[800];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int i,j,k,n,test,casio=1;
    scanf("%d",&test);
    while(test--){
    double l,m;
    scanf("%d%lf",&n,&m);
    edges=0;
    m=m*m;
    memset(last,-1,sizeof last);
    for(int i=1;i<=n;i++){
        scanf("%lf%lf%d%d",&x[i],&y[i],&pen[i],&jump[i]);
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        addEdge(0,i,pen[i],0);
       //   addEdge(i,0,pen[i],0);
        sum+=pen[i];
        addEdge(i,i+n,jump[i],0);
        for(int j=i+1;j<=n;j++){
            l=((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
            if(l<=m){
                addEdge(i+n,j,INF,0);
                addEdge(j+n,i,INF,0);

            }
        }
    }
    vector<int>vc;
    for(int i=1;i<=n;i++){
        memset(Flow,0,sizeof Flow);
        if(sum==maxFlow(0,i,n*2+1)){
            vc.push_back(i-1);
        }
    }
    printf("Case %d:",casio++);
   if(vc.size()==0){
    printf(" -1\n");
   }
   else{
    for(int i=0;i<vc.size();i++){
        printf(" %d",vc[i]);
    }
    printf("\n");
   }
}
}


