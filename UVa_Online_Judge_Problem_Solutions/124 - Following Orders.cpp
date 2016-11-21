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
vector<int> edge[30];
vector<char> arr;
vector<char> vt;
int rec(vector<int>ind)
{
    if(arr.size()==ind.size())
    {
        FOR(i, arr.size())
            pf("%c", arr[i]);
        pf("\n");
    }
    FOR(i, ind.size())
    {
        if(ind[i]==0){
            vector<int> ind2(ind.begin(), ind.end());
            ind2[i]--;
            FOR(j, edge[i].size())
                ind2[edge[i][j]]--;
            arr.pb(vt[i]);
            rec(ind2);
            arr.ppb;
        }
    }
}
int main()
{
    int t, tst = 1;
    string line;
    int ara[26];
    while(getline(cin, line))
    {
        if(tst>1) pf("\n");
        tst = 2;
        vt.clear();
        char c;
        stringstream ss;
        ss << line;
        while(ss >> c) vt.pb(c);
        sort(vt.begin(), vt.end());
        mem(ara, 0);
        FOR(i, vt.size())
            ara[vt[i]-'a']=i;
        getline(cin, line);
        char u, v;
        ss.clear();
        ss << line;
        vector<int> ind(vt.size(), 0);
        while(ss >> u)
        {
            ss >> v;
            int x = ara[u-'a'];
            int y = ara[v-'a'];
            edge[x].pb(y);
            ind[y]++;
        }
        rec(ind);
        FOR(i, 30) edge[i].clear();
    }
    return 0;
}














