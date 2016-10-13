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
#define pcase(x) printf("World #%d\n",x)
#define pi acos(-1.0)
#define FOR(i,x) for(int i=0; i<x ;i++)
#define inf 2147483647
#define mem(arr, x) memset(arr, x, sizeof(arr))
using namespace std;
typedef long long int lint;
typedef double dbl;
//4 moves
int fx[]= {1,0,0,-1};
int fy[]= {0,1,-1,0};
int n, m;
char grid[1007][1007];
int isvali(int x, int y)
{
    return x>-1 && y>-1 && x<n && y<m;
}

void dfs(int x, int y, char alpha)
{
    grid[x][y]='0';
    for(int i=0; i<4; i++)
    {
        int a = x+fx[i];
        int b = y+fy[i];
        if( isvali(a, b) && grid[a][b]==alpha)
        {
            dfs(a, b, alpha);
        }
    }
}
int main()
{
    int t, flag=0, tst=1;
    sf1(t);
    int counti[27];

    while(t--)
    {
        sf2(n , m);
        mem(counti, 0);
        FOR(i, n) sf("%s",grid[i]);
        FOR(i, n)
        FOR(j, m)
        {
            if(isalpha(grid[i][j]))
            {
                counti[grid[i][j]-'a']++;
                dfs(i, j, grid[i][j]);
            }
        }
        int maxi, pos;
        pcase(tst++);
        while(1)
        {
            maxi = 0;
            FOR(j, 26)
            {
                if(maxi < counti[j]) {pos=j; maxi=counti[j];}
            }
            if(maxi==0) break;
            pf("%c: %d\n", 'a' + pos, maxi);
            counti[pos] = 0;
        }
    }
    return 0;
}

