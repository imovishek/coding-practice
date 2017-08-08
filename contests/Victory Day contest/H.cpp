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


int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    int n;
    sf1(n);
    double ara[3][n];
    FOR(i, 3){
        FOR(j, n)
        {
            sf("%lf", &ara[i][j]);
        }
    }
    double dist1 = 0;
    FOR(i, n)
        dist1+=(ara[0][i] - ara[1][i]) * (ara[0][i] - ara[1][i]);
    dist1 = sqrt(dist1);
    double dist2 = 0;

    FOR(i, n)
    dist2+=(ara[0][i] - ara[2][i]) * (ara[0][i] - ara[2][i]);
    dist2 = sqrt(dist2);

    if(dist1<=dist2) pf("Yan\n");
    else pf("MaratonIME\n");
    return 0;
}














