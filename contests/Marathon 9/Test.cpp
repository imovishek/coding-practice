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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, tst = 1;
    int n;
    sf1(n);
    int ara2[n];
    int ara[n];
    FOR(i, n) sf1(ara2[i]);
    sort(ara2, ara2+n);
    int cnt[n];
    int pos = 0, p2 = 0;
    cnt[0] = 1;
    ara[0] = ara2[0];
    FOR1(i, n-1)
    {
        if(ara2[i-1]==ara2[i]) cnt[pos]++;
        else{
            pos++;
            cnt[pos] = 1;
            ara[pos] = ara2[i];
        }
    }
    pos++;
//    FOR(i, pos) pf("%d %d**\n", ara[i], cnt[i]);
//    pf("*\n");
    int suma = 0, a = 0, sum = 0, b = 0;
    int mini = inf;
    for(int i = -1; i<pos; i++)
    {
//        pf("suma = %d\n", sum);
    	sum = 0;
        for(int j = pos; j>i; j--)
        {
//        	pf("sum = %d*\n", sum);
            if(ara[i+1]*2>=ara[j-1]) {
//                    pf("%d %d*\n", i, j);
                    mini = min(mini, sum+suma);
            }
            if(j>0)sum+=cnt[j-1];
        }
        if(i<pos-1)suma+=cnt[i+1];
    }



    pf("%d\n", mini);
    return 0;
}
