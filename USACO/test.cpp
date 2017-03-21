/*
	ID: ovishek1
	LANG: C++11
	TASK: barn1
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	// freopen("barn1.in", "r", stdin);
	// freopen("barn1.out", "w", stdout);
	int M, S, C;
	cin >> M >> S >> C;
	vector<int> vt;
	for(int i = 0; i < C; i++){
		int a;
		cin >> a;
		vt.push_back(a);
	}
	sort(vt.begin(), vt.end());
	int prev = vt[0], st = vt[0];
	vector<pair<int, int> > stall;
	for(int i = 0; i<C; i++)
	{	
		if(prev == vt[i]) continue;
		if(prev == vt[i] - 1) prev ++;
		else{
			stall.push_back(make_pair(st, prev));
			prev = st = vt[i];
		}
	}
	stall.push_back(make_pair(st, prev));
	//for( pair<int, int> x : stall) cout << x.first << ' ' << x.second << endl;

	while(stall.size()>M)
	{
		//cout << stall.size()  << "*" << endl;
		vector< pair<int, int> > temp;
		int sz = stall.size();
		int optimali = 0, mini = (1<<30); for(int i = 1; i<sz ; i++)
		{
			if(mini > stall[i].first - stall[i-1].second)
			{
				mini = stall[i].first - stall[i-1].second;
				optimali = i;
			}
		}
		temp.push_back(stall[0]);
		for(int i = 1; i<sz; i++)
		{
			if(i==optimali) temp.back().second = stall[i].second;
			else temp.push_back(stall[i]);
		}
		stall = temp;
		//cout << stall.size() << endl;
	}
	int ans = 0;
	//for( pair<int, int> x : stall) cout << x.first << ' ' << x.second << endl;
	for(pair<int, int> x : stall){
		ans += x.second - x.first + 1;
	}
	cout << ans << endl;
	return 0;
}