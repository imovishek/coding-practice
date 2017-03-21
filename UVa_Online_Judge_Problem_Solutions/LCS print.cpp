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
int dp[100][100];
char a[] = "actrdwak";
char b[] = "artcdawk";
vector<char> vt;
int tric[100][100]
void print(int x, int y)
{
    if(!x || !y){
        for(int i = vt.size()-1; i>=0 ; i--)
        {
            pf("%c",vt[i]);
        }
        pf("\n");
        return;
    }
    if(a[x-1]==b[y-1]){
        vt.pb(a[x-1]);
        print(x-1, y-1);
        vt.ppb;
    }
    else{
        if(dp[x][y-1]<dp[x-1][y])
            print(x-1, y);
        else if(dp[x][y-1]==dp[x-1][y])
        {
            print(x-1, y);
            print(x, y-1);
        }
        else print(x, y-1);
    }
}
int main()
{
    int t, tst = 1;
    int l1 = strlen(a);
    int l2 = strlen(b);
    FOR(i, l1) dp[i][0] = 0;
    FOR(i, l2) dp[0][i] = 0;
    for(int i = 1; i<=l1 ; i++)
    {
        for(int j = 1; j<=l2 ; j++)
        {
            if(a[i-1]==b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[l1][l2] << endl;
    print(l1, l2);
    return 0;
}

