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
char ara[101][105];
void gonext(int x, int y)
{
    for(int i=0;i<8;i++)
        if(ara[x+fx[i]][y+fy[i]]=='@')
        {
            ara[x+fx[i]][y+fy[i]]='*';
            gonext(x+fx[i], y+fy[i]);
        }
}
int main()
{
    int n, m;
    while(sf2(n, m) && (n && m)){
        FOR(i, n)
            sf("%s",ara[i]);
        int counti=0;
        FOR(i, n)
            FOR(j, m)
            {
                if(ara[i][j]=='@'){
                        counti++;
                        gonext(i, j);
                }

            }
        pf("%d\n",counti);
    }
    return 0;
}
/*
1 1
*
3 5
*@*@*
**@**
*@*@*
1 8
*@****@@
5 5
@****
@*@@*
@**@*
@*@@@
@**@@
0 0
*/
