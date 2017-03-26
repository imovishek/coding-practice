/*
	ID: ovishek1
	LANG: C++11
	TASK: milk3
*/

#include<bits/stdc++.h>
using namespace std;
int dp[22][22][22];
int a, b, c;
int ara[50];
int rec(int x, int y, int z)
{
	if(x==0) ara[ z ] = 1;
	int &ret = dp[x][y][z];
	if(ret!=-1) return ret;
	ret = 0;
	int cap_a = a - x, cap_b = b - y, cap_c = c - z;
	rec(x - min(cap_b, x), y + min(cap_b, x), z);
	rec(x - min(cap_c, x), y, z + min(cap_c, x));
	rec(x + min(cap_a, y), y - min(cap_a, y), z);
	rec(x, y - min(cap_c, y), z + min(cap_c, y));
	rec(x + min(cap_a, z), y, z - min(cap_a, z));
	rec(x, y + min(cap_b, z), z- min(cap_b, z));
	return ret;
}
int main()
{
	freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);
	memset(dp, -1, sizeof dp);
	cin >> a >> b >> c;
	rec(0, 0, c);
	int f = 0;
	for(int i = 0; i<50; i++) {
		if(ara[i]){
			if(f) cout << " ";
			f = 1;
			cout << i ;
		}
	}
	cout << endl;
	return 0;
}