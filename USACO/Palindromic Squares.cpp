/*
ID: ovishek1
LANG: C++11
PROB: palsquare
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

void print(const vector<int> &ara)
{
    int n = ara.size();
    FOR(i, n)
    {
        if(ara[i]<=9) pf("%d", ara[i]);
        else pf("%c", 'A' + ara[i] - 10);
    }
}

vector<int> conv(int n, int b)
{
    vector<int> vt;
    while(n)
    {
        vt.pb(n%b);
        n/=b;
    }
    reverse(vt.begin(), vt.end());
    return vt;
}

int main()
{
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);
    int t, tst = 1;
    int B;
    sf1(B);
    FOR1(i, 300)
    {
        int sq = i * i;
        vector<int> vt = conv(sq, B);
        vector<int> rvt(vt.rbegin(), vt.rend());
        if(vt==rvt){
            vector<int> vi = conv(i, B);
            print(vi);
            pf(" ");
            print(vt);
            pf("\n");
        }
    }
    return 0;
}














