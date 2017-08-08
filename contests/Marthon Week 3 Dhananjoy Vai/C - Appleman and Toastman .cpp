#include<bits/stdc++.h>
using namespace std;
typedef long long int lint; 
int main()
{
	int n;
	cin >> n;
	lint ara[n];
	for(int i = 0; i<n; i++)
	{
		cin >> ara[i];
	}
	sort(ara, ara+n);
	reverse(ara, ara+n);
	lint cum[n];
	cum[0] = ara[0];
	for(int i = 1; i<n; i++) cum[i] = cum[i-1] + ara[i];
	long long int ans = 0;
	for(int i = n-1; i>0; i--)
	{
		ans += ara[i] + cum[i-1];
	}
	cout << ans + cum[n-1] << endl;
	return 0;
}