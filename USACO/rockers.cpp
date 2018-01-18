/*
ID: ovishek1
LANG: C++11
PROB: rockers
*/
#include <bits/stdc++.h>
#define prev prevsource
using namespace std;
int n, m, t;
int ara[23];
int dp[21][21][21];
int rec(int pos, int now, int roise)
{
    if(now==m) return 0;
    if(pos==n){
        return 0;
    }
    int &ret = dp[pos][now][roise];
    if(ret != -1) return ret;
    ret = rec(pos, now+1, t);
    if(ara[pos] <= roise) ret = max(ret, 1 + rec(pos+1, now, roise - ara[pos]));
    ret = max(ret, rec(pos+1, now, roise));
    return ret;
}
int main()
{
    freopen("rockers.in", "r", stdin);
    freopen("rockers.out", "w", stdout);
    scanf("%d %d %d", &n, &t, &m);
    for(int i = 0; i<n; i++)
        scanf("%d", &ara[i]);
    memset(dp, -1, sizeof dp);
    cout << rec(0, 0, t) << endl;
    return 0;
}


