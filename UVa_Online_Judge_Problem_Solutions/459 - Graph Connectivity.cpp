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
#define pi acos(-1.0)
#define FOR(i,x) for(int i=0; i<x ;i++)
#define inf 2147483647
#define mem(arr, x) memset(arr, x, sizeof(arr))
using namespace std;
typedef long long int lint;
typedef double dbl;
vector < int > edge[27];
int flag[27];
int dfs(int u)
{
    for(int i=0;i< edge[u].size(); i++)
    {
        int v=edge[u][i];
        if(flag[v]==0)
        {
            flag[v]=1;
            dfs(v);
        }
    }
}

int main()
{
    #ifdef OVI
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t, nl=0;
    char ara[10];
    sf1(t);
    gets(ara);
    gets(ara);
    while(t--)
    {
        if(nl) pf("\n");
        nl=1;
        char ch=getchar();
        getchar();
        while(gets(ara) && strlen(ara)){
            edge[ara[0]-'A'].pb(ara[1]-'A');
            edge[ara[1]-'A'].pb(ara[0]-'A');
        }
        int n= ch-'A'+1, counti=0;
        mem(flag, 0);
        FOR(i, n){
            if(!flag[i]){
                flag[i]=1;
                dfs(i);
                counti++;
            }
        }
        pf("%d\n",counti);
        FOR(i, n) edge[i].clear();

    }
    return 0;
}
