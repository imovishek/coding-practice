#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#define pii pair<int,int>
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a);
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 2147483647
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
using namespace std;
typedef long long int lint;
typedef double dbl;
#define mx 65600
bool flag[mx+7];
vector<int> primes;
void seive()
{
    mem(flag, 0);
    for(int i = 4; i<mx; i+=2) flag[i] = 1;
    int sq = sqrt(mx);
    primes.pb(2);
    for(int i = 3; i <mx; i+=2)
    {
        if(!flag[i])
        {
            primes.pb(i);
            if(i>sq) continue;
            int i2 = i<<1;
            for(int j = i*i; j<=mx; j+=i2)
            {
                flag[j] = 1;
            }
        }
    }
}
int main()
{
    seive();
    int n;
    int counti[primes.size()+5];
    while(sf1(n) != EOF && n>=2)
    {
        mem(counti, 0);
        pf("%d = ",n);
        for(int i = 0; primes[i]*primes[i]<=n ; i++)
        {
            while(n%primes[i]==0)
            {
                n/=primes[i];
                counti[i]++;
            }
        }
        int fsp = 0;
        for(int i=0; i<primes.size() ; i++)
        {
            if(counti[i]!=0)
            {
                if(fsp) pf(" * ");
                fsp = 1;
                pf("%d^%d", primes[i], counti[i]);
            }
        }
        if(n>1) {
             if(fsp) pf(" * ");
             pf("%d^1", n);
        }
        pf("\n");

    }
    return 0;
}

