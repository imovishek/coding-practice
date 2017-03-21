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

int ara[1000007] = {1,2,3};
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        int n, m, k;
        sf3(n, m, k);
        for(int i = 3; i<n ; i++) ara[i] = (ara[i-1] + ara[i-2] + ara[i-3])%m + 1;
        int x = 0;
        int f[k+1], cnt = 0, a;
        mem(f, 0);
        int mini = inf;
        for(int i = 0; i<n ; i++)
        {
            if(ara[i]>k) continue;
            if(f[ara[i]]==0) cnt++;
            f[ara[i]]++;
            while(cnt==k)
            {
                mini = min(mini, i-x+1);
                a = ara[x++];
                if(a>k) continue;
                if(f[a]>1) f[a]--;
                else if(f[a]==1){f[a]--; cnt--;}

            }
        }
        pcase(tst++);
        if(mini==inf) pf("sequence nai\n");
        else pf("%d\n",mini);
    }
    return 0;
}





