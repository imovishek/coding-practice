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
#define pf printf
#define sf scanf
#define pcase(x) printf("Case %d: ",x)
using namespace std;
typedef long long int lint;
typedef double dbl;
vector<int>edge[2007];
int dp[2007][2],n,b,c,flag[2007];
int cow=0,bull=0;
int rec(int node)
{
//    int siz=edge[node].size();

//    if(dp[node][cb]!=-1)
//            return db[node][cb];
    if(flag[node]==1){
        for(int i=0;i<siz;i++)
        {
            if(flag[edge[node][i]]==1)
            {
                bigflag=-1;
                return;
            }
            flag[edge[node][i]]=-1;
        }
    }
    else if(flag[node]==-1){
        for(int i=0;i<siz;i++)
        {
            if(flag[edge[node][i]]==-1)
            {
                bigflag=-1;
                return;
            }
            flag[edge[node][i]]=1;
        }
    }
    return 0;

}
int main()
{
    int t;
    sf("%d",&t);
    while(t--)
    {
        int u,v;
        scanf("%d %d %d",&a,&b,&n);
        for(int i=0;i<n;i++){
            scanf("%d %d",&u,&v);
            vt[u].push_back(v);
            vt[v].push_back(u);
        }

    }
    return 0;
}
