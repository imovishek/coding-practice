/*
ID: ovishek1
LANG: C++11
PROB: game1
*/
#include <bits/stdc++.h>
#define ll long long
#define mx 105
using namespace std;
int n;
int ara[mx];
int cum[mx];
int dp[mx][mx];
int rec(int l, int r)
{
    if(l==r) return ara[r];
    int &ret = dp[l][r];
    if(ret != -1) return ret;
    int sum = cum[r] - cum[l-1];
    ret = sum - rec(l+1, r);
    ret = max(ret, sum - rec(l, r-1));
    return ret;
}

int main()
{
    freopen("game1.in", "r", stdin);
    freopen("game1.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i<=n; i++)
        scanf("%d", &ara[i]), cum[i] += ara[i] + cum[i-1];
    memset(dp, -1, sizeof dp);
    int x = rec(1, n);
    cout << x << " " << cum[n] - x << endl;
    return 0;
}


