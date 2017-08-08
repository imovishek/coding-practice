#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define inf 1000000007


int main()
{
	ios :: sync_with_stdio(false);
	int n, s;
	while(cin >> n >> s)
	{
		int ara[n];
		for(int i = 0; i<n; i++)
			cin >> ara[i];
		int x = 0;
		int sum = 0, ans = inf;
		for(int i = 0; i<n; i++)
		{
			if(sum + ara[i]<s) sum+=ara[i];
			else{
				sum += ara[i];
				while(x < n && sum>=s)
				{
					ans = min(ans, i - x + 1);
					sum -= ara[x++];
				}
			}
		}
		if(ans==inf) ans = 0;
		cout << ans << endl;
	}
	return 0;
}