/*
ID: ovishek1
LANG: C++11
PROB: nocows
*/


#include<bits/stdc++.h>
using namespace std;
#define MOD 9901
int dp[202][102];
int n, k;
int twospower[500];
int rec(int koyta, int height, int sig){
	if(koyta==1){
		if(!sig)
			return height<=k;
		else {
			return height < k;
		}
	}
	koyta--;
	int &ret = dp[koyta][height];
	if(ret!=-1) return ret;
	ret = 0;
	for(int i = 1; i<=koyta; i+=2)
	{
		ret += rec(i, height+1, sig) * rec(koyta-i, height+1, sig);
		ret %= MOD;
	}
	return ret;
}

int main()
{
	freopen("nocows.in", "r", stdin);
    freopen("nocows.out", "w", stdout);
	int cnt = 1;
	for(int i = 1; i<=300; i = (i<<1) + 1) twospower[i] = cnt++; 

    memset(dp, -1, sizeof dp);
    cin >> n >> k;
    k--;
    int a = rec(n, 0, 0);
    memset(dp, -1, sizeof dp);
    cout << (a - rec(n, 0, 1) + MOD) % MOD << endl;
	return 0;
}