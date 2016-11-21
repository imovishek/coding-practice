#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#define pb push_back
using namespace std;
vector<int>edg[105];
stack<int>st;
int flag[105];
int color[105];
int m,n,k;
void traverse(int col, int v)
{
    int siz=edg[v].size();
    for(int i=0;i<siz;i++)
    {
        if(flag[i]==0)
        {
            flag[v]=1;
            if(color==-1 )
        }
    }
}
int main()
{
    memset(color,-1,sizeof(color));
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d %d",&n,&k);
        int u,v;
        while(k--)
        {
            scanf("%d %d",&u,&v);
            edg[u].pb(v);
            edg[v].pb(u);
        }
    }
    return 0;
}
