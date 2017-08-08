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
#define checki(x, i)    (x & (1<<i))
#define reseti(x, i)    x&=~(1<<i)
#define seti(x, i)    x|=(1<<i)

using namespace std;
typedef long long int lint;
typedef double dbl;


int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    int x, y;
    sf2(x, y);
    int a, b;
    while(1)
    {
        if(x==0 && y==0) return 0;
        int now = x^y, tx = x, ty = y;
        int ans = 0, am = 0, f = 0;
        for(int i = 31; i>=0; i--)
        {
            if(checki(now, i)) {
                if(checki(x, i)){
                    ans = 1;
                    int temp = x;
                    reseti(x, i);
                    for(int j = i-1; j>=0 ; j--)
                        if(checki(now, j)) {
                                if(checki(x, j))reseti(x, j);
                                else seti(x, j);
                        }
                    am = temp - x;

                }
                else{
                    ans = 2;
                    int temp = y;
                    reseti(y, i);
                    for(int j = i-1; j>=0 ; j--)
                        if(checki(now, j)) {
                            if(checki(y, j))reseti(y, j);
                            else seti(y, j);
                        }
                    am = temp - y;
                }
                break;
            }
        }
        cout << ans << ' ' << am << endl;
        cout.flush();
        if(x==0 && y==0) return 0;
        sf2(a, b);
        if(a==1) x-=b;
        else y-=b;

    }
    return 0;
}














