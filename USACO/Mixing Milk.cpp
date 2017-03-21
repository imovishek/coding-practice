/*
ID: ovishek1
LANG: C++11
PROB: milk
*/


#include<bits/stdc++.h>
#define pii             pair<lint,lint>
#define mkp             make_pair
#define fs              first
#define sc              second
#define pb              push_back
#define ppb             pop_back()
#define all(vt)         vt.begin(), vt.end()
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
#define repr(vt, it)    for(typeof(vt.begin()) it = vt.begin(); it!=vt.end(); it++)
#define mx              100007

using namespace std;
typedef long long int lint;
typedef double dbl;
typedef vector<int> vi;


int main()
{
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);
    int t, tst = 1;
    int s, n;
    sf2(s, n);
    pii ara[n];
    FOR(i, n){
        sf2ll(ara[i].fs, ara[i].sc);
    }
    sort(ara, ara+n);
    lint cost = 0;
    FOR(i, n){
        if(s==0) break;
        if(s>=ara[i].sc){
            s -= ara[i].sc;
            cost += 0LL + ara[i].fs * ara[i].sc;
        }
        else{
            cost += 0LL + ara[i].fs * s;
            s = 0;
        }
    }
    cout << cost << endl;
    return 0;
}












