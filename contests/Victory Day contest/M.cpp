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


char grid[1007][1007];
int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    int n, m;
    sf2(n, m);
    int f = 0, ans = 0, sum = 0;
    FOR(i, n)
    {
        sf("%s", grid[i]);
        if(i&1){
            for(int k = m-1; k>=0; k--)
                if(grid[i][k]=='.') sum++;
                else if(grid[i][k]=='L') {
                    ans = max(ans, sum);
                    sum = 0;
                }
        }
        else{
            for(int k = 0; k<m; k++)
                if(grid[i][k]=='.') sum++;
                else if(grid[i][k]=='L') {
                    ans = max(ans, sum);
                    sum = 0;
                }
        }
    }
    ans = max(ans, sum);
    pf1(ans);
    return 0;
}














