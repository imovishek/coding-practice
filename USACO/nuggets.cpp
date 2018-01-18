/*
ID: ovishek1
LANG: C++11
PROB: nuggets
*/

#include <bits/stdc++.h>
using namespace std;
#define mx 1000006

bool dp[1000006];

int main()
{
    freopen("nuggets.in", "r", stdin);
    freopen("nuggets.out", "w", stdout);

    int n;
    scanf("%d", &n);
    dp[0] = 1;
    int mini = INT_MAX;
    for(int i = 0; i<n; i++)
    {
        int a;
        scanf("%d", &a);
        mini = min(a, mini);
        for(int j = a; j<mx; j++)
        {
            dp[j] |= dp[j - a];
        }
    }
    int maxi = 0, ans = 0;
    for(int i = mx - 1; i>=0; i--)
    {
        if(dp[i]==0) {
                ans = i;
                break;
        }
        maxi++;
    }
//    cout << maxi << " " << endl;
    if(maxi < mini) printf("0\n");
    else printf("%d\n", ans);
    return 0;
}

