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
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)

using namespace std;
typedef long long int lint;
typedef double dbl;
int n, m;
vector<int> edge[125];
int indegree[125];

void top_sort(vector<int> &vt)
{
    int flag[125];
    mem(flag, 0);
    while(1)
    {
        int f = 0;
        FOR(i, n)
            if(indegree[i]==0 && flag[i]==0)
            {
               vt.pb(i);
               flag[i] = 1;
               FOR(j, edge[i].size())
                    indegree[edge[i][j]]--;
               f++;
               break;
            }
        if(!f) break;

    }
}

int main()
{
    int t, tst = 1;
    while(sf1(n)==1){
        string ara[n];
        map<string, int> mp;
        string st;
        int pos = 0;
        FOR(i, n) {cin>>st; mp[st] = pos; ara[pos++] = st; }
        sf1(m);
        mem(indegree, 0);
        FOR(i, m)
        {
            string u, v;
            cin >> u >> v;
            int x = mp[v];
            edge[mp[u]].pb(x);
            indegree[x]++;
        }
        vector<int> vt;
        top_sort(vt);
        pf("Case #%d: Dilbert should drink beverages in this order:", tst++);
        FOR(i, vt.size()){
            pf(" %s", ara[vt[i]].c_str());
        }
        pf(".\n\n");
        FOR(i, n) edge[i].clear();
    }
    return 0;
}














