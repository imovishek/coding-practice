/*
	ID: ovishek1
	LANG: C++11
	TASK: numtr
*/

#include<bits/stdc++.h>
using namespace std;
int ara[1007][1007];
int main()
{
	freopen("numtr.in", "r", stdin);
    freopen("numtr.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i<=n; i++)
	{
		for(int j = 0; j<i; j++)
			cin >> ara[i-1][j];
	}
	for(int i = n-2; i>=0; i--)
	{
		for(int j = 0; j<=i; j++)
			ara[i][j] += max(ara[i+1][j], ara[i+1][j+1]);
	}
	cout << ara[0][0] << endl;
	return 0;
}