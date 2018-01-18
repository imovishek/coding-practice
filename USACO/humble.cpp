/*
ID: ovishek1
LANG: C++11
PROB: humble
*/
#include <bits/stdc++.h>
#define ll long long
#define mx 105
using namespace std;

int main()
{
    freopen("humble.in", "r", stdin);
    freopen("humble.out", "w", stdout);
    int n, m;
    scanf("%d %d", &n, &m);
    int ara[n];
    for(int i = 0; i<n; i++)
        scanf("%d", &ara[i]);

    long long dp[m+1];
    dp[0] = 1;
    for(int i = 1; i<=m; i++)
        dp[i] = 10000000000007ll;
    int ptr[n];
    memset(ptr, 0, sizeof ptr);

    for(int i = 1; i<=m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            while(1ll * dp[ptr[j]] * ara[j] <= dp[i-1]) ptr[j]++;
            if(i == ptr[j]) continue;
            dp[i] = min(dp[i], 1ll * dp[ptr[j]] * ara[j]);
        }
    }
    printf("%lld\n", dp[m]);
    return 0;
}



