#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<queue>
#include<map>
#define pii pair<int,int>
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
using namespace std;
typedef long long int lint;
typedef double dbl;
vector <int > edge[207];
map<string, int>mp;
map<string, int>:: iterator it;
string ara[207];
queue< int > Q;
int level[207];
int bfs(int u, int en)
{
    int v;
    Q.push(u);
    level[u]=0;
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        for(int i=0;i<edge[u].size();i++){
            v=edge[u][i];
            if(level[v]==-1)
            {
                level[v]=level[u]+1;
                if(v==en){while(!Q.empty())Q.pop();return level[en];}
                Q.push(v);
            }
        }
    }
}
int main()
{
    int t,tst=1;
    sf1(t);
    getchar();
    string a,u,v,b;
    int pe=0;
    while(t--)
    {
        if(pe)pf("\n");
        pe=1;
        int pos=0;
        while(cin >> a){
            if(a.length()==0)continue;
            int flag=0;
            for(int i=0;a[i];i++)
            if(a[i]=='*'){flag=1;break;}
            if(flag)break;

            if(mp.find(a)==mp.end())
            {
                mp[a]=pos;
                for(it = mp.begin(); it!= mp.end() ; it++)
                {
                    b=it->fs;
                    int fl=0;
                    if(a.length()!=b.length())continue;
                    for(int i=0;b[i];i++){
                        if(a[i]!=b[i])fl++;
                    }
                    if(fl==1){
                        edge[pos].pb(it->sc);
                        edge[it->sc].pb(pos);
//                        pf("%d %d**\n",mp[a],mp[b]);
                    }
                }
                ara[pos++]=a;
            }
        }
        getchar();
        while(getline(cin, a))
        {
            char ch;
            if(a.length()==0)break;
            memset(level,-1,sizeof(level));
            stringstream ss;
            ss << a;
            ss >> u >> v ;
//            cout << '*' << k << '*' << mp[u] << ' ' << mp[v] << endl;
            cout << u << ' ' << v << ' ' << bfs(mp[u],mp[v]) << endl;
//            while(ss>>ch);

        }
        for(int i=0;i<207;i++)edge[i].clear();
        mp.clear();

    }
    return 0;
}
