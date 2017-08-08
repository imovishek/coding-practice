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

vector<int> edge[100005];
int dist[100007];
int bfs(int st)
{
    mem(dist, -1);
    queue<int> Q;
    Q.push(st);
    dist[st] = 0;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        FOR(i, edge[u].size())
        {
            int v = edge[u][i];
            if(dist[v]==-1)
            {
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }
}


int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        map<string , int> mp;
        int pos = 0;
        int n, m;
        sf2(n, m);
        getchar();
        int st;
        FOR(i, n)
        {
            string line;
            getline(cin, line);
            istringstream ss(line);
            string u, v;
            vector<int> vt;
            while(!ss.eof())
            {
                ss >> u;
                ss >> v;
                u.insert(u.length(), 1, ' ');
                u = u + v;
                u.erase(u.length()-1, u.length()-1);
//                cout << u <<  '*' ;
                int a = 0;
                FOR(i, u.length()) if(u[i]==':') {a = i; break;}
                if(a){
                    u.erase(a, u.length()-1);
                }
                auto it = mp.find(u);
                int x;
                if(it==mp.end()) x = mp[u] = pos++;
                else x = it->sc;
                vt.pb(x);
                if(u=="Erdos, P.") st = x;
//                cout << x << endl;
                if(v[v.length()-1]==':') break;
            }
            FOR(k, vt.size())
            {
                FOR(j, vt.size())
                {
                    if(k==j) continue;
                    edge[vt[k]]. pb(vt[j]);
                }
            }
        }
//        pf1(st);
        bfs(st);
        pf("Scenario %d\n", tst++);
        FOR(i, m)
        {
            string name;
            getline(cin ,name);
            int x;
            if(mp.find(name)==mp.end()) pf("%s infinity\n", name.c_str());
            else{
                x = mp[name];
                if(dist[x]==-1) pf("%s infinity\n", name.c_str());
                else pf("%s %d\n", name.c_str(), dist[x]);
            }
        }

        FOR(i, pos) edge[i].clear();
    }
    return 0;
}














