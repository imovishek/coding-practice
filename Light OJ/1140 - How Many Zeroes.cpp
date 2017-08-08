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

lint dp[12][2][2][12];
int n;
vector<int> vt;
lint rec(char ara[], int pos, bool is_start, bool is_equal, int zeros)
{
    if(pos==n) {
            for(int x: vt) pf("%d", x);
            pf(" khali newline\n");
            return zeros;
    }
    lint &ret = dp[pos][is_start][is_equal][zeros];
    if(ret!=-1) {
            for(int x: vt) pf("%d", x);
            pf(" mil paiya gesi ans %lld\n", ret);
            return ret;
    }
    int l = 9;
    if(is_equal) l = ara[pos] - '0';
    ret = 0;
    if(!is_start && pos==n-1) ret = 1;
    if(l==0)
    {
        vt.pb(0);
        ret+= rec(ara, pos+1, is_start, 1, zeros+1);
        vt.ppb;
        return ret;
    }
    else {
        if(is_start) zeros++;
        vt.pb(0);
        ret += rec(ara, pos+1, is_start, 0, zeros);
        vt.ppb;
    }

    for(int i = 1; i<l ; i++){

        vt.pb(i);
        ret += rec(ara, pos+1, 1, 0, zeros);
        vt.ppb;
    }

    vt.pb(l);
    ret += rec(ara, pos+1, 1, is_equal, zeros);
    vt.ppb;
    return ret;
}

int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        int x, y;
        char a[13], b[14];
        sf("%d %d", &x, &y);
        x--;
        sprintf(a, "%d", x);
        sprintf(b, "%d", y);
        puts(a);
        puts(b);
        mem(dp, -1);
        n = strlen(b);
        lint p = rec(b, 0, 0, 1, 0);
        cout << p << "h\n" << endl;
        mem(dp, -1);
        n = strlen(b);
        lint q = rec(b, 0, 0, 1, 0);
        cout << q << "h\n" << endl;
        pcase(tst++);
        pf("%lld\n", q-p);
    }
    return 0;
}














