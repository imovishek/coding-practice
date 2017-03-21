#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
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
int main()
{
    map<double,int>mp;
    int t;
    int n;
    sf1(t);
    while(t--)
    {
        sf1(n);
        mp.clear();
        int a,b,c;
        while(n--)
        {
            sf3(a,b,c);
            mp[(dbl)a/b]++;
        }
        lint mult=1;
        while(!mp.empty())
        {
            mult*=(mp.begin()->sc);
            mult%=1000000007;
//            pf("%lf %d*\n",mp.begin()->fs,mp.begin()->sc);
            mp.erase(mp.begin()->fs);
        }
        int ans=mult;
        pf("%d\n",ans);
    }
    return 0;
}
