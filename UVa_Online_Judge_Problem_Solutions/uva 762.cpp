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
using namespace std;
typedef long long int lint;
typedef double dbl;
queue<int>Q;
map<string,int>mp;
vector<int>edge[20007];
int level[20007];
int parent[20007];
string ara[20007];
void printparent(int st, int en)
{
    if(st==en) return;
    printparent(st,parent[en]);
    cout << ara[parent[en]] << ' ' << ara[en] << endl;
}
int bfs(int st, int en)
{
    Q.push(st);
    level[st]=0;
    int u,v;
    while(!Q.empty()){
        u=Q.front();
        Q.pop();
        for(int i=0;i<edge[u].size();i++)
        {
            v=edge[u][i];
            if(level[v]==-1)
            {
                Q.push(v);
                level[v]=level[u]+1;
                parent[v]=u;
                if(v==en){while(!Q.empty())Q.pop(); return 1;}
            }
        }
    }
    return -1;
}
int main()
{
    string u,v;
    int n,flag=0;

    while(sf("%d",&n)!=EOF)
    {
        if(flag){pf("\n");}
        flag=1;
        int pos=0;
        for(int i=0;i<n;i++)
        {
            cin >> u >> v;
            if(mp.find(u)==mp.end()){
                    mp[u]=pos;
                    ara[pos++]=u;
            }
            if(mp.find(v)==mp.end()){
                    mp[v]=pos;
                    ara[pos++]=v;
            }
            edge[mp[u]].pb(mp[v]);
            edge[mp[v]].pb(mp[u]);
        }
        cin >> u >> v;
        int ans=0;
        if(mp.find(u)==mp.end()) ans=-1;
        if(mp.find(v)==mp.end()) ans=-1;
        if(ans!=-1)
        {
            for(int i=0;i<pos;i++)level[i]=-1;
            ans=bfs(mp[u],mp[v]);
        }
        if(ans==-1)
        {
            pf("No route\n");
        }
        else {
                printparent(mp[u],mp[v]);
        }
        mp.clear();
        for(int i=0;i<pos;i++)edge[i].clear();
    }



    return 0;
}
