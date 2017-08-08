/*
OVISHEK PAUL, CSE - 15, SUST

*/

#include<bits/stdc++.h>
#define pii             pair<int,int>
#define mkp             make_pair
#define fs              first
#define sc              second
#define pb              push_back
#define ppb             pop_back()
#define pf              printf
#define pf1(a)          printf("%d\n",a)
#define hi              printf("hi!\n");
#define sf              scanf
#define sf1(a)          scanf("%d",&a)
#define sf2(a,b)        scanf("%d %d",&a,&b)
#define sf3(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define sf1ll(a)        scanf("%lld",&a)
#define sf2ll(a,b)      scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c)    scanf("%lld %lld %lld",&a,&b,&c)
#define pcase(x)        printf("Case %d: ",x)
#define MOD             1000000007
#define inf             1000000007
#define pi              acos(-1.0)
#define mem(arr,x)      memset((arr), (x), sizeof((arr)));
#define FOR(i,x)        for(int i=0;i<(x); i++)
#define FOR1(i,x)       for(int i=1;i<=(x); i++)
#define mx              207

using namespace std;
typedef long long int lint;
typedef double dbl;

bool ara[mx][mx];

pii check()
{

    int mini = inf;
    FOR(i, mx)
        FOR(j, mx)
            if(ara[i][j]==0) return pii(i, j);
    return pii(-1, 0);
}
int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    int px = 0, py = 0;
    int pos = 0;
    while(1)
    {
        pii a = check();
        if(a.fs==-1) return 0;
        int x = a.fs, y = a.sc;
        if(x-px==1 && y-py==2) pf("%d ", pos);
//        else if(x-px==2 && y-py==3) pf("b");
        pos++;
        px = x, py = y;
        for(int i = x; i<mx ; i++)
            ara[i][y] = 1;
        for(int i = y; i<mx ; i++)
            ara[x][i] = 1;
        while(1){
            x+=1, y+=1;
            if(x>=mx || y>=mx) break;
            ara[x][y] = 1;
        }

        x = a.sc, y = a.fs;
        for(int i = x; i<mx ; i++)
            ara[i][y] = 1;
        for(int i = y; i<mx ; i++)
            ara[x][i] = 1;
        while(1){
            x+=1, y+=1;
            if(x>=mx || y>=mx) break;
            ara[x][y] = 1;
        }

    }
    return 0;
}














