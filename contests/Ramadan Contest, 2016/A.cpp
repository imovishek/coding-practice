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
int counti=0;
int flag[1000];
vector <int> edge[1007];
int dfs(int u)
{
    if(flag[u]==1)return 0;
    flag[u]=1;
    int maxi=0;
    for(int i=0;i<edge[u].size();i++)
    {
        maxi=max(maxi,1+dfs(edge[u][i]));
    }
    flag[u]=0;
    return maxi;
}
int main()
{
    map<string,int>mp;

    int t,tst=1,n;
    string u,v;
    sf("%d",&t);
    while(t--)
    {
        cin >> n;
        int i=1;
        while(n--)
        {
            cin>>u>>v;
            if(mp.find(u)==mp.end()){
                mp[u]=i++;
            }
            if(mp.find(v)==mp.end()){
                mp[v]=i++;
            }
            edge[mp[u]].pb(mp[v]);
            edge[mp[v]].pb(mp[u]);

        }
        cin >> u;
        pcase(tst++);
        printf("%d\n",dfs(mp[u]));
        mp.clear();
        for(int i=0;i<1007;i++)edge[i].clear();

    }
    return 0;
}
