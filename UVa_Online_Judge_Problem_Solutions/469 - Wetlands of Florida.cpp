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
//8 moves
int fx[]={1,1,1,0,0,-1,-1,-1};
int fy[]={1,0,-1,1,-1,1,0,-1};
int n, m;
char grid[500][107];
bool check[107][107];

int isvali(int x, int y){ return x>-1 && y>-1 && x<n && y<m; }
int counti = 0;
int dfs(int x, int y)
{
    for(int i=0;i<8;i++)
    {
        int a = x+fx[i];
        int b = y+fy[i];
        if( isvali(a, b) && !check[a][b] && grid[a][b]=='W')
        {
            check[a][b]=1;
            counti++;
            dfs(a, b);
        }
    }
    return counti;
}
int main()
{
    int t, flag=0;
    sf1(t);
    getchar();
    gets(grid[0]);
    while(t--)
    {
        if(flag) puts("");
        flag=1;
        int pos=0;
        while(gets(grid[pos]) && isalpha(grid[pos][0])) pos++;
        m = strlen(grid[0]);
        n = pos;
        int x, y;
        mem(check, 0);
        counti=1;
        sscanf(grid[pos++], "%d %d",&x, &y);
        check[x-1][y-1]=1;
        pf("%d\n", dfs(x-1, y-1));

        while(gets(grid[pos]) && strlen(grid[pos]))
        {
            counti=1;
            sscanf(grid[pos++], "%d %d",&x, &y);
            mem(check, 0);
            check[x-1][y-1]=1;
            pf("%d\n", dfs(x-1, y-1));
        }

    }

    return 0;
}
