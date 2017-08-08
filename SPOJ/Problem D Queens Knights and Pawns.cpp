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

int ara[1007][1007];
int n, m;
int fx1[] = {-1,-1,-1,0,0,1,1,1};
int fy1[] = {-1,0,1,-1,1,-1,0,1};

int fx2[] = {-1,-1,1,1,-2,-2,2,2};
int fy2[] = {2,-2,2,-2,1,-1,1,-1};

bool isvali(int x, int y)
{
    return x>0 && y>0 && x<=n && y<=m;
}

pii ques[mx];

int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    while(sf2(n, m))
    {
        if(n==0 && m==0) return 0;
        int k, que;
        sf1(k);
        que = k;
        FOR(j, k)
        {
            int x, y;
            sf2(x, y);
            ques[j] = pii(x, y);
        }

        sf1(k);
        FOR(i, k){
            int x, y;
            sf2(x, y);
            ara[x][y] = 2;
            FOR(j, 8){
                if(isvali(x+fx2[j], y+fy2[j])){
                    if(!(ara[x+fx2[j]][y+fy2[j]]))ara[x+fx2[j]][y+fy2[j]] = 1;
                }
            }
        }

        sf1(k);
        FOR(i, k)
        {
            int x, y;
            sf2(x, y);
            ara[x][y] = 2;
        }

        FOR(i, que){
            int x = ques[i].fs;
            int y = ques[i].sc;
            FOR(i, 8){
                int tx = x, ty = y;
                while(isvali(tx, ty) && ara[tx][ty]!=2){
                    ara[tx][ty] = 1;
                    tx += fx1[i];
                    ty += fy1[i];
                }
            }
        }

        int ans = 0;
        FOR1(i, n)
            FOR1(j, m)
            {
                ans += !ara[i][j];
                ara[i][j] = 0;
            }
        pf("Board %d has %d safe squares.\n", tst++, ans);
    }
    return 0;
}














