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

vector<pii> pfact[mx];
void fun()
{
    pfact[1].pb(pii(1,1));
    for(int tn = 2; tn<mx; tn++){
        int n = tn;
        vector<pii> vt;
        for(int i = 2; i*i<=n; i++)
        {
            if(n%i==0){
                pii a;
                a.fs = i;
                a.sc = 0;
                while(n%i==0){
                    a.sc++;
                    n/=i;
                }
                vt.pb(a);
            }
        }
        if(n>1) vt.pb(pii(n, 1));
//        pf("%d*\n", tn);
//        FOR(i, vt.size()){
//            pf("%d %d\n", vt[i].fs, vt[i].sc);
//        }
        int y = 0;
        vt.pb(pii(inf, 0));
        n = tn;
        for(int i = 0; i<pfact[n-1].size(); i++)
        {
            if(vt[y].fs==pfact[n-1][i].fs)
                pfact[n].pb(pii(vt[y].fs, vt[y].sc + pfact[n-1][i].sc)), y++;
            else if(vt[y].fs<pfact[n-1][i].fs){
                pfact[n].pb(vt[y]);
                i--;
                y++;
            }
            else{
                pfact[n].pb(pfact[n-1][i]);
            }

            if(y>=vt.size()) break;
        }
        while(y<vt.size()-1)
            pfact[n].pb(vt[y++]);
    }
}


int main()
{
#ifdef OVI
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    fun();
    cout << pfact[10].size() << endl;
    FOR(i, pfact[10].size()){
        pf("%d %d\n", pfact[10][i].fs, pfact[10][i].sc);
    }
    sf1(t);
    while(t--)
    {
        ;
    }
    return 0;
}














