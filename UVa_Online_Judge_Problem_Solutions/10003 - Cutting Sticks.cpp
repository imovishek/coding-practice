/*input
100
3
25 50 75
10
4
4 5 7 8
0
*/

#include <bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long
#define MOD 1000000007
int ara[55];
int dp[51][1001];
int rec(int pos, int len)
{
	if(ara[pos]+len <= ara[pos+1]) return 0;
	int &ret = dp[pos][len];
	if(ret != -1) return ret;
	ret = INT_MAX;
	for(int i = pos+1; ara[i] < ara[pos]+len; i++)
		ret = min(ret, len + rec(pos, ara[i]-ara[pos]) + rec(i, len - (ara[i]-ara[pos])));
	return ret;
}
int main()
{
	int l, n;
	while(scanf("%d", &l) && l)
	{
		scanf("%d", &n);
		for(int i = 1; i<=n; i++)
			scanf("%d", &ara[i]);
		ara[n+1] = l;
		memset(dp, -1, sizeof dp);
		cout << "The minimum cutting is "<< rec(0, l) << "." << endl;
	}
	return 0;
}
