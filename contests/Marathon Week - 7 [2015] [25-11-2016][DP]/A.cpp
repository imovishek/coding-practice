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

char ara[10000007];
int mini = inf;
int n;
int rec(int pos, int sum)
{
    for(int i = pos; i<n ; i++){
        sum*=10;
        if(ara[i]=='A'){
            FOR(j, 10){
                int x = rec(i+1, (sum+j)%10);
                if(x==0 && mini==inf) {mini = j; break;}
            }
            break;
        }
        sum = (sum + ara[i] - '0') % 8;
    }
    return sum;
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
        mini = inf;
        int sum = 0;
        for(int i = n-3; i<n ; i++)
            sum = (sum*10 + ara[i] - '0') % 8;
        if(!sum){
            pf("YES\n");
            if(ara[0]=='A') pf1(1);
            else pf1(0);
        }
        else pf("NO\n");
    }
    return 0;
}














