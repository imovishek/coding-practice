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
//4 moves
int fx[]= {1,0,0,-1};
int fy[]= {0,1,-1,0};
int sig;
bool isvali(int x, int y)
{
    return (x>-1 && y>-1 && x<n && y<n);
}

char grid[105][107];
int dfs(int i, int j, int x, int y)
{
    if(grid[i][j]=='x') sig=1;
    grid[i][j]='.';
    int a = i + x;
    int b = j + y;
    if( isvali(a, b) && grid[a][b]!='.')
    {
        dfs(a, b, x, y);
    }
    return sig;
}
int main()
{
    int t, tst=1;
    sf1(t);
    while(t--)
    {
        sf1(n);
        FOR(i, n) sf("%s",grid[i]);
        int counti=0;
        FOR(i, n)
        FOR(j, n)
        {
            if(grid[i][j]!='.')
            {
                int k;
                for(k = 0; k<4; k++)
                {
                    if(isvali(i+fx[k], j+fy[k])&& grid[i+fx[k]][j+fy[k]]!='.')
                    {
                        sig = 0;
                        counti+=dfs(i, j, fx[k], fy[k]);
                        break;
                    }
                }
                if(k==4){
                    if(grid[i][j]=='x') counti++;
                }
            }

        }
        pcase(tst++);
        pf("%d\n",counti);
    }
    return 0;
}
/*
2
4
x...
.x..
.@.@
....
2
..
x.
*/
