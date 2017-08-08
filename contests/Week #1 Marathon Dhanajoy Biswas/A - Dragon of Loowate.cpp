#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	while(cin >> n >> m)
	{
		if(n==m && n==0) return 0;
		priority_queue<int, vector<int>, greater<int> > goosepq, knightpq;
		for(int i = 0; i<n ; i++)
		{
			int radius;
			cin >> radius;
			goosepq.push(radius);
		}
		for(int i = 0; i<m ; i++)
		{
			int height;
			cin >> height;
			knightpq.push(height);
		}
		int ans = 0;
		while(!knightpq.empty() && !goosepq.empty())
		{
			if(goosepq.top()<=knightpq.top()){
				goosepq.pop();
				ans += knightpq.top();
			}
			knightpq.pop();
		}
		if(goosepq.empty()) cout << ans << endl;
		else cout << "Loowater is doomed!" << endl; 

	}	
	return 0;
}