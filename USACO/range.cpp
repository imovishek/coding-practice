/*
ID: ovishek1
LANG: C++11
PROB: range
*/

#include <bits/stdc++.h>
using namespace std;
#define mx 805
int ara[256][256];
int cnt[256];

int sum(int i, int j, int a, int b)
{
    return ara[a][b] - ara[a][j-1] - ara[i-1][b] + ara[i-1][j-1];
}
int main()
{
    freopen("range.in", "r", stdin);
    freopen("range.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=n; j++){
            scanf("%1d", &ara[i][j]);
            ara[i][j] += ara[i][j-1];
        }
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=n; j++){
            ara[i][j] += ara[i-1][j];
        }
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=n; j++)
            for(int len = 2; i+len<=n+1 && j+len<=n+1; len++)
                if(sum(i, j, i+len-1, j+len-1) == len*len)
                    cnt[len]++;
    for(int i = 2; i<256; i++)
    {
        if(cnt[i]) cout << i << " " << cnt[i] << endl;
    }

    return 0;
}
