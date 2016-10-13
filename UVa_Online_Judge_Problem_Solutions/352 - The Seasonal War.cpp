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
int n;
char isvali(int x, int y)
{
    if(x<n && x>-1 && y<n && y>-1) return 1;
    return 0;
}
char gird[30][30];
int dfs(int x, int y)
{
    for(int i=0;i<8;i++)
    {
        int a=x + fx[i], b = y+fy[i];
        if( isvali(a, b) && gird[a][b]=='1')
        {
            gird[a][b]='0';
            dfs(a,b);
        }
    }
}
int main()
{
    int tst=1;
    while( sf1(n)!= EOF )
    {
        FOR(i, n) sf("%s",gird[i]);
        int counti=0;
        FOR(i, n)
            FOR(j, n)
            {
                if(gird[i][j]=='1')
                {
                    gird[i][j]='0';
                    dfs(i,j);
                    counti++;
                }
            }
        pf("Image number %d contains %d war eagles.\n",tst++,counti);
    }
    return 0;
}
