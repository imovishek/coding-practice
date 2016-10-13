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
#define pcase(x) printf("Case %d:",x)
#define pi acos(-1.0)
#define FOR(i,x) for(int i=0; i<x ;i++)
#define inf 2147483647
#define mem(arr, x) memset(arr, x, sizeof(arr))
using namespace std;
typedef long long int lint;
typedef double dbl;
int grid[15][15];
int flag[15][15];
int n;
int isvali(int x, int y, int r)
{
    if(x>-1 && y>-1 && x<n && y<n){
        if(flag[x][y])
            return 0;
        return x==r || y==r || x == n-1-r || y==n-1-r;
    }
    return 0;
}
////4 moves
int fx[]= {1,0,0,-1};
int fy[]= {0,1,-1,0};
int sum = 0;
void dfs(int x, int y, int r)
{
    if(isvali(x, y, r)) {
            sum += grid[x][y];
            flag[x][y] = 1;
    }
    else return;
    FOR(i, 4)
        dfs(x + fx[i] , y + fy[i], r);
}
int main()
{
    int tst = 1;
    while(sf1(n) && n)
    {
        FOR(i, n)
            FOR(j, n)
            {
                sf1(grid[i][j]);
            }
        int flagi = 0;
        pcase(tst++);
        mem(flag, 0);
        FOR(i, n/2+1)
        {
            sum = 0;
            if(flag[i][i]==0) flagi = 1;
            dfs(i, i, i);
            if(flagi) pf(" %d", sum);
            flagi = 0;
        }
        puts("");
    }
    return 0;
}
