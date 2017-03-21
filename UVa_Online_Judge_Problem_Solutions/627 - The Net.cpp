#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
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
vector <int> edge[325];
int dir[325];
int level[325];
void printpath(int u)
{
    if(u==-1) return;
    printpath(dir[u]);
    printf("%d ", u);
}
int bfs(int st, int en)
{
    queue<int>Q;
    Q.push(st);
    level[st] = 0;
    dir[st] = -1;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int i = 0 ; i < edge[u].size(); i++)
        {
            int v = edge[u][i];
            if(level[v]==-1)
            {
                dir[v] = u;
                level[v] = level[u] + 1;
                Q.push(v);
            }
            if(v == en) return level[v];
        }
    }
    return -1;
}
int main()
{
    #ifdef OVI
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    int u, v;
    while(sf1(n)!=EOF)
    {
        pf("-----\n");
        getchar();
        char line[1007];
        FOR(j, n)
        {
            gets(line);
            char *pt;
            pt = strtok(line, "-,");
            sscanf(pt,"%d", &u);
            pt = strtok(NULL, "-,");
            while(pt!=NULL)
            {
                sscanf(pt,"%d", &v);
                pt = strtok(NULL, "-,");
                edge[u].pb(v);
            }
        }
        int m;
        sf1(m);
        FOR(i, m)
        {
            sf2(u,v);
            mem(level, -1);
            int sig = bfs(u, v);
            if( sig == -1)
                pf("connection impossible\n");
            else
            {
                printpath(dir[v]);
                pf("%d",v);
                puts("");
            }


        }
        FOR(i, n+1) edge[i].clear();
    }
    return 0;
}
/*
6
1-2,3,4
2-1,3
3-1,2,5,6
4-1,5
5-3,4,6
6-3,5
6
1 6
1 5
2 4
2 5
3 6
2 1
10
1-2
2-
3-4
4-8
5-1
6-2
7-3,9
8-10
9-5,6,7
10-8
3
9 10
5 9
9 2
*/
