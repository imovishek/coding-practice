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
#define mx              200007

using namespace std;
typedef long long int lint;
typedef double dbl;
pii num[mx];
bool comp(pii a, pii b)
{
    if(a.fs==b.fs)
    {
        if(a.sc/2==b.sc/2) return a.sc<b.sc;
        if(a.sc%2 != b.sc%2) return (a.sc%2);
        if(a.sc%2==0) return num[a.sc/2].sc > num[b.sc/2].sc;
        else return num[a.sc/2].fs > num[b.sc/2].fs;
    }
    return a.fs<b.fs;
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
        int n, m;
        sf2(n, m);
        pii ara[2*m+1];
        map<pii, bool> mp;
        int pos = 0;
        FOR(i, m) {
            int u, v;
            sf2(u, v);
            if(mp.find(pii(u, v))!=mp.end()) continue;
            mp[pii(u,v)] = 1;
            ara[pos].fs = u, ara[pos].sc = pos;
            pos++;
            ara[pos].fs = v, ara[pos].sc = pos;
            num[pos/2].fs = u, num[pos/2].sc = v;
            pos++;
        }
        sort(ara, ara+pos, comp);
        stack<int> st;
        int f = 0;
        FOR(i, pos) pf("%d ", ara[i].fs);
        pf("\n");
        FOR(i, pos) pf("%d ", ara[i].sc);
        pf("\n");
        int prev = -1;
        FOR(i, pos)
        {
            int idx = ara[i].sc;
            int val = ara[i].fs;
            if(idx%2==0){
                st.push(idx);
                if(prev==val && num[idx/2].fs!=num[idx/2].sc){
                    f = 1;
                    break;
                }
            }
            else{
                int top = st.top();
                prev = max(prev, val);
                st.pop();
                if(top!=idx-1) {f = 1; break;}
            }
        }
        if(f) pf("No\n");
        else pf("Yes\n");
    }
    return 0;
}

/*

10
9 3
0 8
0 4
5 8

9 4
0 8
0 4
5 8
0 4

9 5
0 8
0 4
5 8
0 4
4 4

*/












