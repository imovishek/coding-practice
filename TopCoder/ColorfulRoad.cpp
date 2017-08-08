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

int dp[100];
int n;
string st;
int rec(int pos)
{
    int col = st[pos];
    if(pos==n-1) return 0;
    int &ret = dp[pos];
    if(ret != -1) return ret;
    ret = inf;
    for(int i = pos+1; i<n ; i++)
        if(st[i]==((col+1)%3)){
            int x = rec(i);
            if(x==inf) continue;
            ret = min(ret, (i-pos)*(i-pos) + x);
        }
    return ret;
}

class ColorfulRoad{
public:
    int getMin(string sti){
        n = sti.length();
        st = sti;
        FOR(i, n){
            if(sti[i]=='R') st[i] = 0;
            else if(sti[i]=='G' ) st[i] = 1;
            else st[i] = 2;
        }
        mem(dp, -1);
        int ans = rec(0);
        if(ans==inf) return -1;
        else return ans;
    }
};

int main(){
    ColorfulRoad a;
    cout << a.getMin("RBRGBGBGGBGRGGG") << endl;
    return 0;
}












