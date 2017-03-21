#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#define pii pair<int,int>
#define pi3 pair<int,pii>
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a);
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 2147483647
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
using namespace std;
typedef long long int lint;
typedef double dbl;
vector <pi3> st;
bool comp(pi3 a, pi3 b)
{
    if(a.sc.fs>b.sc.fs) return 0;
    return 1;
}
int flag[10],n, t, b;
int rec(int pos, int w, int cost)
{
    if(pos == t) return cost;
    int maxi = rec(pos+1, w, cost);
    int x = 0;
    int ara[25];
    for(int i = 0;i<8;i++)ara[i] = flag[i];
    for(int i = st[pos].sc.fs; i>=0; i--){
        x+=flag[i];
        flag[i] = 0;
    }
    int pass = w-x+st[pos].fs;
    if(pass<=n){
        flag[st[pos].sc.sc]+=st[pos].fs;
        int now = rec(pos + 1, pass, cost+(st[pos].sc.sc-st[pos].sc.fs)*st[pos].fs);
        if(maxi < now) maxi = now;
    }
    for(int i = 0;i<8;i++)flag[i] = ara[i];
    return maxi;
}
int main()
{
    #ifdef OVI
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif
    while(sf3(n,b,t)!=EOF)
    {
        if(!n && !b && !t) break;
        int start, desti, piece;
        FOR(i,t)
        {
            sf3(start, desti, piece);
            st.pb(pi3(piece, pii(start, desti)));
        }
        for(int i = 0; i<t ; i++) pf("%d %d %d##\n", st[i].sc.fs, st[i].sc.sc, st[i].fs);
        sort(st.begin(), st.end(), comp);
        for(int i = 0; i<t ; i++) pf("%d %d %d**\n", st[i].sc.fs, st[i].sc.sc, st[i].fs);
        for(int i = 0; i<=b; i++) flag[i] = 0;
        pf("%d\n", rec(0,0,0));
        st.clear();

    }
    return 0;
}

