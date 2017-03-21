/*
	ID: ovishek1
	LANG: C++11
	TASK: wormhole
*/
#include<bits/stdc++.h>
using namespace std;
int n;
int flag[20];
pair<int, int> ara[20];
vector< pair<int, int> > vt;
bool comp(pair<int, int> a, pair<int, int> b)
{
	if(a.second!=b.second)
		return a.second < b.second;
	return a.first < b.first;
}
void print(const vector<pair<int, int> > &vt)
{
	// for(int i = 0; i<vt.size(); i++)
	// 			cout << vt[i].first << " * " << vt[i].second << endl;
	// 	cout << endl;
}
int ans = 0;
void rec()
{
	if(vt.size()==n) {
		
		vector<pair<int, int> > tmp = vt;
		// for(int i = 0; i<n; i++)
		// 		cout << tmp[i].first << " * " << tmp[i].second << endl;
		// 	cout << endl;
		map< pair<int, int>, pair<int, int> > mp, next;
		for(int i = 0; i<n; i+=2)
		{
			mp[ vt[i] ] = vt[i+1];
			mp[ vt[i+1] ] = vt[i];
		}
		sort(vt.begin(), vt.end(), comp);
		for(int i = 1; i<n; i++)
			if(vt[i].second==vt[i-1].second) next[vt[i-1]] = vt[i];
		int f = 0;
		for(int i = 0; i<n; i++){
			int cnt = 0;
			pair<int, int> now = vt[i];
			while(cnt<=n)
			{
				now = mp[now];
				// if(ans==2) cout << now.first << " %% " << now.second << endl;
				if(next.find(now)==next.end()) break;
				now = next[now];
				// if(ans==2) cout << now.first << " %% " << now.second << endl;
				cnt++;
			}
			if(cnt>n) {f = 1; break;}
		}
		if(f) {
			// for(int i = 0; i<n; i++)
			// 	cout << tmp[i].first << " * " << tmp[i].second << endl;
			// cout << endl;
			ans++;
		}
		vt = tmp;
		return;
	}
	for(int i = 0; i<n; i++)
	{
		if(flag[i]==0){
			// cout << "pushed " << ara[i].first << " " << ara[i].second << endl;
			for(int j = i+1; j<n; j++)
			{
				if(flag[j]==1) continue;
			vt.push_back(ara[i]);
				vt.push_back(ara[j]);
				print(vt);
				// cout << "pushed " << ara[j].first << " " << ara[j].second << endl;
				flag[i] = flag[j] = 1;
				rec();
				flag[i] = flag[j] = 0;
				vt.pop_back();
				// cout << "vt poped *" << endl;
			vt.pop_back();
				print(vt);
			}
				// cout << "vt poped ****" << endl;
			break;
		}
	}
}

int main()
{
	ios :: sync_with_stdio(false);
	freopen("wormhole.in", "r", stdin);
    freopen("wormhole.out", "w", stdout);
	cin >> n;
	for(int i = 0; i<n ; i++)
		cin >> ara[i].first >> ara[i].second;
	rec();
	cout << ans << endl;
	return 0;
}

/*

6
1 2
1 1
2 2
3 1
3 3
2 1

*/