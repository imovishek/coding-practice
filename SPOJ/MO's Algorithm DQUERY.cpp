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

int sq;
struct data{
    int l, r, idx;
} q[2*mx];
int answer[mx*2];
bool cmp(data a, data b)
{
    if(a.l/sq!=b.l/sq) return a.l/sq<b.l/sq;
    return a.r < b.r;
}
int ara[mx];
int flag[mx*10];
void MOS(int n, int m){
    sq = sqrt(n);
    sort(q, q+m, cmp);
    int l = 0, r = 0;
    int ans = 0;
//    for(int i = q[0].l; i<=q[0].r ; i++){
//        flag[ ara[i] ]++;
//        if(flag[ara[i]]==1) ans ++;
//    }
//    answer[ q[0].idx ] = ans;
    FOR(i, m)
    {
//        pf("%d %d**\n", q[i].l, q[i].r);
//        pf("%d %d &&*\n", l, r);
        while(l<q[i].l){
            flag[ara[l]]--;
            if(flag[ara[l]]==0) ans--;
//            pf("%d removed l\n", l);
            l++;
        }

        while(l-1>=q[i].l){
            flag[ara[l-1]]++;
            if(flag[ara[l-1]]==1) ans++;
//            pf("%d added l\n", l-1);
            l--;
        }

        while(r>=q[i].r+1){
            flag[ara[r]]--;
            if(flag[ara[r]]==0) ans--;
//            pf("%d removed r\n", r);
            r--;
        }
        while(r+1<=q[i].r){
            flag[ara[r+1]]++;
            if(flag[ara[r+1]]==1) ans++;
//            pf("%d added r\n", r+1);
            r++;
        }
        answer[ q[i].idx ] = ans;
//        pf("ans = %d\n", ans);
    }
}

int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    int n, m;
    sf1(n);
    FOR1(i, n) sf1(ara[i]);
    sf1(m);
    FOR(i, m) {
        sf2(q[i].l, q[i].r);
        q[i].idx = i;
    }
    MOS(n, m);
    FOR(i, m) pf1(answer[i]);
    return 0;
}














