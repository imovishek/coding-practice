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
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)

using namespace std;
typedef long long int lint;
typedef double dbl;
int parent[100];

int id(int n)
{
    if(parent[n]!=n) parent[n] = id(parent[n]);
    return parent[n];
}
int main()
{
    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        char ch, u, v;
        string st;
        sf(" %c", &ch);
        getchar();
        for(int i = 0; i<=ch-'A' ; i++) parent[i] = i;
        while(getline(cin, st) && st.size()){
            u = st[0]-'A';
            v = st[1]-'A';
            parent[id(u)] = id(v);
        }
        set<int> stt;
        for(int i = 0; i<=ch-'A' ; i++) stt.insert(id(i));
        pf1(stt.size());
        if(t) pf("\n");
    }
    return 0;
}














