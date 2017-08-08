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
char ara[100];
int dp[51][6][6];
int n, siga, sigb;
int rec(int pos, int v, int c)
{
    if(v>=3 || c>=5) { sigb = 1; return 0;}
    if(pos==n){
        siga = 1;
        return 1;
    }
    int &ret = dp[pos][v][c];
    if(ret!=-1) return ret;
    ret = 0;
    if(ara[pos]==1) ret |= rec(pos+1, v+1, 0);
    else if(ara[pos]==0) ret |= rec(pos+1, 0, c+1);
    else{
        ret |= rec(pos+1, v+1, 0);
        if(siga&sigb) return 1;
        ret |= rec(pos+1, 0, c+1);
    }
    if(siga&sigb) return 1;
}
bool isvowel(char ch)
{
    return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ;
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
        sf("%s", ara);
        n = strlen(ara);
        FOR(i, n){
            if(ara[i]=='?') ara[i] = 2;
            else if(isvowel(ara[i])) ara[i] = 1;
            else ara[i] = 0;
        }
        siga = sigb = 0;
        mem(dp, -1);
        rec(0, 0, 0);
        pcase(tst++);
        if(siga & sigb) pf("MIXED\n");
        else if(siga) pf("GOOD\n");
        else pf("BAD\n");




    }
    return 0;
}














