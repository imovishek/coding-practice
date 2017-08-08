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


lint ara[1007][1007];
int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    ara[0][0] = 1;
    lint ans[1007];
    for(lint i = 1; i<=1000; i++)
    {
        int sum = ara[i][1] = 1;
        for(lint j = 2; j<=1000 ; j++)
        {
            sum+= ara[i][j] = ((ara[i-1][j]*j)%1000000007 + ara[i-1][j-1]) % 1000000007;
//            if(i<=5 && j<=5) pf("%d ", ara[i][j]);
            sum%=1000000007;
        }
//        if(i<=5)pf("\n");
        ans[i] = sum;
    }
    sf1(t);
    while(t--)
    {
        int n;
        sf1(n);
        pf1(ans[n]);
    }
    return 0;
}














