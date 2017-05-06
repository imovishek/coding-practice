/*
ID: ovishek1
LANG: C++11
PROB: prefix
*/


#include<bits/stdc++.h>
using namespace std;

string st[202], text = "";
int dp[300005];

int n, m;
int rec(int pos)
{
	cout << pos << endl;
	if(pos==n) return 0;
	int &ret = dp[pos];
	if(ret!=-1) return ret;
	ret = 0;
	for(int i = 0; i<m; i++){
		if(st[i].length()>(n-pos)) continue;
		if(text.substr(pos, st[i].length())==st[i]){
			ret = max(ret, (int)st[i].length() + rec(pos+(int)st[i].length())); 
		}
	}
	return ret;
}

int main()
{
	freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);
 	// memset(dp, -1, sizeof dp);
 	string a;
 	int pos = 0;
 	while(cin >> a) {
 		if(a==".") break;
 		st[pos++] = a;
 	}
 	m = pos;
 	while(cin >> a)
 		text = text + a;
 	n = text.length();

 	for(int i = n-1; i>=0; i--)
 	{
 		for(int j = 0; j<m; j++)
 		{
 			if(n - i >= st[j].length() && text.substr(i, st[j].length())==st[j])
 				dp[i] = max(dp[i], (int)st[j].length() + dp[i + st[j].length()]);
 		}
 	}
 	cout << dp[0] << endl;
	return 0;
}