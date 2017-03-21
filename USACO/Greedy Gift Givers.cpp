/*
ID: ovishek1
LANG: C++11
PROB: gift1
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

     freopen("gift1.in", "r", stdin);
     freopen("gift1.out", "w", stdout);


    int t, tst = 1;
    map<string, int> mp;
    int n;
    sf1(n);
    int ara[n];
    mem(ara, 0);
    string st, names[n];
    FOR(i, n) {
        cin >> st;
        mp[st] = i;
        names[i] = st;
    }
    int tmp = n;
    while(tmp-- && cin >> st)
    {
        int u, v, pos = mp[st];
        sf2(u, v);
        if(!v) continue;
        ara[pos] -= u;
        int given = (u/v) * v;
        ara[pos] += u - given;
        FOR(i , v)
        {
            cin >> st;
            pos = mp[st];
            ara[pos]+= given/v;
        }
    }

    FOR(i, n)
    {
        pf("%s %d\n", names[i].c_str(), ara[i]);
    }
    return 0;
}














