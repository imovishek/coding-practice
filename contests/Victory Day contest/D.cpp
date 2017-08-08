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
#define mx              100007

using namespace std;
typedef long long int lint;
typedef double dbl;

bool isvali(int x, int y)
{
    return x>-1 && y>-1 && x<8 && y<8;
}
int fx1[] = {0,0,1,-1,1,1,-1,-1};
int fy1[] = {1,-1,0,0,1,-1,1,-1};

int fx[] = {1,1,-1,-1,2,2,-2,-2};
int fy[] = {2,-2,2,-2,1,-1,1,-1};
int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    char grid[8][10], d, p;
    FOR(i, 8) sf("%s", grid[i]);
    sf(" %c%c", &d, &p);
    int y = d - 'a', x = 8 - (p - '0');
    int f = 0;
    FOR(i, 8)
    {
        int a = x, b = y;
        while(isvali(a+fx1[i], b+fy1[i]))
        {
            a = a+fx1[i], b = b+fy1[i];
            char ch = grid[a][b];
            if(grid[a][b]!='.'){
                if(i<4){
                    if(grid[a][b]=='t' || grid[a][b]=='r') f = 1;
                }
                if(i>=4){
                    if(ch=='b' || ch=='r') f = 1;
                }


                break;
            }
        }
    }
    FOR(i, 8) if(isvali(x+fx[i], y+fy[i]) && grid[x+fx[i]][y+fy[i]]=='c') f = 1;
    FOR(i, 8) if(isvali(x+fx1[i], y+fy1[i]) && grid[x+fx1[i]][y+fy1[i]]=='k') f = 1;
    if(isvali(x+1, y+1) && grid[x+1][y+1]=='p') f = 1;
    if(isvali(x+1, y-1) && grid[x+1][y-1]=='p') f = 1;

    if(f) pf("Sim\n");
    else pf("Nao\n");
    return 0;
}














