/*
ID: ovishek1
LANG: C++11
PROB: friday
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

    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);

    int mod[] = {3, 0, 3, 2 , 3, 2, 3, 3, 2, 3, 2, 3};
    int freq[7], n;
    mem(freq, 0);
    sf1(n);
    int x = 1;
    FOR(k, n)
    {
        int y = 1900 + k;
        int c = 0;
        FOR(i, 12) {
            freq[x]++;
            c = 0;
            if((y%400==0 || (y%4==0 && y%100!=0)) && i==1) c = 1;
            x = (mod[i] + x + c) % 7;
        }
    }

    FOR1(i, 6) pf("%d ", freq[i]);
    pf1(freq[0]);
    return 0;
}














