#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int n;
	int t;
	cin >> t;
	while(t--)
	{
		int budget;
		cin >> n >> budget;
		map<string, vector< pair<int, int> > > mp;
		string type, name;
		int price, quality, r = 0;
		for(int i = 0; i<n ; i++){
			cin >> type >> name >> price >> quality ;
			mp[type].push_back(make_pair(price, quality));
			r = max(r, quality);
		}
		int l = 0, ans = 0;
		while(l<=r){
			int f = 0, mid = l + (r-l)/2, sum = 0;
			for(auto it = mp.begin(); it!=mp.end(); it++)
			{
				vector< pair<int, int> > &vt = it->second;
				int sz = vt.size();
				int mini = INT_MAX;
				for(int i = 0; i<sz; i++)
					if(vt[i].second>=mid){
						mini = min(mini, vt[i].first);
				}
				if(mini==INT_MAX) {f = 1; break;}
				sum += mini;
			}
			if(f || sum>budget) r = mid - 1;
			else{
				l = mid + 1;
				ans = mid;
			}
		}
		cout << ans << endl;
	}
	return 0;
}