#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define inf 2000000007


int main()
{
	ios :: sync_with_stdio(false);
	int n, t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		int ara[n], maxi[n], mini[n];
		for(int i = 0; i<n; i++)
		{
			cin >> ara[i];
			if(i) maxi[i] = max(maxi[i-1], ara[i]);
			else maxi[i] = ara[i];
		}
		mini[n-1] = ara[n-1];
		for(int i = n-2; i>=0; i--)
			mini[i] = min(mini[i+1], ara[i]);
		int ans = -inf;
		for(int i = 0; i<n-1; i++)
			ans = max(ans, maxi[i] - mini[i+1]);
		cout << ans << endl;
	}

	return 0;
}