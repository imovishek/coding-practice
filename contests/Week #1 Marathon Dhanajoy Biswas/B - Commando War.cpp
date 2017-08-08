#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
bool comp(pii a, pii b)
{
	return (a.second - b.first) > (b.second - a.first);
}

int main()
{
	ios::sync_with_stdio(false);
	int n, tst = 1;
	while(cin >> n && n)
	{
		vector< pair<int, int> > ara(n);
		for(int i = 0; i<n; i++)
			cin >> ara[i].second >> ara[i].first;
		sort(ara.rbegin(), ara.rend(), comp);
		// for(int i = 0; i<n ; i++)
		// 	cout << ara[i].first << '*' << ara[i].second << endl;
		int ans = 0;
		for(int i = n-1; i>-1 ; i--)
		{
			ans += ara[i].second;
			for(int j = i+1; j<n; j++)
				if(ara[j].first==0) break;
				else ara[j].first = max(ara[j].first - ara[i].second, 0);
		}
		int maxi = 0;
		for(int j = n-1; j>=0; j--)
			maxi = max(maxi, ara[j].first);
		cout << "Case " << tst++ << ": " << ans + maxi << endl; 

	}
	return 0;
}