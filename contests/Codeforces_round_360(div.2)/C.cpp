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
vector<int> edge[100017];
int flag[100017], consider=0;
queue<int>Q;
bool bipartite(int u)
{
    Q.push(u);
    flag[u]=1;
    int v;
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        for(int i=0;i<edge[u].size();i++)
        {
            v=edge[u][i];
//            if(consider==v)continue;
            if(flag[v]==0)
            {
                flag[v]=(flag[u]==1)?2:1;
                Q.push(v);
            }
            else if(flag[v]==flag[u]){
//                if(consider==0){consider=v;flag[v]=3;continue;}
//                else if(consider==v)continue;
//                while(!Q.empty())Q.pop();
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int n,m;
    sf2(n,m);
    int u,v;
    for(int i=0;i<m;i++)
    {
        sf2(u,v);
        edge[u].pb(v);
        edge[v].pb(u);
    }
    int bigflag=1;
    for(int i=1;i<=n;i++)
    {
        if(flag[i]==0 && edge[i].size())
            bigflag&=bipartite(i);
    }
    int one=0,two=0;
    if(bigflag){
            for(int i=1;i<=n;i++){
                if(flag[i]==1){ one++;
                }
                else if(flag[i]==2) { two++;
                }
            }
//            if((one+two)<(n-1)){pf("-1\n");goto ret;}
            pf("%d\n",one);
            int flagi=0;
            for(int i=1;i<=n;i++){
                    if(flag[i]==1){
                            if(flagi)pf(" ");
                            flagi=1;
                            pf("%d",i);
                    }
            }
            pf("\n%d\n",two);
            flagi=0;
            for(int i=1;i<=n;i++){
                    if(flag[i]==2){
                            if(flagi)pf(" ");
                            flagi=1;
                            pf("%d",i);
                    }
            }
            pf("\n");

    }
    else pf("-1\n");
    ret:
    for(int i=1;i<=n;i++)edge[i].clear();
    return 0;
}
