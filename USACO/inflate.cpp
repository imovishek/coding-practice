/*
ID: ovishek1
LANG: C++11
PROB: inflate
*/
#include <bits/stdc++.h>
#define ll long long
#define mx 105
using namespace std;

int main()
{
    freopen("inflate.in", "r", stdin);
    freopen("inflate.out", "w", stdout);
    int m, n;
    scanf("%d %d", &m, &n);
    int dp[m+1];
    memset(dp, 0, sizeof dp);
    for(int i = 1; i<=n; i++)
    {
        int score, tm;
        scanf("%d %d", &score, &tm);
        for(int j = tm; j<=m; j++)
        {
            dp[j] = max(dp[j], dp[j-1]);
            dp[j] = max(dp[j], dp[j-tm] + score);
        }
    }
    printf("%d\n", dp[m]);
    return 0;
}


