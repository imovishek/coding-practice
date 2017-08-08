#include<bits/stdc++.h>
using namespace std;
#define inf 1000000007
int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	int ara[n], longest[n], maxi = 0;
	longest[0] = inf;
	for(int i = 0; i<n ; i++)
	{
		cin >> ara[i];
		int x = lower_bound(longest, longest+maxi+1, ara[i]) - longest;
		maxi = max(x, maxi);
		// cout << x << "*" << endl;
		longest[x] = ara[i];
	}

	cout << maxi + 1 << endl;

	return 0;
}