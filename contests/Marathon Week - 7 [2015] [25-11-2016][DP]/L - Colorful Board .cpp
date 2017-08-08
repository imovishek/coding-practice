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
#define pf1(a)          printf("%lld\n",a)
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
lint dp[21][21][51];
int n, m, k;

//lint rec(int pos, int odd, int even)
//{
//    if(odd+even>k) return 0;
//    if(pos==n*m) {
//            return 1;
//    }
//    lint &ret = dp[pos][odd][even];
//    if(ret!=-1) return ret;
//
//    ret = 0;
//    int sig = (pos/m + (pos%m)) & 1;
//    if(!sig) {
//            ret = (ret + rec(pos+1, odd, even+1)) % MOD;
//            ret = (ret + even * rec(pos+1, odd, even)) % MOD;
//    }
//
//    else {
//            ret = (ret + rec(pos+1, odd+1, even)) % MOD;
//            ret = (ret + odd * rec(pos+1, odd, even)) % MOD;
//    }
//    return ret;
//
//}

int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    mem(dp, 0);
    dp[1][1][1] = 1;
    lint two[450] = {1};
    for(int i=1; i<=420; i++) two[i] = (two[i-1] * 2) % MOD;
    for(int i = 1; i<=20; i++)
        for(int j = 1; j<=20; j++) dp[i][j][2] = 2;
    for(int i = 1; i<=20; i++)
        for(int j = 1; j<=20; j++)
            for(int k = 3; k<=50; k++){
                if(i==j && j==1) {dp[i][j][k] = k; continue;}
                lint val = (i/2)*(j/2) + (i - i/2) * (j - j/2);
                dp[i][j][k] = (dp[i][j][k-1] * ((two[val] + two[i*j - val] - 1 + MOD) % MOD)) % MOD;
                pf("%d %d %lld**\n", i, j, val);
            }
    sf1(t);

    while(t--){
//        mem(dp, -1);
        sf3(n, m, k);
        n++;
        m++;
        pcase(tst++);
        pf1(dp[n][m][k]);
    }
    return 0;
}














