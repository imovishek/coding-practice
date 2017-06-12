
/*
	ID: ovishek1
	LANG: C++11
	TASK: money
*/


#include<bits/stdc++.h>
using namespace std;
int c[26];
long long dp[26][10005];
int n, k;

int main()
{
	freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
    scanf("%d %d", &n, &k);
    for(int i = 1; i<=n; i++)
    {
    	cin >> c[i];
    }
    for(int i = 0; i<=n; i++) dp[i][0] = 1;
    for(int i = 1; i<=n; i++)
    	for(int j = 0; j<=k; j++){
    		if(j < c[i]) dp[i][j] = dp[i-1][j];
    		else dp[i][j] = dp[i-1][j] + dp[i][j - c[i]];
    	}
    cout << dp[n][k] << endl;
	return 0;
}