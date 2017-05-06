/*
 ID: ovishek1
 LANG: C++11
 TASK: subset
*/

#include<bits/stdc++.h>
using namespace std;
int n;
long long int dp[50][5050];
long long int rec(int pos, int sum)
{
	if(pos==n) {
		if(sum==0) return 1LL;
		return 0;
	}
	long long int &ret = dp[pos][sum];
	if(ret!=-1) return ret;
	ret = 0;
	ret += rec(pos+1, sum);
	ret += rec(pos+1, sum-pos-1);
	return ret;
}

int main()
{
	freopen("subset.in", "r", stdin);
	freopen("subset.out", "w", stdout);
	memset(dp, -1, sizeof dp);
	cin >> n;
	if((n*(n+1)/2)&1) {cout << "0" << endl; return 0;}
	long long int ans = rec(0, (n*(n+1)/2)/2);
	cout << ans/2 << endl;
	return 0;
}