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
int counti=0;
void gonext(int x, int y)
{
    for(int i=0;i<8;i++)
        if(ara[x+fx[i]][y+fy[i]]=='1')
        {
            ara[x+fx[i]][y+fy[i]]='0';
            counti++;
            gonext(x+fx[i], y+fy[i]);
        }
}
int main()
{
    int n, t, flag=0;
    sf1(t);
    while(t--){

        if(flag) puts("");
        flag=1;
        sf("%s",ara[0]);
        n=strlen(ara[0]);
        for(int i=1;i<n;i++)
            sf("%s",ara[i]);
        int maxi=0;
        FOR(i, n)
            FOR(j, n)
                if(ara[i][j]=='1'){
                    counti=1;
                    ara[i][j]='0';
                    gonext(i, j);
                    if(maxi<counti) maxi=counti;
                }
        pf("%d\n",maxi);

    }
    return 0;
}
