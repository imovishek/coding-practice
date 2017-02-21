/*
ID: ovishek1
LANG: C++11
PROB: namenum
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

ifstream dict("dict.txt");
map<string, bool> mp;
string num;
int n;
int ara[] = {0, 3, 6, 9, 12, 15, 18, 21};
vector<string> ans;
string mul;
void rec(int pos, string st){
//    cout << st << endl;
    if(pos==n){
        if(mp.find(st)!=mp.end()) ans.pb(st);
        return;
    }
    FOR(i, 3){
        string temp;
        temp = st;
        int f = 0;
        if(ara[ mul[pos] - '0' - 2] + i >= 16) f = 1;
        temp += ara[ mul[pos] - '0' - 2] + 'A' + i + f;
        rec(pos+1, temp);
    }
}

int main()
{
    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);
    int t, tst = 1;
    string st;
    while(dict >> st) mp[st] = 1;
    cin >> mul;
    n = mul.size();
    rec(0, "");
    sort(ans.begin(), ans.end());
    n = ans.size();
    FOR(i, n)
        cout << ans[i] << endl;
    if(n==0) cout << "NONE" << endl;
    return 0;
}














