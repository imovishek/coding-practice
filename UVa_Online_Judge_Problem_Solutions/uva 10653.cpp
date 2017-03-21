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

//four moves
int fx[]={0,0,1,-1};
int fy[]={1,-1,0,0};
int gird[1007][1007];
int visited[1007][1007];
int n,m;
queue <pii> Q;
int bfs(pii st, pii en)
{
    pii u,v;
    Q.push(st);
    gird[st.fs][st.sc]=0;
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        for(int i=0;i<4;i++)
        {
            v.sc=u.sc+fy[i];
            v.fs=u.fs+fx[i];
            if(v.sc>-1 && v.sc<m && v.fs>-1 && v.fs<n && gird[v.fs][v.sc]!=-1 && visited[v.fs][v.sc]==0)
            {
                visited[v.fs][v.sc]=1;
                gird[v.fs][v.sc]=gird[u.fs][u.sc]+1;
                if(v==en){while(!Q.empty())Q.pop();return gird[v.fs][v.sc];}
                Q.push(v);
            }
        }
    }
}
int main()
{
    while(sf2(n,m) && !(!n && !m))
    {
        int row,r,a,c;
        sf1(row);
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)gird[i][j]=0;
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)visited[i][j]=0;
        while(row--)
        {
            sf2(r,a);
            while(a--)
            {
                sf1(c);
                gird[r][c]=-1;
            }
        }
        int stx,sty,enx,eny;
        sf2(stx,sty);
        sf2(enx,eny);
        printf("%d\n",bfs(pii(stx,sty),pii(enx,eny)));

    }
    return 0;
}
/*

10 10
9
0 1 2
1 1 2
2 2 2 9
3 2 1 7
5 3 3 6 9
6 4 0 1 2 7
7 3 0 3 8
8 2 7 9
9 3 2 3 4
0 0
9 9

10 10
9
0 1 2
1 1 2
2 2 2 9
3 2 1 7
5 2 6 9
6 4 0 1 2 7
7 3 0 3 8
8 2 7 9
9 3 2 3 4
0 0
3 8
0 0
*/
