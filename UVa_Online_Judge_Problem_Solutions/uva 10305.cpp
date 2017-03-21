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
int indegree[125];
int n, m;
vector<int> edge[107];
void top_sort(vector<int> &vt)
{
    int flag[n+5];
    mem(flag, 0);
    while(1)
    {
        int f = 0;
        for(int i = 1; i<=n ; i++) if(!flag[i] && !indegree[i]){
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
    while(sf2(n, m)){
        if(n==0 && m==0) return 0;
        int u, v;
        mem(indegree, 0);
        FOR(i, m){
            sf2(u, v);
            edge[u].pb(v);
            indegree[v]++;
        }
        vector<int> vt;
        top_sort(vt);
        if(vt.size()) pf("%d", vt[0]);
        for(int i = 1; i<vt.size(); i++)
            pf(" %d", vt[i]);
        pf("\n");
        FOR(i, n+1) edge[i].clear();
    }

    return 0;
}















