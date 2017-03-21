#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a)
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
using namespace std;
typedef long long int lint;
typedef double dbl;
int n;
int ara[100007];
lint inf = 10000000000000;
int bigflag, pos = 1;
lint rec(int val)
{
    lint sum = 0;
    while(ara[pos]<0)
    {
        sum+=rec(ara[pos++]);
    }
    if(ara[pos++]==-val)
    {
        if(sum<ara[pos-1])
            return ara[pos-1];
        else return inf;
    }
    else return inf;
}
int main()
{
    int t, tst = 1;
    string line;
    while(getline(cin, line))
    {
        istringstream ss(line);
        n = 0;
        while(ss >> ara[n]) n++;
        if(n==0 || n==1) {
            pf(":-( Try again.\n");
            continue;
        }
        bigflag = 0;
        pos = 1;
        if(inf==rec(ara[0]))
            pf(":-( Try again.\n");
        else pf(":-) Matrioshka!\n");
    }
    return 0;
}














