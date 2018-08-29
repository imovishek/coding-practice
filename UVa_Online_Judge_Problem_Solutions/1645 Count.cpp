/*input
1
2
3
4
5
6
10
40
50
*/

#include <bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long
#define MOD 1000000007
#define fs first
#define sc second
ll dp[1005][1005];
vector<int> divi[1005];
ll bigmod(ll a, ll p)
{
	if(p==0) return 1;
	if(p&1) return a * bigmod(a, p-1) % MOD;
	ll mo = bigmod(a, p/2);
	return mo * mo % MOD;
}

ll rec(int n, int prev)
{
	// if(prev==0) return n==1;
	if(n==1) return 1;
	ll &ret = dp[n][prev];
	if(ret != -1) return ret;
	ret = 0;
	for(int d : divi[n-1])
	{
		ret += rec(d, 11);
		ret %= MOD;
	}
	return ret;
}
int main()
{
	for(int i = 1; i<1005; i++)
		for(int j = i; j<1005; j += i)
			divi[j].push_back(i);
	// for(int d : divi[36])
	// 	cout << d << " ";
	// cout << endl;
	int n, tst = 1;
	while(scanf("%d", &n) == 1){
		memset(dp, -1, sizeof dp);
		printf("Case %d: ", tst++);
		cout << rec(n, 11) << endl;
	}
	return 0;
}
