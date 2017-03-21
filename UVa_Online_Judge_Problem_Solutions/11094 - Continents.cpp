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
char grid[25][25];
//4 moves
int fx[]= {1,0,0,-1};
int fy[]= {0,1,-1,0};
int n, m;
int isvali(int x, int y){ return x>-1 && y>-1 && x<n && y<m; }
int maxi = 0;
char ch;
void dfs(int x, int y)
{
    if(grid[x][y]!=ch) return;
    maxi ++;
    grid[x][y]='*';
    FOR(i, 4){
        int a = x + fx[i];
        int b = (y + fy[i] + m) % m;
        if(isvali(a,b)){
            dfs(a,b);
        }
    }
}

int main()
{
    while(sf2(n, m)!=EOF){
        FOR(i, n) sf("%s",grid[i]);
        int x,y;
        sf2(x, y);
        int maxall=0;
        ch = grid[x][y];
        dfs(x, y);
        FOR(i, n)
        {
            FOR(j, m)
            {
                maxi = 0;
                if(grid[i][j]==ch){ dfs(i, j); }
                if(maxi > maxall) maxall = maxi;
            }
        }
        pf("%d\n",maxall);
    }
    return 0;
}
/*

5 5
wwlww
wlllw
wwlww
wwwll
lllwl
1 3
*/
