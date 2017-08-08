#include<bits/stdc++.h>
using namespace std;
string dp[101][101];
string a, b;
int n, m;
string rec(int x, int y)
{
	if(x==n || y==m) return "";
	string &ret = dp[x][y];
	if(ret != "*") return ret;
	if(a[x]==b[y]) return ret = a[x] + rec(x+1, y+1);
	else{
		string ret2 = rec(x, y+1);
		string ret3 = rec(x+1, y);
		int len2 = ret2.length(), len3 = ret3.length();
		if(len2 > len3) return ret = ret2;
		else if(len2 < len3) return ret = ret3;
		else return ret = min(ret2, ret3);
	}
}

int main()
{
	ios :: sync_with_stdio(false);
	int t, tst = 1;
	cin >> t;
	while(t--)	
	{
		cin >> a >> b;
		n = a.length(), m = b.length();
		for(int i = 0; i<n; i++)
			for(int j = 0; j<m; j++)
				dp[i][j] = "*";
		cout << "Case " << tst++ << ": " ; 
		string ans = rec(0, 0);
		if(ans=="") ans = ":(";
		cout << ans << endl;
	}
}