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
//#define FORv(vt)            for(auto &it = vt.begin(); it!=vt.end(); it++)
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
    int m, n;
    sf1(t);
    while(t--)
    {
        map< pii, int > mp;
        sf2(n, m);
        pii ara[m];
        vector<pii> cont[n];
        int flag[n];
        mem(flag, 0);
        int pos = 0;
        FOR(i, m)
        {
            int u, v;
            sf2(u, v);
            if(mp.find(pii(u, v))!=mp.end()) continue;
            mp[pii(u, v)] = 1;
            ara[pos++] = pii(u, v);
            flag[u]++;
        }
        int f = 0;
        FOR(i, n) if(flag[i]>1) {f = 1; break;}
        m = pos;
        pos = 0;
        FOR(i, m){
            if(ara[i].fs!=ara[i].sc) ara[pos++] = ara[i];
        }
        m = pos;
        sort(ara, ara+m);
        FOR(i, m)
        {
            cont[ara[i].sc].pb(pii(ara[i].fs, i));
        }
        deque<int> dq;
        deque<int> :: iterator it;
        FOR(i, m)
        {
            int u = ara[i].fs, v = ara[i].sc;
            if(cont[u].size()==0) continue;
            if(!(cont[u].size()==1 && cont[u][0].sc==i)) {
                f = 1;
//                pf("%d %d %d*\n", cont[u][0].fs, cont[u][0].sc, u);
            }
            if(f) break;
        }
//        pf1(f);
        if(f){
            pf("No\n");
            continue;
        }
        FOR(i, n){
            FOR(j, cont[i].size()){
                if(!dq.empty() && dq.back()>cont[i][j].fs) dq.push_front(cont[i][j].fs);
                else dq.push_back(cont[i][j].fs);
            }
            FOR(j, cont[i].size()) dq.pb(i);
        }
//        for(it = dq.begin(); it!=dq.end(); it++) pf("%d ", *it);
        int prev = dq.front();
        for(it = dq.begin(); it!=dq.end(); it++) if(prev>*it) {f = 1; break;}
        if(f) pf("No\n");
        else pf("Yes\n");

    }
    return 0;
}

/*

9 4
0 8
2 3
1 6

*/












