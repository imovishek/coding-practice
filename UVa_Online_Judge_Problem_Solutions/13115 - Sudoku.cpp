#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<climits>
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
#define pf1(a) printf("%d\n",a);
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 2147483647
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
//#define seti(p,x) p|=(1<<x)
//#define check(p,x) (p & (1<<x))
//#define reseti(p,x) p&=(~(1<<x))

////8 moves
//int fx[]={1,1,1,0,0,-1,-1,-1};
//int fy[]={1,0,-1,1,-1,1,0,-1};
//
////4 moves
//int fx[]= {1,0,0,-1};
//int fy[]= {0,1,-1,0};
//
////night moves
//int fx[]={2,2,-2,-2,1,-1,1,-1};
//int fy[]={1,-1,1,-1,2,2,-2,-2};

using namespace std;
typedef long long int lint;
typedef double dbl;
int n, k;
int ara[25][25];
bool check(int x, int y, int val)
{
    FOR(i, n){
        if(i!=x && ara[i][y]==val) return 0;
    }
    FOR(i, n){
        if(i!=y && ara[x][i]==val) return 0;
    }
    int p = (x/k)*k, q = (y/k)*k;
    for(int i=0 ; i<k ; i++)
    {
        for(int j = 0; j<k; j++)
            if(ara[p+i][q+j]==val && (p+i!=x || q+j!=y))return 0;
    }
    return 1;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        sf1(n);
        k = sqrt(n);
        FOR(i, n)
            FOR(j, n)
                sf1(ara[i][j]);
        int flag = 1;
        FOR(i, n)
            FOR(j, n)
                if(!check(i, j, ara[i][j])){
                    flag = 0;
                    break;
                }
        if(flag) pf("yes\n");
        else pf("no\n");
    }
    return 0;
}

