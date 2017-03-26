/*
	ID: ovishek1
	LANG: C++11
	TASK: ariprog
*/

#include<bits/stdc++.h>
using namespace std;
int ara[1000007];

bool comp(pair<int, int> a, pair<int, int> b)
{
	if(a.second==b.second) return a.first<b.first;
	return a.second<b.second;
}

int main()
{
	freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i<=m; i++)
		for(int j = 0; j<=m; j++)
			ara[i*i + j*j] = 1;
	vector<int> vt;
	for(int i = 0; i<= m*m*2; i++)
		if(ara[i]) vt.push_back(i);
	int ni = vt.size();
	// for(int i = 0; i<ni; i++) cout << vt[i] << " ";
	// cout << endl;
	vector< pair<int, int> > ans;
	for(int i = 0; i<ni; i++)
		for(int j = i + 1; j<ni; j++)
		{
			int d = vt[j] - vt[i];
			int cnt = 1;
			while(ara[vt[i] + cnt*d]==1) cnt++;
			d = vt[j] - vt[i];
			// if(vt[i]==1) cout << vt[i] << " " << vt[j] << " " << cnt << " hi" << endl;
			if(cnt>=n)
				ans.push_back(make_pair(vt[i], d));
		}
	// cout << ans.size() << endl;
	if(ans.size()==0) cout << "NONE" << endl;
	sort(ans.begin(), ans.end(), comp);
	for(int i = 0; i<ans.size(); i++)
		cout << ans[i].first << " " << ans[i].second << endl;

	return 0;
}