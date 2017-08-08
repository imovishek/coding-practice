/*
OVISHEK PAUL, CSE - 15, SUST

*/

#include<bits/stdc++.h>
#define pii             pair<lint,lint>
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

pii ara[mx*10];

bool cmp(pii a, pii b)
{
    if(a.sc-a.fs<0 && b.sc-b.fs>0) return false;
    if(a.sc-a.fs>0 && b.sc-b.fs<0) return true;
    if(b.sc-b.fs<0 && a.sc-a.fs<0) return a.sc>b.sc;
    return a.fs<b.fs;
}

int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    lint n;
    sf1ll(n);
    lint l = 0, r = 100000000000000007, maxcap = 0;
    FOR(i, n){
        sf2ll(ara[i].fs, ara[i].sc);
    }
    sort(ara, ara+n, cmp);
//    FOR(i, pos) pf("%lld %lld*\n", ara[i].fs, ara[i].sc);

    lint ans = 0;
    while(l<=r){
        lint mid = (l + (r-l)/2);
        lint now = mid, f = 0, maxi = mid;
        FOR(i, n)
        {
            if(now<ara[i].fs){f = 1; break;}
            now += ara[i].sc - ara[i].fs;
//            if(mid==2) pf("%d**\n", now);
            maxi = max(maxi, now);
        }
        if(!f && maxi>=maxcap){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}



/*

10
1 6
25 98
10 45
12 40
40 6
2 1
1 2
5 9
10 98
10 10


4
2 40
2 4
40 1
4 2

5
1000000009 1
1000000009 2
1000000009 3
1000000009 4
1000000009 1

*/










