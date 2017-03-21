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
//night moves
int fx[]={2,2,-2,-2,1,-1,1,-1};
int fy[]={1,-1,1,-1,2,2,-2,-2};
int gird[8][8];
queue <pii> Q;
int bfs(pii st, pii en)
{
    Q.push(st);
    gird[st.fs][st.sc]=0;
    pii u,v;
    if(st==en)return 0;
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        for(int i=0;i<8;i++)
        {
            v.fs=u.fs+fx[i];
            v.sc=u.sc+fy[i];
            if(v.fs>-1 && v.sc>-1 && v.fs<8 && v.sc<8 && gird[v.fs][v.sc]==-1)
            {
                Q.push(v);
                gird[v.fs][v.sc]=gird[u.fs][u.sc]+1;
                if(v==en){while(!Q.empty())Q.pop(); return gird[v.fs][v.sc];}
            }
        }
    }

}
int main()
{
    string u,v;
    while(cin >> u >> v)
    {
//        cout << pii(u[0]-'a',u[1]-'0'-1).fs << pii(u[0]-'a',u[1]-'0'-1).sc ;
        for(int i=0;i<8;i++)for(int j=0;j<8;j++)gird[i][j]=-1;
        pf("To get from ");
        cout << u << " to " << v;
        pf(" takes %d knight moves.\n",bfs(pii(u[0]-'a',u[1]-'0'-1),pii(v[0]-'a',v[1]-'0'-1)));
    }
    return 0;
}
