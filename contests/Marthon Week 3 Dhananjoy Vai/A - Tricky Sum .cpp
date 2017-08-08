#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long cum[32];
	cum[0] = 1;
	for(int i = 1; i<32; i++) cum[i] = cum[i-1] + (1<<i);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int x = 0;
		while((1<<x)<=n) x++;
		x--;
		// cout << (1 << x) << endl;
		long long tn = n;
		long long ans = (tn*(tn+1))/2 - 2 * cum[x];
		cout << ans << endl;
	}
	return 0;
}