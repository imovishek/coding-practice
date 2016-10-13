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


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, tst = 1;
    int n, f=0;
    while(sf1(n)!=EOF)
    {
        if(f) pf("\n");
        f = 1;
        string st[n];
        int ara[n];
        mem(ara, 0);
        map<string, int> mp;
        FOR(i, n){
            cin>>st[i];
            mp[st[i]] = i;
        }
        FOR(i, n)
        {
            string x;
            cin >> x;
            int a, b;
            cin >> a >> b;
            if(b==0) continue;
            int get = a/b;
            ara[mp[x]]-=a;
            a = a-(a/b)*b;
            ara[mp[x]]+=a;
            FOR(i, b)
            {
                cin >> x;
                ara[mp[x]]+=get;
            }

        }
        FOR(i, n) pf("%s %d\n",st[i].c_str(), ara[i]);

    }
    return 0;
}
/*

5
dave laura owen vick amr
dave 200 3 laura owen vick
owen 500 1 dave
amr 150 2 vick owen
laura 0 2 amr vick
vick 0 0
3
liz steve dave
liz 30 1 steve
steve 55 2 liz dave
dave 0 2 steve liz

*/







