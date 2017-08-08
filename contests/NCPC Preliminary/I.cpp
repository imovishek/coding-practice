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
#define mx              1007

using namespace std;
typedef long long int lint;
typedef double dbl;

vector<int> edge[mx];
int low[mx], disc[mx], vis[mx], col[mx], cnt[mx];
int pos = 0, timer = 0;
stack<int> st;
int scc(int u, int p)
{
    vis[u] = 1;
//    pf("dhuklo %d\n", u);
    low[u] = disc[u] = timer++;
    st.push(u);
    FOR(i, edge[u].size())
    {
        int v = edge[u][i];
        if(!vis[v]){
            scc(v, u);
            low[u] = min(low[u], low[v]);
        }
        else if(vis[v]==1){
            low[u] = min(low[u], disc[v]);
        }
    }
    if(low[u]==disc[u]){
        while(!st.empty()){
            int x = st.top();
            st.pop();
            col[x] = pos;
//            cout << "<" << x << ">" ;
            vis[x] = 2;
            cnt[pos] ++;
            if(x==u) break;
        }
        pos++;
//        pf("\n");
    }
//    pf("berholo %d\n", u);

}

int main()
{
#ifdef OVI
//         freopen("input.txt", "r", stdin);
//         freopen("output.txt", "w", stdout);
#endif // OVI

    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        int n, m;
        sf2(n, m);
        FOR(i, m)
        {
            int u, v;
            sf2(u, v);
            edge[u].pb(v);
        }

        FOR1(i, n){
            if(!vis[i])scc(i, -1);
        }
        int ans = 0;
        FOR(i, pos) if(cnt[i]==1) ans++;
        pcase(tst++);
        cout << ans << endl;
        FOR1(i, n) edge[i].clear();
        mem(vis, 0);
        mem(cnt, 0);
        pos = 0, timer = 0;

    }
    return 0;
}


/*

10 20
2 1 1
1 3 1
1 9 2
1 10 2
2 3 2
2 4 1
2 10 1
3 4 1
5 3 1
4 5 1
6 4 1
6 5 1
7 5 1
6 7 2
6 8 1
7 8 1
7 9 2
9 8 1
8 10 1
9 10 1

*/










