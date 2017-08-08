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
#ifdef OVI
         freopen("input.txt", "r", stdin);
         freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1, n, m;
    while(sf2(n, m))
    {
        if(n==m && m==0) return 0;
        int ind[n+1], out[n+1];
        mem(ind, 0);
        mem(out, 0);
        FOR(i, m){
            int u, v, sig;
            sf3(u, v, sig);
            ind[v]++, out[u]++;
            if(sig==2) ind[u]++, out[v]++;
        }
        int ans = 1;
        FOR1(i, n) if(ind[i]==0 || out[i]==0) ans = 0;
        pf1(ans);
    }
    return 0;
}














