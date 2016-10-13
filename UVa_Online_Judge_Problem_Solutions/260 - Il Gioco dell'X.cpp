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

int n;
int fx[]= {-1,0,1,-1,0,1};
int fy[]= {-1,-1,0,0,1,1};
queue < pii > Q;
int level[205][205];
char gird[205][205];
bool flag[205][205];
char isvali(int x, int y)
{
    if(x>-1 && x<n && y>-1 && y<n) return 1;
    return 0;
}
int bfs(pii u, char player)
{
    pii v;
    level[u.fs][u.sc]=0;
    Q.push(u);
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        for(int i=0; i<6; i++)
        {
            int x=u.fs+fx[i];
            int y=u.sc+fy[i];
            if(isvali(x, y) && flag[x][y]==0)
            {
                if(gird[x][y]==player)
                {
                    level[x][y]=level[u.fs][u.sc]+1;
                    flag[x][y]=1;
                    if(player=='b' && x==0)
                    {
                        while(!Q.empty()) Q.pop();
                        return level[x][y];
                    }
                    else if(player=='w' && y==n-1)
                    {
                        while(!Q.empty()) Q.pop();
                        return level[x][y];
                    }

                    Q.push(pii(x,y));
                }

            }
        }
    }
    return inf;
}
int main()
{
    int tst=1;
    while(sf1(n) && n)
    {
        FOR(i,n) sf("%s",gird[i]);
        int minW=inf, minB= inf;
        for(int i=0; i<n; i++)
        {
            mem(flag, 0);
            if(gird[i][0]=='w')
                minW = min(minW, bfs(pii(i,0), 'w'));
            mem(flag, 0);
            if(gird[n-1][i]=='b')
                minB = min(minB, bfs(pii(n-1,i),'b'));
        }
//        mem(flag, 0);
//        pf("*** %d\n", bfs(pii(1,0), 'w'));
//        pf("%d %d\n",minB, minW);
        pf("%d ",tst++);
        pf("%c\n","BW"[minB>minW]);
    }
    return 0;
}
