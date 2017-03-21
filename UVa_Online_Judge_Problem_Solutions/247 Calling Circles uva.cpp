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

vector<int> edge[100], rev[100];
int flag[100], bflag[100];
string  ara[100];
void dfs(stack<int>&st, int u)
{
    if(flag[u]) return;
    flag[u] = 1;
    FOR(i, edge[u].size()){
        dfs(st, edge[u][i]);
    }
    st.push(u);
}
void dfs2(vector<int> &vt, int u)
{
    if(bflag[u]) return;
    vt.pb(u);
    bflag[u] = 1;
    FOR(i, rev[u].size())
        dfs2(vt, rev[u][i]);

}

void scc(stack<int>&st)
{
    while(!st.empty())
    {
        int u = st.top();
        st.pop();
        if(bflag[u]) continue;
        vector<int> vt;
        dfs2(vt, u);
        if(vt.size()) pf("%s", ara[vt[0]].c_str());
        for(int i = 1; i<vt.size() ; i++)
            pf(", %s", ara[vt[i]].c_str());
        pf("\n");
    }
}



int main()
{
    int t, tst = 1;
    int n, m, f = 0;
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while(sf2(n, m))
    {
        if(n==0 && m==0) return 0;
        if(f) pf("\n");
        f = 1;
        map<string, int> mp;
        int pos = 0;
        FOR(i, m)
        {
            string u, v;
            cin >> u >> v;
            if(mp.find(u)==mp.end()){
                    mp[u] = pos;
                    ara[pos++] = u;
            }
            if(mp.find(v)==mp.end()){
                    mp[v] = pos;
                    ara[pos++] = v;
            }
            int x = mp[u], y = mp[v];
            edge[x].pb(y);
            rev[y].pb(x);
        }
        pf("Calling circles for data set %d:\n", tst++);
        mem(bflag, 0);
        mem(flag, 0);
        stack<int> st;
        FOR(i, pos){
            if(bflag[i]==0)
            {
                dfs(st, i);
            }
        }
        scc(st);
        FOR(i, n) {edge[i].clear(); rev[i].clear();}

    }
    return 0;
}


/*
11 22
expired chevy
caroline expired
acne chevy
emperor expired
exclusion emperor
nominated emperor
electro caroline
casey nominated
develops casey
bufing nominated
emperor chevy
casey develops
electro chevy
acne emperor
casey exclusion
bufing exclusion
chevy emperor
caroline acne
casey chevy
bufing develops
caroline chevy
acne exclusion

8 9
A B
B C
C D
D A
E D
E F
F G
G E
G I
*/












