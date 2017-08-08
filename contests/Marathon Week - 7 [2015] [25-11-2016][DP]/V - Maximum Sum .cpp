/*
OVISHEK PAUL, CSE - 15, SUST

*/

#include<cstdio>
#include<cstring>
#include<algorithm>
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


int ara[105][105];
int myturn[105], maxi = -inf;
int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    int n;
    sf1(n);
    mem(ara, 0);
    FOR1(i, n){
        FOR1(j, n) sf1(ara[i][j]);
    }

    for(int i = 1; i<=n ; i++)
    {
        FOR1(j, n) ara[i][j]+=ara[i-1][j];
    }

//    myturn[0] = 0;
    FOR1(i, n)
        for(int j = i; j<=n ; j++)
        {
            int f = 0, ans = -inf;
//            pf("%d %d**\n", i, j);
            FOR1(k, n) {

                myturn[k] = ara[j][k] - ara[i-1][k];
                if(myturn[k]>=0) {f = 1;}
                maxi = max(maxi, myturn[k]);
//                pf("%d ", myturn[k]);
            }
//            pf("\n");
            if(!f) continue;

            int sum = 0;
            for(int k = 1; k<=n; k++)
            {
                maxi = max(maxi, sum);
                if(sum+myturn[k]<0){
                    sum = 0;
                }
                else sum+=myturn[k];
            }
//            pf("%d\n", sum);
            maxi = max(maxi, sum);
        }
    pf1(maxi);
    return 0;
}


/*

2
1 2
-4 -3


*/











