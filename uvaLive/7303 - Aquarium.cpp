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
char grid[107][107];
int val[107][107];
int n, m;
int fx[] = {0,0,1,-1};
int fy[] = {1,-1,0,0};
bool isvali(int x, int y)
{
    return x>-1 && y>-1 && x<n && y<m;
}
struct data{
    int u, v, w;
    data(){}
    data(int _u, int _v, int _w){
        u = _u, v = _v, w = _w;
    }
    bool operator<(const data &a) const{
        return w<a.w;
    }
}edge[1000007];
int par[1000007], pos;

int id(int u)
{
    if(par[u]!=u) par[u] = id(par[u]);
    return par[u];
}
int kruskal()
{
    int ans = 0;
    FOR(i, pos){
        int u = edge[i].u, v = edge[i].v, w = edge[i].w;
        int x = id(u), y = id(v);
        if(x!=y){
            par[x] = y;
            ans+=w;
        }
    }
    return ans;
}
int main()
{
    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        sf2(n, m);
        FOR(i, n) sf("%s", grid[i]);
        FOR(i, n)
            FOR(j, m)
                sf1(val[i][j]);
        pos = 0;
        FOR(i, n)
            FOR(j, m)
            {
                int up = (i*m+j+1)*2 - 1, down = up+1;
                edge[pos++] = data(up, down, val[i][j]);
                edge[pos++] = data(down, up, val[i][j]);

                FOR(k, 4)
                {
                    int a = fx[k] + i, b = fy[k] + j;
                    if(isvali(a, b)==0) continue;
                    int up2 = (a*m+b+1)*2 - 1, down2 = up2+1;
                    if(grid[i][j]=='/'){
                        if(k==0)
                        {
                            if(grid[a][b]=='/') edge[pos++] = data(down, up2, 0);
                            else edge[pos++] = data(down, down2, 0);
                        }
                        else if(k==1){
                            if(grid[a][b]=='/') edge[pos++] = data(up, down2, 0);
                            else edge[pos++] = data(up, up2, 0);
                        }
                        else if(k==2){
                            if(grid[a][b]=='/') edge[pos++] = data(down, up2, 0);
                            else edge[pos++] = data(down, up2, 0);
                        }
                        else if(k==3){
                            if(grid[a][b]=='/') edge[pos++] = data(up, down2, 0);
                            else edge[pos++] = data(up, down2, 0);
                        }
                    }
                    else{
                        if(k==0)
                        {
                            if(grid[a][b]=='/') edge[pos++] = data(up, up2, 0);
                            else edge[pos++] = data(up, down2, 0);
                        }
                        else if(k==1){
                            if(grid[a][b]=='/') edge[pos++] = data(down, down2, 0);
                            else edge[pos++] = data(down, up2, 0);
                        }
                        else if(k==2){
                            if(grid[a][b]=='/') edge[pos++] = data(down, up2, 0);
                            else edge[pos++] = data(down, up2, 0);
                        }
                        else if(k==3){
                            if(grid[a][b]=='/') edge[pos++] = data(up, down2, 0);
                            else edge[pos++] = data(up, down2, 0);
                        }
                    }
                }
//                if(grid[i][j]=='\\'){
//                    int a = i -1, b = j + 1;
//                    int up2 = (a*n+b+1)*2 - 1, down2 = up2+1;
//                    if(isvali(a, b) && grid[a][b]=='\\'){
//                        edge[pos++] = data(up, down2, 0);
//                    }
//                    a = i + 1, b = j - 1;
//                    up2 = (a*n+b+1)*2 - 1, down2 = up2+1;
//                    if(isvali(a, b) && grid[a][b]=='\\'){
//                        edge[pos++] = data(down, up2, 0);
//                    }
//                }
//                else{
//                    int a = i -1, b = j - 1;
//                    int up2 = (a*n+b+1)*2 - 1, down2 = up2+1;
//                    if(isvali(a, b) && grid[a][b]=='\\'){
//                        edge[pos++] = data(up, down2, 0);
//                    }
//                    a = i + 1, b = j + 1;
//                    up2 = (a*n+b+1)*2 - 1, down2 = up2+1;
//                    if(isvali(a, b) && grid[a][b]=='\\'){
//                        edge[pos++] = data(down, up2, 0);
//                    }
//                }
            }
        FOR(i, pos+1) {
        par[i] = i;
        // pf("%d %d %d**\n", edge[i].u, edge[i].v, edge[i].w);
        }
        sort(edge, edge+pos);

        pcase(tst++);
        pf1(kruskal());

    }
    return 0;
}














