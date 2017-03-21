#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
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
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)

using namespace std;
typedef long long int lint;
typedef double dbl;


int main()
{
    int t, tst = 1;
    int n, m;
    sf2(n, m);
    char ara[n+7];
    sf("%s", ara);
    int ans = 0, cnt = 0;
    FOR(i, n)
    {
        if(ara[i]=='.') cnt++;
        else {
            if(cnt) ans+=cnt-1;
            cnt = 0;
        }
    }
    if(cnt) ans+=cnt-1;
    pf("%d*\n", ans);
    FOR(i, m)
    {
        int a;
        char ch;
        sf1(a);
        sf(" %c", &ch);
        if(ara[a-1]=='.' && ch!='.'){
            int x = a-1;
            int c = 0;
            if(x-1>=0 && ara[x-1]=='.')c++;
            if(x+1<n && ara[x+1]=='.')c++;
            if(c>=1) ans--;
            int f = 0;
            if(x-1>=0 && ara[x-1]=='.' && (x-2<0 || ara[x-2]!='.')) {ans--; f = 1;}
            if(x+1<n && ara[x+1]=='.' && (x+2>=n || ara[x+2]!='.')) {ans--; f = 1;}

        }
        ara[a-1] = ch;
        pf("%d\n", ans);
    }
    return 0;
}

