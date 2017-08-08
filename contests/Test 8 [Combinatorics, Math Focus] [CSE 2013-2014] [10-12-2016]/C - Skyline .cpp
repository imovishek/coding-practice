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

int dp[1007][1007];
int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    dp[2][2] = 1, dp[2][3] = 1;
    int ans[1009], ara[1007];
    int prev = 2;
    for(int i = 3; i<=1000; i++)
    {
        int sum = 0;
        for(int j = 1001; j>=0; j--) ara[j] = 0;
        for(int j = 1000; j>=0; j--) {
                ara[j] = (ara[j+1] + dp[i-1][j]) % 1000000;

        }
//        for(int j = 2; j<10; j++) if(i<10 && j<10)pf("%d ", ara[j]);
//        if(i<10 )pf("\n");

        for(int j=2; j<=i+1 ; j++){
            dp[i][j] = (ara[j-1]) % 1000000;
            sum = (sum+dp[i][j]) % 1000000;
//            if(i<10 && j<10) pf("%d ", dp[i][j]);
        }
//        if(i<10 ) pf("\n");
        ans[i] = sum;
    }
    int n;
    while(sf1(n) && n)
    {
        pf1(ans[n]%1000000);
    }
    return 0;
}














